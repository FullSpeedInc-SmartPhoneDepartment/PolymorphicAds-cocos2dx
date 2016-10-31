//
//  CCFSAdInterstitialAdLoader.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//

#define USING_NS_CC_ADINTERSTITIAL          using namespace fsadinterstitial_plugin
#define NS_CC_ADINTERSTITIAL_EXT_BEGIN      namespace fsadinterstitial_plugin {
#define NS_CC_ADINTERSTITIAL_EXT_END        }


NS_CC_ADINTERSTITIAL_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdInterstitialAdLoaderDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdInterstitial() {};
    
    /**
     initialization failed
     */
    virtual void failedInitAdFSAdInterstitial() {};
    
    /**
     failed to send ad request
     */
    virtual void failedSendAdRequestFSAdInterstitial() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdInterstitial() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdInterstitial() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdInterstitial() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedAdCreateFSAdInterstitial() {};
    
    /**
     failed to create ad view
     */
    virtual void failedAdCreateFSAdInterstitial() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdInterstitial() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdInterstitial() {};
    
    /**
     skipped create ad view
     */
    virtual void skipAdCreateFSAdInterstitial() {};
    
    /**
     hidden ad view
     */
    virtual void hideFSAdInterstitial() {};
};

class CCAdInterstitialAdLoader
{
public:
    CCAdInterstitialAdLoader();
    virtual ~CCAdInterstitialAdLoader();
    
    static CCAdInterstitialAdLoader* create();
    
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
     
     you need to specify either or both parameter to controll skipping.
     if both specified, skipCount will be handled first. put zero if you do not want to put specific value.
     to put zero both parameters means ad unit will show up everytime [showAd] called.
     */
    void initAd(const char* adUnitId, int intervalTime, int skipCount);
    
    /**
     load ad
     @param adUnitId : ad unit identifier
     */
    void loadAd(const char* adUnitId);
    
    /**
     show ad view
     @param adUnitId : ad unit identifier
     */
    void showAd(const char* adUnitId);
    
    /**
     hide ad view manually
     */
    void hideAd();
    
    /**
     returns if ad view is ready
     */
    bool isReadyAd(const char* adUnitId);
    
    void setDelegate(CCAdInterstitialAdLoaderDelegate* pDelegate) { _interstitialAdDelegate = pDelegate; }
    
protected:
    CCAdInterstitialAdLoaderDelegate* _interstitialAdDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_ADINTERSTITIAL_EXT_END;

