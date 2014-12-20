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



#ifndef ALARMSRESOURCE_H_
#define ALARMSRESOURCE_H_

#include "CMClientResource.h"
#include "xsd/Elements.h"

#include "IAlarmsResourceResponseListener.h"

/**
*  @addtogroup Client
*  @{
*/


/**
 * @class   AlarmsResource
 * @brief   AlarmsResource class implements OC::Cm::Client::Resource::Resource and OC::Cm::Client::Resource::IResourceResponseListener @n
 *          This class provides base listener methods to receive response of Control Manager requests.<br><br>
 *
 *          Application developers must have the knowledge of input and output data format of Control Manager requests.@n
 *          Then only they can properly type cast the response data.<br><br>
 *
 *          Application needs to type cast the response data to corresponding data class generated by Control Manager-SDK.@n
 *          Control Manager-SDK also generates resource specific controllers and status listeners. It is advisable to use@n
 *          these resource specific controllers and interfaces to avoid type casting.<br><br>
 */
class AlarmsResource : public OC::Cm::Client::Resource::Resource
{

    public:

        /**
         * Constructor of AlarmsResource class.
         *
         * @param[in]   context         Context of Control Manager framework
         * @param[in]   protocol        Specify type of protocol to be used (http, https, scs, shs)
         * @param[in]   deviceAddress   Address of peer device. String format can be different for different protocol. (IP address:port [http,https,shs] or PeerID [scs])
         */
        AlarmsResource(OC::Cm::IContext *context, std::string &protocol, std::string &deviceAddress);

        /**
         * Default virtual destructor of AlarmsResource class.
         */
        virtual ~AlarmsResource();

        /**
         * This method will initialize p_respListener variable.<br>
         * Please make sure that user must register their own listener class through this method before sending a request.
         * Otherwise, all the received response will be ignored.
         *
         * @param[in]   AlarmsResourceResponseListener  Object that implements IAlarmsResourceResponseListener interface
         */

        void addResponseListener (IAlarmsResourceResponseListener &respListener) ;

        IAlarmsResourceResponseListener *getResponseListener ();

        bool getAlarms( int &requestId );

        void buildPath(std::string deviceId);

    private:
        class AlarmsResourceListenerInternal : public OC::Cm::Client::Resource::IResourceResponseListener
        {
            public:

                AlarmsResource *resource;

                AlarmsResourceListenerInternal(AlarmsResource *res)
                {
                    resource = res;
                }

                ~AlarmsResourceListenerInternal()
                {
                }

                void
                OnGetResponseReceived( int clientSessionId, int status, OC::Cm::Connector::HeadersList &headers,
                                       OC::Cm::Serialization::ISerializable *response )
                {
                    IAlarmsResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        if (response != NULL)
                        {
                            std::string elementName = response->getElementName() ;

                            if ( 0 == elementName.compare(EN_ALARMS))
                            {
                                ::Alarms *respData = (::Alarms *)response ;
                                p_respListener->ongetAlarms(clientSessionId, status,  respData) ;
                            }
                            else
                            {
                                p_respListener->ongetAlarms(clientSessionId, 400,  NULL) ;
                            }
                        }
                        else
                        {
                            p_respListener->ongetAlarms(clientSessionId, status,  NULL) ;
                        }
                    }
                }

                void
                OnPutResponseReceived(int clientSessionId,  int status, OC::Cm::Connector::HeadersList &headers,
                                      OC::Cm::Serialization::ISerializable *response)
                {
                }
                void
                OnPostResponseReceived(int clientSessionId, int status, OC::Cm::Connector::HeadersList &headers,
                                       OC::Cm::Serialization::ISerializable *response)
                {
                }

                void
                onDeleteResponseReceived(int clientSessionId, int status, OC::Cm::Connector::HeadersList &headers,
                                         OC::Cm::Serialization::ISerializable *response)
                {
                }

                void
                onSubscribeResponseReceived(int clientSessionId, int status, std::string &subscriptionUri )
                {
                    IAlarmsResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        p_respListener->onSubscribeResponseReceived(clientSessionId, status, subscriptionUri) ;
                    }
                }

                void
                onUnSubscribeResponseReceived(int clientSessionId, int status )
                {
                    IAlarmsResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        p_respListener->onUnSubscribeResponseReceived(clientSessionId, status) ;
                    }
                }

                void
                onErrorReceived( int requestId, int status, OC::Cm::CMError error,
                                 OC::Cm::Serialization::ISerializable *errorMessage)
                {
                    IAlarmsResourceResponseListener *p_respListener = resource->getResponseListener();
                    if ( p_respListener != NULL )
                    {
                        p_respListener->onError( requestId, status, error,
                                                 (OC::Cm::Serialization::Xsd::CMErrorMessage *)errorMessage ) ;
                    }
                }

                void
                onRequestComplete(int requestId, std::string requestPayload,  std::string responsePayload)
                {
                }
        };

        /**
         * Variable that contains IAlarmsResourceResponseListener object.
         */
        IAlarmsResourceResponseListener *p_respListener ;

        OC::Cm::Client::Resource::IResourceResponseListener *p_internalResponseListener ;

};
/** @} */
#endif /* ALARMSRESOURCE_H_ */
