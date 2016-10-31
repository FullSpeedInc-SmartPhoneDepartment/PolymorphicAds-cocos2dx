//
//  AdDoubleBannerScene.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#ifndef AdDoubleBannerScene_h
#define AdDoubleBannerScene_h

#include "CCFSAdDoubleBannerView.h"
#include "cocos2d.h"

USING_NS_CC_FSADDOUBLEBANNERVIEW;

class AdDoubleBannerScene : public cocos2d::Layer, public CCAdDoubleBannerViewDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    
    virtual void finishInitAdFSAdDoubleBannerView();
    virtual void failedInitAdFSAdDoubleBannerView();
    virtual void failedSendAdRequestFSAdDoubleBannerView();
    virtual void finishedResponseAdRequestFSAdDoubleBannerView();
    virtual void failedResponseAdRequestFSAdDoubleBannerView();
    virtual void emptyAdResponseAdRequestFSAdDoubleBannerView();
    virtual void finishedCreateFSAdDoubleBannerView();
    virtual void failedCreateFSAdDoubleBannerView();
    virtual void finishedAdClickFSAdDoubleBannerView();
    virtual void failedAdClickFSAdDoubleBannerView();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdDoubleBannerScene);
    
private:
    CCAdDoubleBannerView* adBannerView;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
    
};

#endif /* AdDoubleBannerScene_h */
