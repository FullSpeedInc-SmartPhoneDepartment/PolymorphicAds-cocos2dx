//
//  CCFSAdDoubleBannerView.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#define USING_NS_CC_FSADDOUBLEBANNERVIEW            using namespace fsaddoublebannerview_plugin
#define NS_CC_FSADDOUBLEBANNERVIEW_EXT_BEGIN        namespace fsaddoublebannerview_plugin {
#define NS_CC_FSADDOUBLEBANNERVIEW_EXT_END          }


NS_CC_FSADDOUBLEBANNERVIEW_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdDoubleBannerViewDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdDoubleBannerView() {};
    
    /**
     failed to initalize ad unit
     */
    virtual void failedInitAdFSAdDoubleBannerView() {};
    
    /**
     failed for send ad request
     */
    virtual void failedSendAdRequestFSAdDoubleBannerView() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdDoubleBannerView() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdDoubleBannerView() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdDoubleBannerView() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdDoubleBannerView() {};
    
    /**
     failed to create ad view
     */
    virtual void failedCreateFSAdDoubleBannerView() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdDoubleBannerView() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdDoubleBannerView() {};
};

class CCAdDoubleBannerView
{
public:
    CCAdDoubleBannerView();
    virtual ~CCAdDoubleBannerView();
    
    static CCAdDoubleBannerView* create();
    
    /**
     initialize
     @param adUnitId : ad unit identifier
     */
    void initAd(const char* adUnitId, int x, int y, int w, int h);
    
    /**
     load and show ad view.
     */
    void loadAndShowAd();
    
    /**
     hide ad view.
     */
    void hideAd();
    
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
    
    void setDelegate(CCAdDoubleBannerViewDelegate* pDelegate) { _WbannerViewDelegate = pDelegate; }
    
protected:
    CCAdDoubleBannerViewDelegate* _WbannerViewDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_FSADDOUBLEBANNERVIEW_EXT_END;

