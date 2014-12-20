//******************************************************************
//
// Copyright 2014 Samsung Electronics All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=



#include "ClientSessionData.h"

namespace OC
{
    namespace Cm
    {
        namespace Connector
        {
            namespace Client
            {

                ClientSessionData::ClientSessionData()
                {
                    m_pRequestPayload = NULL ;
                    m_pResponsePayload = NULL ;
                    m_pResponseHandler = NULL ;
                    m_isControlRequest = true;
                    m_serverType = 0;
                }

                ClientSessionData::~ClientSessionData()
                {
                    if (NULL != m_pRequestPayload)
                    {
                        delete m_pRequestPayload ;
                    }

                    if (NULL != m_pResponsePayload)
                    {
                        delete m_pResponsePayload ;
                    }
                }

                OC::Cm::Client::Resource::IResourceResponseListener *
                ClientSessionData::getResponseHandler() const
                {
                    return m_pResponseHandler ;
                }

                void
                ClientSessionData::setResponseHandler(OC::Cm::Client::Resource::IResourceResponseListener
                                                      *responseHandler)
                {
                    m_pResponseHandler = responseHandler ;
                }


            } /* namespace Client */
        }
    } /* namespace Cm */
} /* namespace OC */
