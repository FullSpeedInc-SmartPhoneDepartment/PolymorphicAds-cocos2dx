//
//  CCFSAdPiPAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#include "CCFSAdPiPAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdPiPAdLoader

static fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pPiPAdLoaderDelegate = nullptr;

USING_NS_CC;

NS_CC_ADPIPLOADER_EXT_BEGIN;

CCAdPiPAdLoader::CCAdPiPAdLoader()
: _pipadloaderDelegate(nullptr)
{
    
}

CCAdPiPAdLoader::~CCAdPiPAdLoader()
{
    
}

CCAdPiPAdLoader* CCAdPiPAdLoader::create()
{
    CCAdPiPAdLoader* view = new CCAdPiPAdLoader();
    return view;
}

void CCAdPiPAdLoader::initAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::initAd  Android");
    if (_pipadloaderDelegate) {
        pPiPAdLoaderDelegate = _pipadloaderDelegate;
    }
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdPiP",
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
        log("failed to call CCAdPiPAdLoader initAd");
    }
}

void CCAdPiPAdLoader::loadAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::loadAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdPiP",
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
        log("failed to call CCAdPiPAdLoader loadAd");
    }
}

void CCAdPiPAdLoader::createAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::createAd  Android");
    
}

void CCAdPiPAdLoader::loadAndCreateAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::loadAndCreateAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdPiP",
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
        log("failed to call CCAdPiPAdLoader loadAndCreateAd");
    }
}

void CCAdPiPAdLoader::showAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::showAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdPiP",
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
        log("failed to call CCAdPiPAdLoader showAd");
    }
}

void CCAdPiPAdLoader::showAd(const char *adUnitId, CCAdPipPositionType position)
{
    CCLOG("CCAdPiPAdLoader::showAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdPiP",
                                       "(Ljava/lang/String;I)V"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        m.env->CallStaticVoidMethod(
                                    m.classID,
                                    m.methodID,
                                    jAdUnitId, position
                                    );
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
    } else {
        log("failed to call CCAdPiPAdLoader showAd");
    }
}

void CCAdPiPAdLoader::hideAd(const char *adUnitId)
{
    CCLOG("CCAdPiPAdLoader::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdPiP",
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
        log("failed to call CCAdPiPAdLoader hideAd");
    }
}

bool CCAdPiPAdLoader::isReadyAd(const char *adUnitId)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "isReadyAdPiP",
                                       "(Ljava/lang/String;)Z"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        jboolean ret = m.env->CallStaticBooleanMethod(m.classID, m.methodID, jAdUnitId);
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
        return (bool) (ret == JNI_TRUE);
    } else {
        log("failed to call CCAdPiPAdLoader isReadyAd");
        return false;
    }
}

bool CCAdPiPAdLoader::isDisplayAd(const char *adUnitId)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "isDisplayAdPiP",
                                       "(Ljava/lang/String;)Z"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        jboolean ret = m.env->CallStaticBooleanMethod(m.classID, m.methodID, jAdUnitId);
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
        return (bool) (ret == JNI_TRUE);
    } else {
        log("failed to call CCAdPiPAdLoader isDisplayAd");
        return false;
    }
}

NS_CC_ADPIPLOADER_EXT_END;



// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->finishInitAdFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->failedInitAdFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->failedSendAdRequestFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->finishedResponseAdRequestFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->failedResponseAdRequestFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->emptyAdResponseAdRequestFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCloseAdPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->hideAdViewFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->finishedAdClickFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->failedAdClickFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReadyPlayMoviePiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->finishedReadyMovieFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailurePreparePlayMoviePiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->failedReadyMovieFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCompletePlayMoviePiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->completedMovieFSAdPiP("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onExpandedAdViewPiP(JNIEnv* env, jobject thiz) {
        
        if (pPiPAdLoaderDelegate) {
            pPiPAdLoaderDelegate->expandedAdViewFSAdPiP("");
        }
    }
}


#endif

