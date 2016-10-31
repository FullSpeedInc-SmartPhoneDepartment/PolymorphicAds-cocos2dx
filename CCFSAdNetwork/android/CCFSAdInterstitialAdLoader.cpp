//
//  CCFSAdInterstitialAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//
#include "CCFSAdInterstitialAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdInterstitialAdLoader

static fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pInterstitialDelegate = nullptr;

USING_NS_CC;

NS_CC_ADINTERSTITIAL_EXT_BEGIN;

CCAdInterstitialAdLoader::CCAdInterstitialAdLoader()
: _interstitialAdDelegate(nullptr)
{
    
}

CCAdInterstitialAdLoader::~CCAdInterstitialAdLoader()
{
    
}

CCAdInterstitialAdLoader* CCAdInterstitialAdLoader::create()
{
    CCAdInterstitialAdLoader* view = new CCAdInterstitialAdLoader();
    return view;
}

void CCAdInterstitialAdLoader::initAd(const char *adUnitId)
{
    CCLOG("CCAdInterstitialAdLoader::initAd  Android");
    if (_interstitialAdDelegate) {
        pInterstitialDelegate = _interstitialAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdInterstitial",
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
        log("failed to call CCAdInterstitialAdLoader initAd");
    }
}

void CCAdInterstitialAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount)
{
    CCLOG("CCAdInterstitialAdLoader::initAd  Android");
    if (_interstitialAdDelegate) {
        pInterstitialDelegate = _interstitialAdDelegate;
    }
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdInterstitial",
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
        log("failed to call CCAdInterstitialAdLoader initAd");
    }
}

void CCAdInterstitialAdLoader::loadAd(const char *adUnitId)
{
    CCLOG("CCAdInterstitialAdLoader::loadAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdInterstitial",
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
        log("failed to call CCAdInterstitialAdLoader loadAd");
    }
}

void CCAdInterstitialAdLoader::showAd(const char *adUnitId)
{
    CCLOG("CCAdInterstitialAdLoader::showAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdInterstitial",
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
        log("failed to call CCAdInterstitialAdLoader showAd");
    }
}

void CCAdInterstitialAdLoader::hideAd()
{
    CCLOG("CCAdInterstitialAdLoader::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdInterstitial",
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
        log("failed to call CCAdInterstitialAdLoader hideAd");
    }
}

bool CCAdInterstitialAdLoader::isReadyAd(const char *adUnitId)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "isReadyAdInterstitial",
                                       "(Ljava/lang/String;)Z"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        jboolean ret = m.env->CallStaticBooleanMethod(m.classID, m.methodID, jAdUnitId);
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
        return (bool) (ret == JNI_TRUE);
    } else {
        log("failed to call CCAdInterstitialAdLoader isReadyAd");
        return false;
    }
}

NS_CC_ADINTERSTITIAL_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->finishInitAdFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->failedInitAdFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->failedSendAdRequestFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->finishedResponseAdRequestFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->failedResponseAdRequestFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->emptyAdResponseAdRequestFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSkipShowAdInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->skipAdCreateFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCloseAdInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->hideFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->finishedAdClickFSAdInterstitial();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdInterstitial(JNIEnv* env, jobject thiz) {
        
        if (pInterstitialDelegate) {
            pInterstitialDelegate->failedAdClickFSAdInterstitial();
        }
    }
    
}



#endif

