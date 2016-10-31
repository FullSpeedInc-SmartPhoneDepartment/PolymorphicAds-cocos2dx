//
//  AdBannerScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdBannerScene_h
#define AdBannerScene_h

#include "CCFSAdBannerView.h"
#include "cocos2d.h"

USING_NS_CC_FSADBANNERVIEW;

class AdBannerScene : public cocos2d::Layer, public CCAdBannerViewDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    
    virtual void finishInitAdFSAdBannerView();
    virtual void failedInitAdFSAdBannerView();
    virtual void failedSendAdRequestFSAdBannerView();
    virtual void finishedResponseAdRequestFSAdBannerView();
    virtual void failedResponseAdRequestFSAdBannerView();
    virtual void emptyAdResponseAdRequestFSAdBannerView();
    virtual void finishedCreateFSAdBannerView();
    virtual void failedCreateFSAdBannerView();
    virtual void finishedAdClickFSAdBannerView();
    virtual void failedAdClickFSAdBannerView();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdBannerScene);
    
private:
    CCAdBannerView* adBannerView;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
    
};


#endif /* AdBannerScene_h */
