/******************************************************************
 *
 * Copyright 2014 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/

#include <map>
#include <string>

#include "base/values.h"
#include "base_resource/base_identified_object.h"
#include "base_resource/process_attribute.h"
#include "data_types/primitive_data_type.h"
#include "data_types/simple_data_type.h"
#include "data_types/simple_array_data_type.h"
#include "http_header/http_request_header.h"
#include "http_header/http_response_header.h"
#include "http_start_line/http_request_line.h"
#include "http_start_line/http_status_code_defined.h"
#include "base/logging.h"
#include "wrapped_component/common_wrapper_functions.h"

namespace webservice
{

#undef SAFE_DESTROY
#define SAFE_DESTROY(x)  if (x) { delete(x); x = NULL; }

    BaseIdentifiedObject::BaseIdentifiedObject(std::string id, std::string object_name)
    {
        id_ = new String50(id);
        id_->SetProperty(1, 1, false);
        elements_["id"] = id_;

        description_ = new String50;
        description_->SetProperty(0, 1, true);
        description_->SetFunctionPtr(&CommonWrapperFunctions::GetIdentifiedObjectDescription,
                                     &CommonWrapperFunctions::SetIdentifiedObjectDescription, object_name);
        elements_["description"] = description_;

        p_attr = new ProcessAttribute;
        http_ = NULL;
        pGetFunc_ = NULL;
        pPutFunc_ = NULL;
        pPostFunc_ = NULL;
        pDeleteFunc_ = NULL;
    }

    BaseIdentifiedObject::~BaseIdentifiedObject()
    {
        SAFE_DESTROY(this->id_)
        SAFE_DESTROY(this->description_)
        SAFE_DESTROY(p_attr)
        SAFE_DESTROY(http_)
    }

    HTTPResponseType BaseIdentifiedObject::ProcessHTTPRequestMethod(const HTTPRequestLine &request_line,
            const HTTPRequestHeader &request_header, base::Value  *request_body,
            HTTPResponseHeader &response_header, base::Value *response_body,
            std::map<std::string, std::string> &id_deps)
    {
        HTTPResponseType response_error_code = RT_405_METHOD_NOT_ALLOWED;
        int http_method = request_line.GetHTTPMethod();
        HttpRequest req(const_cast<HTTPRequestLine *> (&request_line),
                        const_cast<HTTPRequestHeader *> (&request_header), request_body);
        HttpResponse res(const_cast<HTTPResponseHeader *> (&response_header), response_body);
        http_ = new HTTPMessage(req, res);
        if (web_util::HTTP_METHOD_POST != http_method)
        {
            // Validate ID
            response_error_code = ValidateObjectID();
            if (RT_200_OK != response_error_code)
            {
                return response_error_code;
            }
            // Save current IDs
            SaveCurrentIDWithName(id_deps);
        }

        switch (http_method)
        {
            case web_util::HTTP_METHOD_GET:
                {
                    response_error_code = Get(request_line, request_header, response_header, response_body, id_deps);
                } break;
            case web_util::HTTP_METHOD_PUT:
                {
                    response_error_code = Put(request_line, request_header, request_body, response_header,
                                              response_body, id_deps);
                } break;
            case web_util::HTTP_METHOD_POST:
                {
                    response_error_code = Post(request_line, request_header, request_body, response_header,
                                               response_body, id_deps);
                } break;
            case web_util::HTTP_METHOD_DELETE:
                {
                    response_error_code = Delete(request_line, request_header, response_header, response_body, id_deps);
                } break;
            default:
                response_error_code = RT_405_METHOD_NOT_ALLOWED;
                break;
        }
        return response_error_code;
    }

    HTTPResponseType BaseIdentifiedObject::Get(const HTTPRequestLine &request_line,
            const HTTPRequestHeader &request_header,
            HTTPResponseHeader &response_header, base::Value *response_body,
            std::map<std::string, std::string> &id_deps)
    {
        HTTPResponseType en_response_type = RT_UNKNOWN;
        HTTPResponseType en_error_response_type = RT_200_OK;
        base::DictionaryValue *response_dict = static_cast<base::DictionaryValue *>(response_body);
        std::map<std::string, BaseAttributeType *>::iterator it;

        base::DictionaryValue input_dictionary_value;
        SetIDList(id_deps, &input_dictionary_value, true);
        WrapperInput input = WrapperInput(http_, &input_dictionary_value);

        base::DictionaryValue function_response;
        function_response.Clear();
        if (NULL != this->pGetFunc_)
        {
            HTTPResponseType ret = (*(this->pGetFunc_))(reinterpret_cast<void *>(&input),
                                   reinterpret_cast<void *>(&function_response));
            DLOG(INFO) << "Return value of this wrapper function is " << ret;
        }

        DLOG(INFO) << "BaseIdentifiedObject Get Method (element size : " << elements_.size() << ")";
        for (it = elements_.begin(); it != elements_.end(); it++)
        {
            std::string name = it->first;
            BaseAttributeType *attr = it->second;
            if (function_response.HasKey(name)) en_response_type = p_attr->GetAttributeWithFunctionResponse(
                            name, attr, &function_response, response_dict);
            else en_response_type = p_attr->GetAttribute(name, attr, &input, response_dict);
            if (RT_200_START > en_response_type
                || RT_300_START <= en_response_type) en_error_response_type = en_response_type;
        }
        DLOG(INFO) << "BaseIdentifiedObject::Get return code  " << en_error_response_type;
        return en_error_response_type;
    }

    HTTPResponseType BaseIdentifiedObject::Put(const HTTPRequestLine &request_line,
            const HTTPRequestHeader &request_header, base::Value *request_body,
            HTTPResponseHeader &response_header, base::Value *response_body,
            std::map<std::string, std::string> &id_deps)
    {
        HTTPResponseType en_response_type = RT_UNKNOWN;
        HTTPResponseType en_error_response_type = RT_204_NO_CONTENT;
        if (NULL == request_body) return en_error_response_type;
        base::DictionaryValue *request_body_dict = static_cast<base::DictionaryValue *>(request_body);
        base::DictionaryValue input_dictionary_value;
        SetIDList(id_deps, &input_dictionary_value, true);
        WrapperInput input = WrapperInput(http_, &input_dictionary_value);
        DLOG(INFO) << "BaseIdentifiedObject Put Method (element size : " << elements_.size() << ")";
        // Pre Check : unnecessary, data type, restriction
        for (base::DictionaryValue::key_iterator dict_key_it = request_body_dict->begin_keys();
             dict_key_it != request_body_dict->end_keys(); ++dict_key_it)
        {
            std::string input_key = *dict_key_it;
            en_response_type = p_attr->PutPreChecking(input_key, this->elements_, request_body_dict);
            if (RT_200_START > en_response_type || RT_300_START <= en_response_type) return en_response_type;
        }
        // Processing attributes
        base::DictionaryValue function_response;
        function_response.Clear();
        if (NULL != this->pPutFunc_)
        {
            input.dictionary->MergeDictionary(request_body_dict);
            en_response_type = (*(this->pPutFunc_))(reinterpret_cast<void *>(&input),
                                                    reinterpret_cast<void *>(&function_response));
            DLOG(INFO) << "Return value of this wrapper function is " << en_response_type;
            if (RT_200_START > en_response_type || RT_300_START <= en_response_type) return en_response_type;
        }
        std::map<std::string, BaseAttributeType *>::iterator it;
        for (it = elements_.begin(); it != elements_.end(); it++)
        {
            std::string name = it->first;
            BaseAttributeType *attr = it->second;
            if ("id" == name) continue;
            if (function_response.HasKey(name))
            {
                en_response_type = p_attr->PutAttributeWithFunctionResponse(name, attr, &function_response);
            }
            else
            {
                en_response_type = p_attr->PutAttribute(name, attr, &input, request_body_dict);
            }
            if (RT_200_START > en_response_type
                || RT_300_START <= en_response_type) en_error_response_type = en_response_type;
        }
        return en_error_response_type;
    }

    HTTPResponseType BaseIdentifiedObject::Post(const HTTPRequestLine &request_line,
            const HTTPRequestHeader &request_header, base::Value *request_body,
            HTTPResponseHeader &response_header, base::Value *response_body,
            std::map<std::string, std::string> &id_deps)
    {
        HTTPResponseType en_response_type = RT_201_CREATE;
        if (NULL == request_body) return en_response_type;
        base::DictionaryValue *request_body_dict = static_cast<base::DictionaryValue *>(request_body);
        base::DictionaryValue input_dictionary_value;
        WrapperInput input = WrapperInput(http_, &input_dictionary_value);

        // Pre Check : unnecessary, data type, restriction
        for (base::DictionaryValue::key_iterator dict_key_it = request_body_dict->begin_keys();
             dict_key_it != request_body_dict->end_keys(); ++dict_key_it)
        {
            std::string input_key = *dict_key_it;
            en_response_type = p_attr->PostPreChecking(input_key, this->elements_, request_body_dict);
            DLOG(ERROR) << "PostPreChecking  :  " << input_key << " : " << en_response_type;
            if (RT_200_START > en_response_type || RT_300_START <= en_response_type)
            {
                return en_response_type;
            }
        }

        std::string created_id = "";
        if (NULL != this->pPostFunc_)
        {
            input.dictionary = request_body_dict->DeepCopyWithoutEmptyChildren();
            SetIDList(id_deps, input.dictionary, false);
            en_response_type = (*(this->pPostFunc_))(reinterpret_cast<void *>(&input),
                               reinterpret_cast<void *>(response_body), &created_id);
        }
        else
        {
            SetIDList(id_deps, &input_dictionary_value, true);
            // Processing attributes
            std::map<std::string, BaseAttributeType *>::iterator it;
            for (it = elements_.begin(); it != elements_.end(); it++)
            {
                std::string name = it->first;
                BaseAttributeType *attr = it->second;
                en_response_type = p_attr->PostAttribute(name, attr, &input, request_body_dict);
                if (RT_200_START > en_response_type || RT_300_START <= en_response_type)
                {
                    return en_response_type;
                }
            }
            en_response_type = CreateObjectID(reinterpret_cast<void *>(&input_dictionary_value), &created_id);
        }
        if ("" != created_id) id_deps["created_new_id"] = created_id;
        DLOG(INFO) << "id : " << created_id << ", ret : " << en_response_type;
        return en_response_type;
    }

    HTTPResponseType BaseIdentifiedObject::Delete(const HTTPRequestLine &request_line,
            const HTTPRequestHeader &request_header,
            HTTPResponseHeader &response_header, base::Value *response_body,
            std::map<std::string, std::string> &id_deps)
    {
        HTTPResponseType en_response_type = RT_204_NO_CONTENT;
        base::DictionaryValue input_dictionary_value;
        SetIDList(id_deps, &input_dictionary_value, true);

        std::string *default_value = reinterpret_cast<std::string *>(this->id_->GetDefault());
        if (NULL != default_value)
        {
            en_response_type = DeleteObjectID(reinterpret_cast<void *>(&input_dictionary_value),
                                              *default_value);
        }
        return en_response_type;
    }

    void BaseIdentifiedObject::SetIDList(std::map<std::string, std::string> &id_deps,
                                         base::DictionaryValue *dict_value, bool is_clear)
    {
        std::map<std::string, std::string>::iterator it;
        if (is_clear) dict_value->Clear();
        for (it = id_deps.begin(); it != id_deps.end(); it++)
        {
            DLOG(INFO) << it->first << " " << it->second;
            dict_value->SetWithoutPathExpansion(it->first, base::Value::CreateStringValue(it->second));
        }
    }

}
