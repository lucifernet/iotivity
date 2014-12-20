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
/* Header for class OC_Cm_ControlManager */

#ifndef _Included_OC_Cm_ControlManager
#define _Included_OC_Cm_ControlManager

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     OC_Cm_ControlManager
 * Method:    constructNative
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_constructNative
(JNIEnv *, jclass);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    deleteNative
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_deleteNative
(JNIEnv *, jclass, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    start
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_start
(JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    stop
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_stop
(JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    isStarted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_isStarted
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    isSCSConnected
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_isSCSConnected
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getSHPState
 * Signature: (J)LOC/Shp/SHPStates;
 */
JNIEXPORT jobject JNICALL Java_OC_Cm_ControlManager_getCMState
(JNIEnv *, jobject, jlong);

/*   Not supported
 * Class:     OC_Cm_ControlManager
 * Method:    getSimulatorFlag
 * Signature: (J)Z

JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_getSimulatorFlag
  (JNIEnv *, jobject, jlong);

 */

/*  Not supported
 * Class:     OC_Cm_ControlManager
 * Method:    setSimulatorFlag
 * Signature: (JZ)V

JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_setSimulatorFlag
  (JNIEnv *, jobject, jlong, jboolean);

*/

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getSHPMode
 * Signature: (J)LOC/Shp/SHPModes;
 */
JNIEXPORT jobject JNICALL Java_OC_Cm_ControlManager_getCMMode
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    setSHPMode
 * Signature: (JILjava/lang/String;ZJ)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_setCMMode
(JNIEnv *, jobject, jlong, jint, jstring, jboolean, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    setConfiguration
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_setConfiguration
(JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getConfiguration
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_getConfiguration
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getTimer
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_OC_Cm_ControlManager_getTimer
(JNIEnv *, jobject, jlong, jint);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    setTimer
 * Signature: (JII)V

JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_setTimer
  (JNIEnv *, jobject, jlong, jint, jint);

 */

/*
 * Class:     OC_Cm_ControlManager
 * Method:    setCMListener
 * Signature: (JLOC/Shp/ISHPListener;)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_setCMListener
(JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    removeCMListener
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_removeCMListener
(JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getDeviceFinder
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_getDeviceFinder
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getSubscriptionManager
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_getSubscriptionManager
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    addNotificationListener
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_addNotificationListener
(JNIEnv *, jobject , jlong , jobject );

/*
 * Class:     OC_Cm_ControlManager
 * Method:    removeNotificationListener
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_removeNotificationListener
(JNIEnv *, jobject , jlong , jlong ) ;

/*
 * Class:     OC_Cm_ControlManager
 * Method:    validateConfiguration
 * Signature: (JLOC/Shp/Configuration;)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_validateConfiguration
(JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    validateMyDevice
 * Signature: (JLOC/Shp/Device;)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_validateMyDevice
(JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    configureSqliteSubscriptionManager
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_configureSqliteSubscriptionManager
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    configureFileBasedSubscriptionManager
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_configureFileBasedSubscriptionManager
(JNIEnv *, jobject, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    setCMLogLevel
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_setCMLogLevel
(JNIEnv *, jobject, jlong, jint);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    deviceUpdateToSHS
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_OC_Cm_ControlManager_deviceUpdateToSHS
(JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    configureClassLoader
 * Signature: (Ljava/lang/ClassLoader;)V
 */
JNIEXPORT void JNICALL Java_OC_Cm_ControlManager_configureClassLoader
(JNIEnv *, jclass, jobject);

/*
 * Class:     OC_Cm_ControlManager
 * Method:    getContext
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_OC_Cm_ControlManager_getContext
(JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
