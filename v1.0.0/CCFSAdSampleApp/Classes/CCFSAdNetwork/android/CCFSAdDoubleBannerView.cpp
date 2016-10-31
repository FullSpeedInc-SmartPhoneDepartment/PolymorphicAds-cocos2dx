//
//  CCFSAdDoubleBannerView.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//
#include "CCFSAdDoubleBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdDoubleBannerView

static fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pWBannerViewDelegate = nullptr;

USING_NS_CC;

NS_CC_FSADDOUBLEBANNERVIEW_EXT_BEGIN;

CCAdDoubleBannerView::CCAdDoubleBannerView()
: _WbannerViewDelegate(nullptr)
{
    
}

CCAdDoubleBannerView::~CCAdDoubleBannerView()
{
    
}

CCAdDoubleBannerView* CCAdDoubleBannerView::create()
{
    CCAdDoubleBannerView* view = new CCAdDoubleBannerView();
    return view;
}

void CCAdDoubleBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    CCLOG("CCAdDoubleBannerView::initAd  Android");
    if (_WbannerViewDelegate) {
        pWBannerViewDelegate = _WbannerViewDelegate;
    }
    
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdDoubleBanner",
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
        log("failed to call CCAdDoubleBannerView initAd");
    }
}

void CCAdDoubleBannerView::hideAd()
{
    CCLOG("CCAdDoubleBannerView::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdDoubleBanner",
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
        log("failed to call CCAdDoubleBannerView hideAd");
    }
}

void CCAdDoubleBannerView::loadAndShowAd()
{
    CCLOG("CCAdDoubleBannerView::loadAndShowAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAndShowDoubleBanner",
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
        log("failed to call CCAdDoubleBannerView loadAndShowAd");
    }
}

void CCAdDoubleBannerView::pause()
{
    CCLOG("CCAdDoubleBannerView::pause  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "pauseAdDoubleBanner",
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
        log("failed to call CCAdDoubleBannerView pause");
    }
}

void CCAdDoubleBannerView::resume()
{
    CCLOG("CCAdDoubleBannerView::resume  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "resumeAdDoubleBanner",
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
        log("failed to call CCAdDoubleBannerView resume");
    }
}

void CCAdDoubleBannerView::setRectAd(int x, int y, int w, int h)
{
    
}

NS_CC_FSADDOUBLEBANNERVIEW_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->finishInitAdFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->failedInitAdFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->failedSendAdRequestFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->finishedResponseAdRequestFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->failedResponseAdRequestFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->emptyAdResponseAdRequestFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->finishedAdClickFSAdDoubleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdDoubleBanner(JNIEnv* env, jobject thiz) {
        
        if (pWBannerViewDelegate) {
            pWBannerViewDelegate->failedAdClickFSAdDoubleBannerView();
        }
    }
}

#endif