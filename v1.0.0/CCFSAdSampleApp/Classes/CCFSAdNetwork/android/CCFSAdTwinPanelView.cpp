//
//  CCFSAdTwinPanelView.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//
#include "CCFSAdTwinPanelView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android

#include "cocos2d.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"


#define JNI_PACKAGE_CLASS_NAME      "jp/co/fullspeed/polymorphicads/adapter/FSAdNetworkCocos2dxPlugin"


#pragma mark - CCAdTwinPanelView

static fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pTwinPanelViewDelegate = nullptr;

USING_NS_CC;

NS_CC_FSADTWINPANELVIEW_EXT_BEGIN;

CCAdTwinPanelView::CCAdTwinPanelView()
: _twinPanelViewDelegate(nullptr)
{
    
}

CCAdTwinPanelView::~CCAdTwinPanelView()
{
    
}

CCAdTwinPanelView* CCAdTwinPanelView::create()
{
    CCAdTwinPanelView* view = new CCAdTwinPanelView();
    return view;
}

void CCAdTwinPanelView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    CCLOG("CCAdTwinPanelView::initAd  Android");
    if (_twinPanelViewDelegate) {
        pTwinPanelViewDelegate = _twinPanelViewDelegate;
    }
    
    _adUnitId = adUnitId;
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "initAdTwinPanel",
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
        log("failed to call CCAdTwinPanelView initAd");
    }
}

void CCAdTwinPanelView::hideAd()
{
    CCLOG("CCAdTwinPanelView::hideAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "hideAdTwinPanel",
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
        log("failed to call CCAdTwinPanelView hideAd");
    }
}

void CCAdTwinPanelView::loadAndShowAd()
{
    CCLOG("CCAdTwinPanelView::loadAndShowAd  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "loadAndShowAdTwinPanel",
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
        log("failed to call CCAdTwinPanelView loadAndShowAd");
    }
}

void CCAdTwinPanelView::pause()
{
    CCLOG("CCAdTwinPanelView::pause  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "pauseAdTwinPanel",
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
        log("failed to call CCAdTwinPanelView pause");
    }
}

void CCAdTwinPanelView::resume()
{
    CCLOG("CCAdTwinPanelView::resume  Android");
    
    JniMethodInfo m;
    if (JniHelper::getStaticMethodInfo(
                                       m,
                                       JNI_PACKAGE_CLASS_NAME,
                                       "resumeAdTwinPanel",
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
        log("failed to call CCAdTwinPanelView resume");
    }
}

void CCAdTwinPanelView::setRectAd(int x, int y, int w, int h)
{
    
}

NS_CC_FSADTWINPANELVIEW_EXT_END;


// callbacks for Android JNI
extern "C" {
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessInitRequestTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->finishInitAdFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureInitRequestTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->failedInitAdFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureSendAdRequestTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->failedSendAdRequestFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessResponseAdRequestTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->finishedResponseAdRequestFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureResponseAdRequestTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->failedResponseAdRequestFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onReceiveNoAdsTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->emptyAdResponseAdRequestFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onSuccessClickAdTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->finishedAdClickFSAdTwinPanelView();
        }
    }
    
    JNIEXPORT void JNICALL Java_jp_co_fullspeed_polymorphicads_adapter_FSAdNetworkCocos2dxPlugin_onFailureClickAdTwinPanel(JNIEnv* env, jobject thiz) {
        
        if (pTwinPanelViewDelegate) {
            pTwinPanelViewDelegate->failedAdClickFSAdTwinPanelView();
        }
    }
    
}


#endif
