//
//  CCFSAdPopupAdLoader.h
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#define USING_NS_CC_ADPOPUP          using namespace fsadpopup_plugin
#define NS_CC_ADPOPUP_EXT_BEGIN      namespace fsadpopup_plugin {
#define NS_CC_ADPOPUP_EXT_END        }


NS_CC_ADPOPUP_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdPopupAdLoaderDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdPopup() {};
    
    /**
     initialization failed
     */
    virtual void failedInitAdFSAdPopup() {};
    
    /**
     failed to send ad request
     */
    virtual void failedSendAdRequestFSAdPopup() {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdPopup() {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdPopup() {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdPopup() {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedAdCreateFSAdPopup() {};
    
    /**
     failed to create ad view
     */
    virtual void failedAdCreateFSAdPopup() {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdPopup() {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdPopup() {};
    
    /**
     skipped to create ad view
     */
    virtual void skipAdCreateFSAdPopup() {};
    
    /**
     hidden ad view
     */
    virtual void hideFSAdPopup() {};
};

class CCAdPopupAdLoader
{
public:
    CCAdPopupAdLoader();
    virtual ~CCAdPopupAdLoader();
    
    static CCAdPopupAdLoader* create();
    
    void initAd(const char* adUnitId);
    void initAd(const char* adUnitId, int intervalTime, int skipCount);
    void loadAd(const char* adUnitId);
    void showAd(const char* adUnitId);
    void hideAd();
    
    void setDelegate(CCAdPopupAdLoaderDelegate* pDelegate) { _popupAdDelegate = pDelegate; }
    
protected:
    CCAdPopupAdLoaderDelegate* _popupAdDelegate;
    const char* _adUnitId;
    
private:
    
};

NS_CC_ADPOPUP_EXT_END;
