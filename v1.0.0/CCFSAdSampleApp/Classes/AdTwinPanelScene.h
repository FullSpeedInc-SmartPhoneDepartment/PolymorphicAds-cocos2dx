//
//  AdTwinPanelScene.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#ifndef AdTwinPanelScene_h
#define AdTwinPanelScene_h

#include "CCFSAdTwinPanelView.h"
#include "cocos2d.h"

USING_NS_CC_FSADTWINPANELVIEW;

class AdTwinPanelScene : public cocos2d::Layer, public CCAdTwinPanelViewDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    
    virtual void finishInitAdFSAdTwinPanelView();
    virtual void failedInitAdFSAdTwinPanelView();
    virtual void failedSendAdRequestFSAdTwinPanelView();
    virtual void finishedResponseAdRequestFSAdTwinPanelView();
    virtual void failedResponseAdRequestFSAdTwinPanelView();
    virtual void emptyAdResponseAdRequestFSAdTwinPanelView();
    virtual void finishedCreateFSAdTwinPanelView();
    virtual void failedCreateFSAdTwinPanelView();
    virtual void finishedAdClickFSAdTwinPanelView();
    virtual void failedAdClickFSAdTwinPanelView();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdTwinPanelScene);
    
private:
    CCAdTwinPanelView* adBannerView;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
    
};

#endif /* AdTwinPanelScene_h */
