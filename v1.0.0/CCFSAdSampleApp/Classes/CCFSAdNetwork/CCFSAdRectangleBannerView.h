//
//  CCFSAdRectangleBannerView.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/10/11.
//
//

#define USING_NS_CC_FSADRECTANGLEBANNERVIEW              using namespace fsadrectanglebannerview_plugin
#define NS_CC_FSADRECTANGLEBANNERVIEW_EXT_BEGIN          namespace fsadrectanglebannerview_plugin {
#define NS_CC_FSADRECTANGLEBANNERVIEW_EXT_END            }

NS_CC_FSADRECTANGLEBANNERVIEW_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdRectangleBannerViewDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdRectangleBannerView() {};
    
    /**
     failed to initalize ad unit
     */
    virtual void failedInitAdFSAdRectangleBannerView() {};
    
    /**
     failed for send ad request
     */
    virtual void failedSendAdRequestFSAdRectangleBannerView() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdRectangleBannerView() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdRectangleBannerView() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdRectangleBannerView() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdRectangleBannerView() {};
    
    /**
     failed to create ad view
     */
    virtual void failedCreateFSAdRectangleBannerView() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdRectangleBannerView() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdRectangleBannerView() {};
};

class CCAdRectangleBannerView
{
public:
    CCAdRectangleBannerView();
    virtual ~CCAdRectangleBannerView();
    
    static CCAdRectangleBannerView* create();
    
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
    
    void setDelegate(CCAdRectangleBannerViewDelegate* pDelegate) { _bannerViewDelegate = pDelegate; }
    
protected:
    CCAdRectangleBannerViewDelegate* _bannerViewDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_FSADRECTANGLEBANNERVIEW_EXT_END;
