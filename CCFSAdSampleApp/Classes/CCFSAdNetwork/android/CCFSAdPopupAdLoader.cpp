//
//  CCFSAdPopupAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#include "CCFSAdPopupAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android


#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdPopupAdLoader

static fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pPopupAdLoaderDelegate = nullptr;

USING_NS_CC;

NS_CC_ADPOPUP_EXT_BEGIN;

CCAdPopupAdLoader::CCAdPopupAdLoader()
: _popupAdDelegate(nullptr)
{
    
}

CCAdPopupAdLoader::~CCAdPopupAdLoader()
{
    
}

CCAdPopupAdLoader* CCAdPopupAdLoader::create()
{
    CCAdPopupAdLoader* view = new CCAdPopupAdLoader();
    return view;
}

void CCAdPopupAdLoader::initAd(const char *adUnitId)
{
    CCLOG("CCAdPopupAdLoader::initAd  Android");
    if (_popupAdDelegate) {
        pPopupAdLoaderDelegate = _popupAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdPopup",
                                       "(Ljava/lang/String;II)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        int intervalTime = 0;
        int skipCount = 0;
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId, intervalTime, skipCount
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader initAd");
    }
}

void CCAdPopupAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount)
{
    CCLOG("CCAdPopupAdLoader::initAd  Android");
    if (_popupAdDelegate) {
        pPopupAdLoaderDelegate = _popupAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdPopup",
                                       "(Ljava/lang/String;II)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId, intervalTime, skipCount
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader initAd");
    }
}

void CCAdPopupAdLoader::loadAd(const char *adUnitId)
{
    CCLOG("CCAdPopupAdLoader::loadAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdPopup",
                                       "(Ljava/lang/String;)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader loadAd");
    }
}

void CCAdPopupAdLoader::showAd(const char *adUnitId)
{
    CCLOG("CCAdPopupAdLoader::showAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdPopup",
                                       "(Ljava/lang/String;)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader showAd");
    }
}

void CCAdPopupAdLoader::hideAd()
{
    CCLOG("CCAdPopupAdLoader::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdPopup",
                                       "(Ljava/lang/String;)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(_adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPopupAdLoader hideAd");
    }
}

NS_CC_ADPOPUP_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->finishInitAdFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->failedInitAdFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->failedSendAdRequestFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->finishedResponseAdRequestFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->failedResponseAdRequestFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->emptyAdResponseAdRequestFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSkipShowAdPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->skipAdCreateFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCloseAdPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->hideFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->finishedAdClickFSAdPopup();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdPopup(JNIEnv* env, jobject thiz) {
        
        if (pPopupAdLoaderDelegate) {
            pPopupAdLoaderDelegate->failedAdClickFSAdPopup();
        }
    }
    
}


#endif  //CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
