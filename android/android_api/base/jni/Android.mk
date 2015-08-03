LOCAL_PATH := $(call my-dir)
TARGET_ARCH_ABI := $(APP_ABI)

include $(CLEAR_VARS)
OIC_LIB_PATH := ../../../../out/android/$(APP_ABI)/$(APP_OPTIM)
LOCAL_MODULE := libandroid-oc_logger
LOCAL_SRC_FILES := $(OIC_LIB_PATH)/liboc_logger.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
OIC_LIB_PATH := ../../../../out/android/$(APP_ABI)/$(APP_OPTIM)
LOCAL_MODULE := libandroid-octbstack
LOCAL_SRC_FILES := $(OIC_LIB_PATH)/liboctbstack.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
OIC_LIB_PATH := ../../../../out/android/$(APP_ABI)/$(APP_OPTIM)
LOCAL_MODULE := libandroid-oc
LOCAL_SRC_FILES := $(OIC_LIB_PATH)/liboc.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
OIC_LIB_PATH := ../../../../out/android/$(APP_ABI)/$(APP_OPTIM)
LOCAL_MODULE := libandroid-ca
LOCAL_SRC_FILES := $(OIC_LIB_PATH)/libconnectivity_abstraction.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
OIC_SRC_PATH := ../../../resource
LOCAL_MODULE := libca-interface
LOCAL_SRC_FILES := JniCaInterface.c
LOCAL_STATIC_LIBRARIES := libandroid-ca
LOCAL_LDLIBS := -llog
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/csdk/connectivity/api
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
OIC_SRC_PATH := ../../../resource
OIC_OUT_PATH := ../../../out
LOCAL_MODULE    := ocstack-jni
LOCAL_SRC_FILES :=  JniOcStack.cpp \
                    JniUtils.cpp \
                    JniEntityHandler.cpp \
                    JniOnResourceFoundListener.cpp \
                    JniOnDeviceInfoListener.cpp \
		    JniOnPlatformInfoListener.cpp \
                    JniOnPresenceListener.cpp \
                    JniOnGetListener.cpp \
                    JniOnPutListener.cpp \
                    JniOnPostListener.cpp \
                    JniOnDeleteListener.cpp \
                    JniOnObserveListener.cpp \
                    JniOcRepresentation.cpp \
                    JniOcResourceHandle.cpp \
                    JniOcPresenceHandle.cpp \
                    JniOcRequestHandle.cpp \
                    JniOcResourceRequest.cpp \
                    JniOcResourceResponse.cpp \
                    JniOcPlatform.cpp \
                    JniOcResource.cpp \
                    JniOcResourceIdentifier.cpp \
                    JniOcSecurity.cpp

LOCAL_LDLIBS := -llog
LOCAL_STATIC_LIBRARIES := android-oc
LOCAL_STATIC_LIBRARIES += android-octbstack
LOCAL_STATIC_LIBRARIES += android-coap
LOCAL_STATIC_LIBRARIES += android-oc_logger
LOCAL_STATIC_LIBRARIES += android-ca
LOCAL_STATIC_LIBRARIES += android_cpp11_compat

LOCAL_CPPFLAGS += -std=c++0x
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_C_INCLUDES := $(OIC_SRC_PATH)/include
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/c_common
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/csdk/stack/include
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/csdk/ocsocket/include
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/oc_logger/include
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/../extlibs/boost/boost_1_58_0
LOCAL_C_INCLUDES += $(OIC_SRC_PATH)/../build_common/android/compatibility
include $(BUILD_SHARED_LIBRARY)
