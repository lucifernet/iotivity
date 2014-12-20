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



#ifndef DEVICESRESOURCE_H_
#define DEVICESRESOURCE_H_

#include "CMClientResource.h"
#include "xsd/Elements.h"

#include "IDevicesResourceResponseListener.h"


/**
*  @addtogroup Client
*  @{
*/

/**
 * @class   DevicesResource
 * @brief   DevicesResource class implements OC::Cm::Client::Resource::Resource and OC::Cm::Client::Resource::IResourceResponseListener @n
 *          This class provides base listener methods to receive response of Control Manager requests.<br><br>
 *
 *          Application developers must have the knowledge of input and output data format of Control Manager requests.@n
 *          Then only they can properly type cast the response data.<br><br>
 *
 *          Application needs to type cast the response data to corresponding data class generated by Control Manager-SDK.@n
 *          Control Manager-SDK also generates resource specific controllers and status listeners. It is advisable to use@n
 *          these resource specific controllers and interfaces to avoid type casting.<br><br>
 */
class DevicesResource : public OC::Cm::Client::Resource::Resource
{

    public:

        /**
         * Constructor of DevicesResource class.
         *
         * @param[in]   context         Context of Control Manager framework
         * @param[in]   protocol        Specify type of protocol to be used (http, https, scs, shs)
         * @param[in]   deviceAddress   Address of peer device. String format can be different for different protocol. (IP address:port [http,https,shs] or PeerID [scs])
         */
        DevicesResource(OC::Cm::IContext *context, std::string &protocol, std::string &deviceAddress);

        /**
         * Default virtual destructor of DevicesResource class.
         */
        virtual ~DevicesResource();

        /**
         * This method will initialize p_respListener variable.<br>
         * Please make sure that user must register their own listener class through this method before sending a request.
         * Otherwise, all the received response will be ignored.
         *
         * @param[in]   DevicesResourceResponseListener Object that implements IDevicesResourceResponseListener interface
         */

        void addResponseListener (IDevicesResourceResponseListener &respListener) ;

        IDevicesResourceResponseListener *getResponseListener ();

        bool getDevices( int &requestId );


        bool postDevices( int &requestId , ::Device &reqData);


        void buildPath( );

    private:
        class DevicesResourceListenerInternal : public OC::Cm::Client::Resource::IResourceResponseListener
        {
            public:

                DevicesResource *resource;

                DevicesResourceListenerInternal(DevicesResource *res)
                {
                    resource = res;
                }

                ~DevicesResourceListenerInternal()
                {
                }

                void
                OnGetResponseReceived( int clientSessionId, int status, OC::Cm::Connector::HeadersList &headers,
                                       OC::Cm::Serialization::ISerializable *response )
                {
                    IDevicesResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        if (response != NULL)
                        {
                            std::string elementName = response->getElementName() ;

                            if ( 0 == elementName.compare(EN_DEVICES))
                            {
                                ::Devices *respData = (::Devices *)response ;
                                p_respListener->ongetDevices(clientSessionId, status,  respData) ;
                            }
                            else
                            {
                                p_respListener->ongetDevices(clientSessionId, 400,  NULL) ;
                            }
                        }
                        else
                        {
                            p_respListener->ongetDevices(clientSessionId, status,  NULL) ;
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
                    IDevicesResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        std::string location;
                        headers.getHeader("location", location);
                        p_respListener->onpostDevices(clientSessionId, status, location) ;
                    }
                }

                void
                onDeleteResponseReceived(int clientSessionId, int status, OC::Cm::Connector::HeadersList &headers,
                                         OC::Cm::Serialization::ISerializable *response)
                {
                }

                void
                onSubscribeResponseReceived(int clientSessionId, int status, std::string &subscriptionUri )
                {
                    IDevicesResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        p_respListener->onSubscribeResponseReceived(clientSessionId, status, subscriptionUri) ;
                    }
                }

                void
                onUnSubscribeResponseReceived(int clientSessionId, int status )
                {
                    IDevicesResourceResponseListener *p_respListener = resource->getResponseListener();
                    if (p_respListener != NULL)
                    {
                        p_respListener->onUnSubscribeResponseReceived(clientSessionId, status) ;
                    }
                }

                void
                onErrorReceived( int requestId, int status, OC::Cm::CMError error,
                                 OC::Cm::Serialization::ISerializable *errorMessage)
                {
                    IDevicesResourceResponseListener *p_respListener = resource->getResponseListener();
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
         * Variable that contains IDevicesResourceResponseListener object.
         */
        IDevicesResourceResponseListener *p_respListener ;

        OC::Cm::Client::Resource::IResourceResponseListener *p_internalResponseListener ;

};
/** @} */
#endif /* DEVICESRESOURCE_H_ */
