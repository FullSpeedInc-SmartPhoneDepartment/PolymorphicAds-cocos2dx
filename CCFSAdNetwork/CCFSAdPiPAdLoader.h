//
//  CCFSAdPiPAdLoader.h
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#define USING_NS_CC_ADPIPLOADER          using namespace fsadpiploader_plugin
#define NS_CC_ADPIPLOADER_EXT_BEGIN      namespace fsadpiploader_plugin {
#define NS_CC_ADPIPLOADER_EXT_END        }


NS_CC_ADPIPLOADER_EXT_BEGIN;

typedef enum {
    CCAdPiPPositionTypeLeftTop = 0,
    CCAdPiPPositionTypeRightTop,
    CCAdPiPPositionTypeLeftBottom,
    CCAdPiPPositionTypeRightBottom
} CCAdPipPositionType;

//////////////
// delegate //
//////////////
class CCAdPiPAdLoaderDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdPiP(const char* adUnitId) {};
    
    /**
     initialization failed
     */
    virtual void failedInitAdFSAdPiP(const char* adUnitId) {};
    
    /**
     failed to send ad request
     */
    virtual void failedSendAdRequestFSAdPiP(const char* adUnitId) {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdPiP(const char* adUnitId) {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdPiP(const char* adUnitId) {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdPiP(const char* adUnitId) {};
    
    /**
     finished to load movie
     */
    virtual void finishedReadyMovieFSAdPiP(const char* adUnitId) {};
    
    /**
     failed to load movie
     */
    virtual void failedReadyMovieFSAdPiP(const char* adUnitId) {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdPiP(const char* adUnitId) {};
    
    /**
     failed create ad view
     */
    virtual void failedCreateFSAdPiP(const char* adUnitId) {};
    
    /**
     finished playing
     */
    virtual void completedMovieFSAdPiP(const char* adUnitId) {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdPiP(const char* adUnitId) {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdPiP(const char* adUnitId) {};
    
    /**
     hidden ad view
     */
    virtual void hideAdViewFSAdPiP(const char* adUnitId) {};
    
    /**
     movie expanded
     */
    virtual void expandedAdViewFSAdPiP(const char* adUnitId) {};
};

class CCAdPiPAdLoader
{
public:
    CCAdPiPAdLoader();
    virtual ~CCAdPiPAdLoader();
    
    static CCAdPiPAdLoader* create();
    
    /**
     initialize ad
     @param adUnitId:ad unit identifier
     */
    void initAd(const char* adUnitId);
    
    /**
     load ad
     @param adUnitId : ad unit identifier
     */
    void loadAd(const char* adUnitId);
    
    /**
     create ad view
     @param adUnitId : ad unit identifier
     */
    void createAd(const char* adUnitId);
    
    /**
     load ad & create ad view
     @param adUnitId : ad unit identifier
     
     You can call this instead of calling [loadAd] and [createAd]
     */
    void loadAndCreateAd(const char* adUnitId);
    
    /**
     show ad view
     @param adUnitId : ad unit identifier
     */
    void showAd(const char* adUnitId);
    
    /**
     show ad view
     @param adUnitId : ad unit identifier
     @param positionType : position type
     
     if you do not want to use declared positionType, you need to set position property before call this
     */
    void showAd(const char* adUnitId, CCAdPipPositionType position);
    
    /**
     hide ad view
     @param adUnitId : ad unit identifier
     */
    void hideAd(const char* adUnitId);
    
    /**
     returns if ad view is ready
     @param adUnitId : ad unit identifier
     */
    bool isReadyAd(const char* adUnitId);
    
    /**
     returns if ad view is displayed
     @param adUnitId : ad unit identifier
     */
    bool isDisplayAd(const char* adUnitId);
    
    void setDelegate(CCAdPiPAdLoaderDelegate* pDelegate) { _pipadloaderDelegate = pDelegate; }
    
protected:
    CCAdPiPAdLoaderDelegate* _pipadloaderDelegate;
    
private:
    
};

NS_CC_ADPIPLOADER_EXT_END;
