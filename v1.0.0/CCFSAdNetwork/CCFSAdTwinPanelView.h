//
//  CCFSAdTwinPanelView.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#define USING_NS_CC_FSADTWINPANELVIEW            using namespace fsadtwinpanelview_plugin
#define NS_CC_FSADTWINPANELVIEW_EXT_BEGIN        namespace fsadtwinpanelview_plugin {
#define NS_CC_FSADTWINPANELVIEW_EXT_END          }


NS_CC_FSADTWINPANELVIEW_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdTwinPanelViewDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdTwinPanelView() {};
    
    /**
     failed to initalize ad unit
     */
    virtual void failedInitAdFSAdTwinPanelView() {};
    
    /**
     failed for send ad request
     */
    virtual void failedSendAdRequestFSAdTwinPanelView() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdTwinPanelView() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdTwinPanelView() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdTwinPanelView() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdTwinPanelView() {};
    
    /**
     failed to create ad view
     */
    virtual void failedCreateFSAdTwinPanelView() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdTwinPanelView() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdTwinPanelView() {};
};

class CCAdTwinPanelView
{
public:
    CCAdTwinPanelView();
    virtual ~CCAdTwinPanelView();
    
    static CCAdTwinPanelView* create();
    
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
    
    void setDelegate(CCAdTwinPanelViewDelegate* pDelegate) { _twinPanelViewDelegate = pDelegate; }
    
protected:
    CCAdTwinPanelViewDelegate* _twinPanelViewDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_FSADTWINPANELVIEW_EXT_END;
