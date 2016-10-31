//
//  AdInterstitialScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdInterstitialScene_h
#define AdInterstitialScene_h

#include "CCFSAdInterstitialAdLoader.h"
#include "cocos2d.h"

USING_NS_CC_ADINTERSTITIAL;

class AdInterstitialScene : public cocos2d::Layer, public CCAdInterstitialAdLoaderDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    void pushBtnShow(Ref* sender);
    
    // CCAdInterstitialAdLoaderDelegate Methods
    virtual void finishInitAdFSAdInterstitial();
    virtual void failedInitAdFSAdInterstitial();
    virtual void failedSendAdRequestFSAdInterstitial();
    virtual void finishedResponseAdRequestFSAdInterstitial();
    virtual void failedResponseAdRequestFSAdInterstitial();
    virtual void emptyAdResponseAdRequestFSAdInterstitial();
    virtual void finishedAdCreateFSAdInterstitial();
    virtual void failedAdCreateFSAdInterstitial();
    virtual void finishedAdClickFSAdInterstitial();
    virtual void failedAdClickFSAdInterstitial();
    virtual void skipAdCreateFSAdInterstitial();
    virtual void hideFSAdInterstitial();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdInterstitialScene);
    
private:
    CCAdInterstitialAdLoader* interstitialAdLoader;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
    
};

#endif /* AdInterstitialScene_h */
