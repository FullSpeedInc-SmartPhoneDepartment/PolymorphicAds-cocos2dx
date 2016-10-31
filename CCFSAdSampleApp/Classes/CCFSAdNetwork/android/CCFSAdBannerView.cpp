//
//  CCFSAdBannerView.m
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//
#include "CCFSAdBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdBannerView

static fsadbannerview_plugin::CCAdBannerViewDelegate* pBannerViewDelegate = nullptr;

USING_NS_CC;
NS_CC_FSADBANNERVIEW_EXT_BEGIN;

CCAdBannerView::CCAdBannerView()
: _bannerViewDelegate(nullptr)
{
    
}

CCAdBannerView::~CCAdBannerView()
{
    
}

CCAdBannerView* CCAdBannerView::create()
{
    CCAdBannerView* view = new CCAdBannerView();
    return view;
}

void CCAdBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    CCLOG("CCAdBannerView::initAd  Android");
    if (_bannerViewDelegate) {
        pBannerViewDelegate = _bannerViewDelegate;
    }
    
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdBanner",
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
        log("failed to call CCAdBannerView initAd");
    }
}

void CCAdBannerView::hideAd()
{
    CCLOG("CCAdBannerView::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdBanner",
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
        log("failed to call CCAdBannerView hideAd");
    }
}

void CCAdBannerView::loadAndShowAd()
{
    CCLOG("CCAdBannerView::loadAndShowAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAndShowBanner",
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
        log("failed to call CCAdBannerView loadAndShowAd");
    }
}

void CCAdBannerView::pause()
{
    CCLOG("CCAdBannerView::pause  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "pauseAdBanner",
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
        log("failed to call CCAdBannerView pause");
    }
}

void CCAdBannerView::resume()
{
    CCLOG("CCAdBannerView::resume  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "resumeAdBanner",
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
        log("failed to call CCAdBannerView resume");
    }
}

void CCAdBannerView::setRectAd(int x, int y, int w, int h)
{
    
}

NS_CC_FSADBANNERVIEW_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishInitAdFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedInitAdFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedSendAdRequestFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishedResponseAdRequestFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedResponseAdRequestFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->emptyAdResponseAdRequestFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishedAdClickFSAdBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedAdClickFSAdBannerView();
        }
    }
    
}


#endif

