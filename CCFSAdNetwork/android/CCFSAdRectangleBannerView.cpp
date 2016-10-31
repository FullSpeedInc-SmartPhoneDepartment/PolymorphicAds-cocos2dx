//
//  CCFSAdRectangleBannerView.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/10/11.
//
//
#include "CCFSAdRectangleBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdRectangleBannerView

static fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pBannerViewDelegate = nullptr;

USING_NS_CC;
NS_CC_FSADRECTANGLEBANNERVIEW_EXT_BEGIN;

CCAdRectangleBannerView::CCAdRectangleBannerView()
: _bannerViewDelegate(nullptr)
{
    
}

CCAdRectangleBannerView::~CCAdRectangleBannerView()
{
    
}

CCAdRectangleBannerView* CCAdRectangleBannerView::create()
{
    CCAdRectangleBannerView* view = new CCAdRectangleBannerView();
    return view;
}

void CCAdRectangleBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    CCLOG("CCAdRectangleBannerView::initAd  Android");
    if (_bannerViewDelegate) {
        pBannerViewDelegate = _bannerViewDelegate;
    }
    
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdRectangleBanner",
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
        log("failed to call CCAdRectangleBannerView initAd");
    }
}

void CCAdRectangleBannerView::hideAd()
{
    CCLOG("CCAdRectangleBannerView::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdRectangleBanner",
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
        log("failed to call CCAdRectangleBannerView hideAd");
    }
}

void CCAdRectangleBannerView::loadAndShowAd()
{
    CCLOG("CCAdRectangleBannerView::loadAndShowAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAndShowRectangleBanner",
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
        log("failed to call CCAdRectangleBannerView loadAndShowAd");
    }
}

void CCAdRectangleBannerView::pause()
{
    CCLOG("CCAdRectangleBannerView::pause  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "pauseAdRectangleBanner",
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
        log("failed to call CCAdRectangleBannerView pause");
    }
}

void CCAdRectangleBannerView::resume()
{
    CCLOG("CCAdRectangleBannerView::resume  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "resumeAdRectangleBanner",
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
        log("failed to call CCAdRectangleBannerView resume");
    }
}

void CCAdRectangleBannerView::setRectAd(int x, int y, int w, int h)
{
    
}

NS_CC_FSADRECTANGLEBANNERVIEW_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishInitAdFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedInitAdFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedSendAdRequestFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishedResponseAdRequestFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedResponseAdRequestFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->emptyAdResponseAdRequestFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->finishedAdClickFSAdRectangleBannerView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdRectangleBanner(JNIEnv* env, jobject thiz) {
        
        if (pBannerViewDelegate) {
            pBannerViewDelegate->failedAdClickFSAdRectangleBannerView();
        }
    }
    
}


#endif

