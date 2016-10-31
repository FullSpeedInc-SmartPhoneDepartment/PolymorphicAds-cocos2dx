//
//  CCFSAdBannerView.h
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//


#define USING_NS_CC_FSADBANNERVIEW  using namespace fsadbannerview_plugin
#define NS_CC_FSADBANNERVIEW_EXT_BEGIN        namespace fsadbannerview_plugin {
#define NS_CC_FSADBANNERVIEW_EXT_END          }


NS_CC_FSADBANNERVIEW_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdBannerViewDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdBannerView() {};
    
    /**
     failed to initalize ad unit
     */
    virtual void failedInitAdFSAdBannerView() {};
    
    /**
     failed for send ad request
     */
    virtual void failedSendAdRequestFSAdBannerView() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdBannerView() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdBannerView() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdBannerView() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdBannerView() {};
    
    /**
     failed to create ad view
     */
    virtual void failedCreateFSAdBannerView() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdBannerView() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdBannerView() {};
};
    
class CCAdBannerView
{
public:
    CCAdBannerView();
    virtual ~CCAdBannerView();
    
    static CCAdBannerView* create();
    
    /**
     initialize
     @param adUnitId : ad unit identifier
     */
    void initAd(const char* adUnitId, int x, int y, int w, int h);
    
    /**
     hide ad view.
     */
    void hideAd();
    
    /**
     load and show ad view.
     */
    void loadAndShowAd();
    
    /**
     pause reload timer
     */
    void pause();
    
    /**
     resume reload timer
     */
    void resume();
    
    /**
     set rect ad view
     */
    void setRectAd(int x, int y, int w, int h);
    
    void setDelegate(CCAdBannerViewDelegate* pDelegate) { _bannerViewDelegate = pDelegate; }
    
protected:
    CCAdBannerViewDelegate* _bannerViewDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_FSADBANNERVIEW_EXT_END;

