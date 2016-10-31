//
//  AdForcedMovieScene.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#ifndef AdForcedMovieScene_h
#define AdForcedMovieScene_h

#include "CCFSAdForcedMovieAdLoader.h"
#include "cocos2d.h"

USING_NS_CC;
USING_NS_CC_ADFORCEDMOVIE;

class AdForcedMovieScene : public cocos2d::Layer, public CCAdForcedMovieAdLoaderDelegate
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void pushBtnBackScene(Ref* sender);
    void pushBtnShow(Ref* sender);
    
    // CCAdForcedMovieAdLoader Delegate Methods
    virtual void finishInitAdFSAdForcedMovie(const char* adUnitId);
    virtual void failedInitAdFSAdForcedMovie(const char* adUnitId);
    virtual void failedSendAdRequestFSAdForcedMovie(const char* adUnitId);
    virtual void finishedResponseAdRequestFSAdForcedMovie(const char* adUnitId);
    virtual void failedResponseAdRequestFSAdForcedMovie(const char* adUnitId);
    virtual void emptyAdResponseAdRequestFSAdForcedMovie(const char* adUnitId);
    virtual void finishedReadyMovieFSAdForcedMovie(const char* adUnitId);
    virtual void failedReadyMovieFSAdForcedMovie(const char* adUnitId);
    virtual void finishedCreateFSAdForcedMovie(const char* adUnitId);
    virtual void failedCreateFSAdForcedMovie(const char* adUnitId);
    virtual void completedMovieFSAdForcedMovie(const char* adUnitId);
    virtual void finishedAdClickFSAdForcedMovie(const char* adUnitId);
    virtual void failedAdClickFSAdForcedMovie(const char* adUnitId);
    virtual void hideAdViewFSAdForcedMovie(const char* adUnitId);
    
    // implement the "static create()" method manually
    CREATE_FUNC(AdForcedMovieScene);
    
private:
    CCAdForcedMovieAdLoader* forcedMovieAdLoader;
    const char* adUnitId;
    
    Label* label_state;
};

#endif /* AdForcedMovieScene_h */
