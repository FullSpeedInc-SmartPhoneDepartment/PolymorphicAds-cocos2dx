//
//  CCFSAdAnalytics.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/23.
//
//
#include "CCFSAdAnalytics.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads_analytics/util/FSAnalyticsCocos2dxPlugin"


static fsadanalytics_plugin::CCAdAnalyticsDelegate* pAnalyticsDelegate = nullptr;

USING_NS_CC;
NS_CC_FSADANALYTICS_EXT_BEGIN;

void CCAdAnalytics::analyticsDebugLogEnable(bool enable)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "analyticsDebugLogEnable",
                                       "(Z)V"
                                       )) {
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    enable
                                    );
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdAnalytics analyticsDebugLogEnable");
    }
}

void CCAdAnalytics::analyticsConversion(const char* conversionId)
{
    CCLOG("CCAdAnalytics::analyticsConversion  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "analyticsConversion",
                                       "(Ljava/lang/String;)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(conversionId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdAnalytics analyticsConversion");
    }
}

void CCAdAnalytics::setDelegate(CCAdAnalyticsDelegate* pDelegate)
{
    pAnalyticsDelegate = pDelegate;
}

NS_CC_FSADANALYTICS_EXT_END;


// callbacks for Android JNI

extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_1analytics_util_FSAnalyticsCocos2dxPlugin_onFinishedConversionFSAdAnalytics(JNIEnv* env, jobject thiz) {
        
        if (pAnalyticsDelegate) {
            pAnalyticsDelegate->finishedConversionFSAdAnalytics();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_1analytics_util_FSAnalyticsCocos2dxPlugin_onFailedConversionFSAdAnalytics(JNIEnv* env, jobject thiz) {
        
        if (pAnalyticsDelegate) {
            pAnalyticsDelegate->failedConversionFSAdAnalytics();
        }
    }
}

#endif

