//
//  AdRectangleBannerScene.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/10/14.
//
//

#ifndef AdRectangleBannerScene_h
#define AdRectangleBannerScene_h

#include "CCFSAdRectangleBannerView.h"
#include "cocos2d.h"

USING_NS_CC_FSADRECTANGLEBANNERVIEW;

class AdRectangleBannerScene : public cocos2d::Layer, public CCAdRectangleBannerViewDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    
    virtual void finishInitAdFSAdRectangleBannerView();
    virtual void failedInitAdFSAdRectangleBannerView();
    virtual void failedSendAdRequestFSAdRectangleBannerView();
    virtual void finishedResponseAdRequestFSAdRectangleBannerView();
    virtual void failedResponseAdRequestFSAdRectangleBannerView();
    virtual void emptyAdResponseAdRequestFSAdRectangleBannerView();
    virtual void finishedCreateFSAdRectangleBannerView();
    virtual void failedCreateFSAdRectangleBannerView();
    virtual void finishedAdClickFSAdRectangleBannerView();
    virtual void failedAdClickFSAdRectangleBannerView();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdRectangleBannerScene);
    
private:
    CCAdRectangleBannerView* adBannerView;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
    
};


#endif /* AdRectangleBannerScene_h */
