//
//  CCFSAdSlideInAdLoader.h
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#define USING_NS_CC_ADSLIDEIN          using namespace fsadslidein_plugin
#define NS_CC_ADSLIDEIN_EXT_BEGIN      namespace fsadslidein_plugin {
#define NS_CC_ADSLIDEIN_EXT_END        }

NS_CC_ADSLIDEIN_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdSlideInAdLoaderDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdSlideIn() {};
    
    /**
     initialization failed
     */
    virtual void failedInitAdFSAdSlideIn() {};
    
    /**
     failed to send ad request
     */
    virtual void failedSendAdRequestFSAdSlideIn() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdSlideIn() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdSlideIn() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdSlideIn() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedAdCreateFSAdSlideIn() {};
    
    /**
     failed to create ad view
     */
    virtual void failedAdCreateFSAdSlideIn() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdSlideIn() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdSlideIn() {};
    
    /**
     skipped to create ad view
     */
    virtual void skipAdCreateFSAdSlideIn() {};
    
    /**
     hidden ad view
     */
    virtual void hideFSAdSlideIn() {};
    
};

class CCAdSlideInAdLoader
{
public:
    CCAdSlideInAdLoader();
    virtual ~CCAdSlideInAdLoader();
    
    static CCAdSlideInAdLoader* create();
    
    /**
     initialize ad
     @param adUnitId:ad unit identifier
     */
    void initAd(const char* adUnitId);
    
    /**
     initialize ad
     @param adUnitId : ad unit identifier
     @param intervalTime : ad display interval time(seconds)
     @param skipCount : ad display skip count
     @param displayTime : time displaying ad(seconds)
     
     you need to specify either or both of "intervalTime" and "skipCount" parameter to controll skipping.
     if both specified, skipCount will be handled first. put zero if you do not want to put specific value.
     set zero to ignore value. displayTime need to be more than 5(seconds) which means it will be ignored if you set less 5.
     
     */
    void initAd(const char* adUnitId, int intervalTime, int skipCount, int displayTime);
    
    /**
     load ad
     @param adUnitId : ad unit identifier
     */
    void loadAd(const char* adUnitId);
    
    /**
     show ad view
     @param adUnitId : ad unit identifier
     
     You can't force new ad displayed during another(previous) ad displayed
     */
    void showAd(const char* adUnitId);
    
    /**
     hide ad view manually
     */
    void hideAd();
    
    void setDelegate(CCAdSlideInAdLoaderDelegate* pDelegate) { _slideinAdDelegate = pDelegate; }
    
protected:
    CCAdSlideInAdLoaderDelegate* _slideinAdDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_ADSLIDEIN_EXT_END;
