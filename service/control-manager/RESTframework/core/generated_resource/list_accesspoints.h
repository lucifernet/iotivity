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

#ifndef WEBSERVICE_SRC_NEW_RESOURCE_HANDLER_GENERATED_RESOURCE_LIST_ACCESSPOINTS_H_
#define WEBSERVICE_SRC_NEW_RESOURCE_HANDLER_GENERATED_RESOURCE_LIST_ACCESSPOINTS_H_

#include "base_resource/base_list.h"
#include "data_types/simple_data_type.h"
#include "data_types/simple_array_data_type.h"

namespace webservice
{

    class ListAccessPoints : public BaseList
    {
        public:
            ListAccessPoints();
            virtual ~ListAccessPoints();
            /**
              * Register function to create this class.
              * @param[in] string
              * @param[in] BaseList*
              * @return static RegisterList
              */
            static RegisterList regList;
            /**
              * Create this class.
              * @return BaseList*
              */
            static BaseList *Create();
    };

}

#endif /* WEBSERVICE_SRC_NEW_RESOURCE_HANDLER_GENERATED_RESOURCE_LIST_ACCESSPOINTS_H_ */