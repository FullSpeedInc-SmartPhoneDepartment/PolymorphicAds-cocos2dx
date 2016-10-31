//
//  AdSlideInScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdSlideInScene_h
#define AdSlideInScene_h

#include "CCFSAdSlideInAdLoader.h"
#include "cocos2d.h"

USING_NS_CC_ADSLIDEIN;

class AdSlideInScene : public cocos2d::Layer, public CCAdSlideInAdLoaderDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    void pushBtnShow(Ref* sender);
    
    virtual void finishInitAdFSAdSlideIn();
    virtual void failedInitAdFSAdSlideIn();
    virtual void failedSendAdRequestFSAdSlideIn();
    virtual void finishedResponseAdRequestFSAdSlideIn();
    virtual void failedResponseAdRequestFSAdSlideIn();
    virtual void emptyAdResponseAdRequestFSAdSlideIn();
    virtual void finishedAdCreateFSAdSlideIn();
    virtual void failedAdCreateFSAdSlideIn();
    virtual void finishedAdClickFSAdSlideIn();
    virtual void failedAdClickFSAdSlideIn();
    virtual void skipAdCreateFSAdSlideIn();
    virtual void hideFSAdSlideIn();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdSlideInScene);
    
private:
    CCAdSlideInAdLoader* slideinAdLoader;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
};


#endif /* AdSlideInScene_h */
