//
//  AdPopupScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdPopupScene_h
#define AdPopupScene_h

#include "CCFSAdPopupAdLoader.h"
#include "cocos2d.h"

USING_NS_CC_ADPOPUP;

class AdPopupScene : public cocos2d::Layer, public CCAdPopupAdLoaderDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    void pushBtnShow(Ref* sender);
    
    // CCADPopupAdLoader Delegate Methods
    virtual void finishInitAdFSAdPopup();
    virtual void failedInitAdFSAdPopup();
    virtual void failedSendAdRequestFSAdPopup();
    virtual void finishedResponseAdRequestFSAdPopup();
    virtual void failedResponseAdRequestFSAdPopup();
    virtual void emptyAdResponseAdRequestFSAdPopup();
    virtual void finishedAdCreateFSAdPopup();
    virtual void failedAdCreateFSAdPopup();
    virtual void finishedAdClickFSAdPopup();
    virtual void failedAdClickFSAdPopup();
    virtual void skipAdCreateFSAdPopup();
    virtual void hideFSAdPopup();
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdPopupScene);
    
private:
    CCAdPopupAdLoader* popupAdLoader;
    const char* adUnitId;
    
    cocos2d::Label* _labelStatus;
};


#endif /* AdPopupScene_h */
