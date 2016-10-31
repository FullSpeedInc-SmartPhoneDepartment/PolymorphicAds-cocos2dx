//
//  AdPiPScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdPiPScene_h
#define AdPiPScene_h

#include "CCFSAdPiPAdLoader.h"
#include "cocos2d.h"

USING_NS_CC_ADPIPLOADER;

class AdPiPScene : public cocos2d::Layer, public CCAdPiPAdLoaderDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    
    void pushBtnAdLoad(Ref* sender);
    void pushBtnAdCreate(Ref* sender);
    void pushBtnAdLoadCreate(Ref* sender);
    void pushBtnAdShow(Ref* sender);
    
    //
    virtual void finishInitAdFSAdPiP(const char* adUnitId);
    virtual void failedInitAdFSAdPiP(const char* adUnitId);
    virtual void failedSendAdRequestFSAdPiP(const char* adUnitId);
    virtual void finishedResponseAdRequestFSAdPiP(const char* adUnitId);
    virtual void failedResponseAdRequestFSAdPiP(const char* adUnitId);
    virtual void emptyAdResponseAdRequestFSAdPiP(const char* adUnitId);
    virtual void finishedReadyMovieFSAdPiP(const char* adUnitId);
    virtual void failedReadyMovieFSAdPiP(const char* adUnitId);
    virtual void finishedCreateFSAdPiP(const char* adUnitId);
    virtual void failedCreateFSAdPiP(const char* adUnitId);
    virtual void completedMovieFSAdPiP(const char* adUnitId);
    virtual void finishedAdClickFSAdPiP(const char* adUnitId);
    virtual void failedAdClickFSAdPiP(const char* adUnitId);
    virtual void hideAdViewFSAdPiP(const char* adUnitId);
    virtual void expandedAdViewFSAdPiP(const char* adUnitId);
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdPiPScene);
    
private:
    CCAdPiPAdLoader* pipAdLoader;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
};

#endif /* AdPiPScene_h */
