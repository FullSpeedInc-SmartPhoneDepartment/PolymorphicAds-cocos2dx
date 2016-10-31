//
//  CCFSAdForcedMovieAdLoader.h
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#define USING_NS_CC_ADFORCEDMOVIE          using namespace fsadforcedmovie_plugin
#define NS_CC_ADFORCEDMOVIE_EXT_BEGIN      namespace fsadforcedmovie_plugin {
#define NS_CC_ADFORCEDMOVIE_EXT_END        }


NS_CC_ADFORCEDMOVIE_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdForcedMovieAdLoaderDelegate
{
public:
    /**
     initialization finished successfully
     */
    virtual void finishInitAdFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     initialization failed
     */
    virtual void failedInitAdFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     failed to send ad request
     */
    virtual void failedSendAdRequestFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     received ad response successfully
     */
    virtual void finishedResponseAdRequestFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     failed to receive ad response
     */
    virtual void failedResponseAdRequestFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     ad response was empty
     */
    virtual void emptyAdResponseAdRequestFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     finished to load movie
     */
    virtual void finishedReadyMovieFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     failed to load movie
     */
    virtual void failedReadyMovieFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     finished to create ad view successfully
     */
    virtual void finishedCreateFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     failed to create ad view
     */
    virtual void failedCreateFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     finished playing
     */
    virtual void completedMovieFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     succeeded to send ad click
     */
    virtual void finishedAdClickFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     failed to send ad click
     */
    virtual void failedAdClickFSAdForcedMovie(const char* adUnitId) {};
    
    /**
     hidden ad view
     */
    virtual void hideAdViewFSAdForcedMovie(const char* adUnitId) {};
};

class CCAdForcedMovieAdLoader
{
public:
    CCAdForcedMovieAdLoader();
    virtual ~CCAdForcedMovieAdLoader();
    
    static CCAdForcedMovieAdLoader* create();
    
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
     load ad information & create ad view
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
    
    void setDelegate(CCAdForcedMovieAdLoaderDelegate* pDelegate) { _forcedmovieDelegate = pDelegate; }
    
protected:
    CCAdForcedMovieAdLoaderDelegate* _forcedmovieDelegate;
    
private:
    
};

NS_CC_ADFORCEDMOVIE_EXT_END;

