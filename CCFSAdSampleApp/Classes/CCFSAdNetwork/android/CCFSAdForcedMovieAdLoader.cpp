//
//  CCFSAdForcedMovieAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#include "CCFSAdForcedMovieAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdForcedMovieAdLoader

static fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pForcedMovieDelegate = nullptr;

USING_NS_CC;

NS_CC_ADFORCEDMOVIE_EXT_BEGIN;

CCAdForcedMovieAdLoader::CCAdForcedMovieAdLoader()
: _forcedmovieDelegate(nullptr)
{
    
}

CCAdForcedMovieAdLoader::~CCAdForcedMovieAdLoader()
{
    
}

CCAdForcedMovieAdLoader* CCAdForcedMovieAdLoader::create()
{
    CCAdForcedMovieAdLoader* view = new CCAdForcedMovieAdLoader();
    return view;
}

void CCAdForcedMovieAdLoader::initAd(const char *adUnitId)
{
    CCLOG("CCAdForcedMovieAdLoader::initAd  Android");
    if (_forcedmovieDelegate) {
        pForcedMovieDelegate = _forcedmovieDelegate;
    }
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdForceMovieAd",
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
        log("failed to call CCAdForcedMovieAdLoader initAd");
    }
}

void CCAdForcedMovieAdLoader::loadAd(const char *adUnitId)
{
    CCLOG("CCAdForcedMovieAdLoader::loadAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdForceMovieAd",
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
        log("failed to call CCAdForcedMovieAdLoader loadAd");
    }
}

void CCAdForcedMovieAdLoader::createAd(const char *adUnitId)
{
    
}

void CCAdForcedMovieAdLoader::loadAndCreateAd(const char *adUnitId)
{
    CCLOG("CCAdForcedMovieAdLoader::loadAndCreateAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAdForceMovieAd",
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
        log("failed to call CCAdForcedMovieAdLoader loadAndCreateAd");
    }
}

void CCAdForcedMovieAdLoader::showAd(const char *adUnitId)
{
    CCLOG("CCAdForcedMovieAdLoader::showAd  Android");
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "showAdForceMovieAd",
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
        log("failed to call CCAdForcedMovieAdLoader showAd");
    }
}

void CCAdForcedMovieAdLoader::hideAd(const char *adUnitId)
{
    CCLOG("CCAdForcedMovieAdLoader::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdForceMovieAd",
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
        log("failed to call CCAdForcedMovieAdLoader hideAd");
    }
}

bool CCAdForcedMovieAdLoader::isReadyAd(const char *adUnitId)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "isReadyAdForceMovieAd",
                                       "(Ljava/lang/String;)Z"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        jboolean ret = m.env->CallStaticBooleanMethod(m.classID, m.methodID, jAdUnitId);
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
        return (bool) (ret == JNI_TRUE);
    } else {
        log("failed to call CCAdForcedMovieAdLoader isReadyAd");
        return false;
    }
}

bool CCAdForcedMovieAdLoader::isDisplayAd(const char *adUnitId)
{
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "isDisplayAdForceMovieAd",
                                       "(Ljava/lang/String;)Z"
                                       )) {
        jstring jAdUnitId = m.env->NewStringUTF(adUnitId);
        jboolean ret = m.env->CallStaticBooleanMethod(m.classID, m.methodID, jAdUnitId);
        m.env->DeleteLocalRef(jAdUnitId);
        m.env->DeleteLocalRef(m.classID);
        return (bool) (ret == JNI_TRUE);
    } else {
        log("failed to call CCAdForcedMovieAdLoader isDisplayAd");
        return false;
    }
}

NS_CC_ADFORCEDMOVIE_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->finishInitAdFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedInitAdFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedSendAdRequestFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->finishedResponseAdRequestFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedResponseAdRequestFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->emptyAdResponseAdRequestFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessShowAdForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->finishedCreateFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureShowAdForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedCreateFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReadyPlayMovieForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->finishedReadyMovieFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailurePreparePlayMovieForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedReadyMovieFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCompletePlayMovieForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->completedMovieFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->finishedAdClickFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->failedAdClickFSAdForcedMovie("");
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onCloseAdForceMovie(JNIEnv* env, jobject thiz) {
        
        if (pForcedMovieDelegate) {
            pForcedMovieDelegate->hideAdViewFSAdForcedMovie("");
        }
    }
    
}

#endif

