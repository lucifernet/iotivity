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
/* Header for class OC_Cm_Client_Resource_Resource */

#ifndef _Included_OC_Cm_Client_Resource_Resource
#define _Included_OC_Cm_Client_Resource_Resource
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    constructNativeClass
 * Signature: (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_Client_Resource_Resource_constructNativeClass
(JNIEnv *, jobject, jlong, jstring, jstring, jstring);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    deleteNativeResource
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_Client_Resource_Resource_deleteNativeResource
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    get
 * Signature: (JLjava/util/Map;LOC/Cm/Client/Resource/IResourceResponseListener;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_get
(JNIEnv *, jobject, jlong, jobjectArray, jobject);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    put
 * Signature: (JLjava/util/Map;JLOC/Cm/Client/Resource/IResourceResponseListener;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_put
(JNIEnv *, jobject, jlong, jobjectArray, jlong, jobject);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    post
 * Signature: (JLjava/util/Map;JLOC/Cm/Client/Resource/IResourceResponseListener;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_post
(JNIEnv *, jobject, jlong, jobjectArray, jlong, jobject);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    delete
 * Signature: (JLjava/util/Map;LOC/Cm/Client/Resource/IResourceResponseListener;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_delete
(JNIEnv *, jobject, jlong, jobjectArray, jobject);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    subscribe
 * Signature: (JLjava/lang/String;Ljava/lang/String;LOC/Cm/Client/Resource/IResourceResponseListener;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_subscribe
(JNIEnv *, jobject, jlong, jstring, jstring, jobject, jstring);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    unSubscribe
 * Signature: (JLjava/lang/String;LOC/Cm/Client/Resource/IResourceResponseListener;)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_Client_Resource_Resource_unSubscribe
(JNIEnv *, jobject, jlong, jstring, jobject);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    setFilter
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_Client_Resource_Resource_setFilter
(JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    setRecursive
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_Client_Resource_Resource_setRecursive
(JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     OC_Cm_Client_Resource_Resource
 * Method:    setResourcePath
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_Client_Resource_Resource_setResourcePath
(JNIEnv *, jobject, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
