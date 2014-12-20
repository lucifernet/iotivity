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

package gen.client.resource;

/**
 * This interface provides listener methods to receive response of SHP requests
 * which are sent using gen.client.resource.UsageLimitsResource class.<br>
 * <br>
 * 
 * Application developers must have the knowledge of input and output data
 * format of SHP requests. Then only they can properly type cast the response
 * data.<br>
 * <br>
 * 
 * Application needs to type cast the response data to corresponding data class
 * generated by SHP-SDK. SHP-SDK also generates resource specific controllers
 * and status listeners. It is advisable to use these resource specific
 * controllers and interfaces to avoid type casting.
 * 
 * @since 1.0.0
 */
public interface IUsageLimitsResourceResponseListener {
    /**
     * Listener method to receive a response of add subscription request.<br>
     * In order to make this function to be called, please see the
     * gen.client.resource.UsageLimitsResource.onSubscribeResponseReceived()
     * method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param status
     *            Http status code of the response
     * @param subscriptionUri
     *            Subscription URI which corresponds to a specific resource
     *            created by a server
     * @since 1.0.0
     */
    void onSubscribeResponseReceived(int clientSessionId, int statusCode,
            String subscriptionUri);

    /**
     * Listener method to receive a response of remove subscription request.<br>
     * In order to make this function to be called, please see the
     * gen.client.resource.UsageLimitsResource.onUnSubscribeResponseReceived()
     * method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param status
     *            Http status code of the response
     * @since 1.0.0
     */
    void onUnSubscribeResponseReceived(int clientSessionId, int statusCode);

    /**
     * Error callback method for the http requests sent using
     * gen.client.resource.UsageLimitsResource class.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param statusCode
     *            (-1) Unable to provide a http status code / Http status code
     * @param errorCode
     *            Error code defined by a SHP framework. Please see the
     *            OC.Cm.SHPErrorCode enumeration.
     * @param errorMessage
     *            Description of the error
     * @since 1.0.0
     */
    void onError(int clientSessionId, int statusCode,
            OC.Cm.CMErrorCode errorCode,
            OC.Cm.Serialization.Xsd.CMErrorMessage error);

    /**
     * Listener method to receive a response of GET request.<br>
     * Please see the
     * gen.client.resource.UsageLimitsResource.OnGetResponseReceived() method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param statusCode
     *            Http status code of the response
     * @param respData
     *            Received UsageLimits object through the deserializer. This
     *            object should not be re-initialized by the user.
     */
    boolean onGetUsageLimits(int clientSessionId, int statusCode,
            gen.xsd.UsageLimits respData);

    /**
     * Listener method to receive a response of PUT request.<br>
     * Please see the
     * gen.client.resource.UsageLimitsResource.OnPutResponseReceived() method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param statusCode
     *            Http status code of the response
     */
    boolean onPutUsageLimits(int clientSessionId, int statusCode);

    /**
     * Listener method to receive a response of POST request.<br>
     * Please see the
     * gen.client.resource.UsageLimitsResource.OnPostResponseReceived() method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param statusCode
     *            Http status code of the response
     * @param respData
     *            Received UsageLimits object through the deserializer. This
     *            object should not be re-initialized by the user.
     */
    boolean onPostUsageLimits(int clientSessionId, int statusCode,
            String location);

    /**
     * Listener method to receive a response of DELETE request.<br>
     * Please see the
     * gen.client.resource.UsageLimitsResource.OnDeleteResponseReceived()
     * method.
     * 
     * @param clientSessionId
     *            Id of the request to which current response belongs
     * @param statusCode
     *            Http status code of the response
     */
    boolean onDeleteUsageLimits(int clientSessionId, int statusCode);
}
