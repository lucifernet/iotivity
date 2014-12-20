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


/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class OC_Cm_Server_ResourceHandler_ResourceHandlerFactory */

#ifndef _Included_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
#define _Included_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
 * Method:    constructNative
 * Signature: (LOC/Cm/Server/ResourceHandler/ResourceHandlerFactory;)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory_constructNative
(JNIEnv *, jobject, jobject);

/*
 * Class:     OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
 * Method:    deleteNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory_deleteNative
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
 * Method:    registerResourceType
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory_registerResourceType
(JNIEnv *, jobject, jlong, jint, jstring);

/*
 * Class:     OC_Cm_Server_ResourceHandler_ResourceHandlerFactory
 * Method:    getResourceType
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Server_ResourceHandler_ResourceHandlerFactory_getResourceType
(JNIEnv *, jobject, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
