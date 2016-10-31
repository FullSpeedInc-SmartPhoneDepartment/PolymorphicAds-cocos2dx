//
//  CCFSAdSlideInAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#include "CCFSAdSlideInAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdSlideInAdLoader

static fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pSlideinAdLoaderDelegate = nullptr;

USING_NS_CC;

NS_CC_ADSLIDEIN_EXT_BEGIN;

CCAdSlideInAdLoader::CCAdSlideInAdLoader()
: _slideinAdDelegate(nullptr)
{
    
}

CCAdSlideInAdLoader::~CCAdSlideInAdLoader()
{
    
}

CCAdSlideInAdLoader* CCAdSlideInAdLoader::create()
{
    CCAdSlideInAdLoader* view = new CCAdSlideInAdLoader();
    return view;
}

void CCAdSlideInAdLoader::initAd(const char *adUnitId)
{
    CCLOG("CCAdSlideInAdLoader::initAd  Android");
    if (_slideinAdDelegate) {
        pSlideinAdLoaderDelegate = _slideinAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdSlideIn",
                                       "(Ljava/lang/String;III)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        int intervalTime = 0;
        int skipCount = 0;
        int displayTime = 10;
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId, intervalTime, skipCount, displayTime
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdSlideInAdLoader initAd");
    }
}

void CCAdSlideInAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount, int displayTime)
{
    CCLOG("CCAdSlideInAdLoader::initAd  Android");
    if (_slideinAdDelegate) {
        pSlideinAdLoaderDelegate = _slideinAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdSlideIn",
                                       "(Ljava/lang/String;III)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId, intervalTime, skipCount, displayTime
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdSlideInAdLoader initAd");
    }
}

void CCAdSlideInAdLoader::loadAd(const char *adUnitId)
{
    CCLOG("CCAdSlideInAdLoader::loadAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdSlideIn",
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
        log("failed to call CCAdSlideInAdLoader loadAd");
    }
}

void CCAdSlideInAdLoader::showAd(const char *adUnitId)
{
    CCLOG("CCAdSlideInAdLoader::showAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdSlideIn",
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
        log("failed to call CCAdSlideInAdLoader showAd");
    }
}

void CCAdSlideInAdLoader::hideAd()
{
    CCLOG("CCAdSlideInAdLoader::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdSlideIn",
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
        log("failed to call CCAdSlideInAdLoader hideAd");
    }
}

NS_CC_ADSLIDEIN_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->finishInitAdFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->failedInitAdFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->failedSendAdRequestFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->finishedResponseAdRequestFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->failedResponseAdRequestFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->emptyAdResponseAdRequestFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSkipShowAdSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->skipAdCreateFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCloseAdSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->hideFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->finishedAdClickFSAdSlideIn();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdSlideIn(JNIEnv* env, jobject thiz) {
        
        if (pSlideinAdLoaderDelegate) {
            pSlideinAdLoaderDelegate->failedAdClickFSAdSlideIn();
        }
    }
    
}


#endif  //CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

