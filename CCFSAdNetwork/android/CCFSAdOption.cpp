//
//  CCFSAdOption.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/23.
//
//
#include "CCFSAdOption.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"

USING_NS_CC;
NS_CC_FSADOPTION_EXT_BEGIN;

void CCFSAdOption::debugLogEnable(bool enable)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "setLogMode",
                                       "(Z)V"
                                       )) {
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    enable
                                    );
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader debugLogEnable");
    }
}

void CCFSAdOption::testModeEnable(bool enable)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "setTestMode",
                                       "(Z)V"
                                       )) {
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    enable
                                    );
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader testModeEnable");
    }
}

NS_CC_FSADOPTION_EXT_END;


#endif

