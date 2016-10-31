//
//  CCFSAdForcedMovieAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#include "CCFSAdForcedMovieAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#include "cocos2d.h"

#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdForcedMovieAdLoader.h>

#pragma mark - CCFSAdForcedMovieAdLoader

@interface CCFSAdForcedMovieAdLoader : NSObject <FSAdForcedMovieAdLoaderDelegate>
{
    void* object;
}

@end

@implementation CCFSAdForcedMovieAdLoader

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdForcedMovieAdLoader *loader = [[self alloc] init];
        sharedInstance = loader;
    });
    return sharedInstance;
}

- (id)init
{
    self = [super init];
    if (self) {
        
    }
    return self;
}

- (void)setDelegate:(void*)delegate
{
    object = delegate;
}

- (void)initAdForcedMovie:(NSString*)adUnitId
{
    [FSAdForcedMovieAdLoader sharedInstance].delegate = self;
    [[FSAdForcedMovieAdLoader sharedInstance] initAd:adUnitId];
}

- (void)loadAdForcedMovie:(NSString*)adUnitId
{
    [[FSAdForcedMovieAdLoader sharedInstance] loadAd:adUnitId];
}

- (void)createAdForcedMovie:(NSString*)adUnitId
{
    [[FSAdForcedMovieAdLoader sharedInstance] createAd:adUnitId];
}

- (void)loadAndCreateAdCorcedMovie:(NSString*)adUnitId
{
    [[FSAdForcedMovieAdLoader sharedInstance] loadAndCreateAd:adUnitId];
}

- (void)showAdForcedMovie:(NSString*)adUnitId
{
    [[FSAdForcedMovieAdLoader sharedInstance] showAd:adUnitId];
}

- (void)hideAdForcedMovie:(NSString*)adUnitId
{
    [[FSAdForcedMovieAdLoader sharedInstance] hideAd:adUnitId];
}

- (BOOL)isReadyAdForcedMovie:(NSString*)adUnitId
{
    return [[FSAdForcedMovieAdLoader sharedInstance] isReadyAd:adUnitId];
}

- (BOOL)isDisplayAdForcedMovie:(NSString*)adUnitId
{
    return [[FSAdForcedMovieAdLoader sharedInstance] isDisplayAd:adUnitId];
}


#pragma mark - FSAdForcedMovieAdLoaderDelegate

- (void)finishInitAdFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedInitAdFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedSendAdRequestFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)finishedResponseAdRequestFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedResponseAdRequestFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)emptyAdResponseAdRequestFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)finishedReadyMovieFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedReadyMovieFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedReadyMovieFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedReadyMovieFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)finishedCreateFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedCreateFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)completedMovieFSAdForcedMovie:(FSAdForcedMovieAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->completedMovieFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)finishedAdClickFSAdForcedMovie:(FSAdForcedMovieAdLoader *)adView adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)failedAdClickFSAdForcedMovie:(FSAdForcedMovieAdLoader *)adView adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdForcedMovie([adUnitId UTF8String]);
    }
}

- (void)hideAdViewFSAdForcedMovie:(FSAdForcedMovieAdLoader *)adView adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate* pDelegate = (fsadforcedmovie_plugin::CCAdForcedMovieAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->hideAdViewFSAdForcedMovie([adUnitId UTF8String]);
    }
}

@end


#pragma mark - CCAdForcedMovieAdLoader

USING_NS_CC;

NS_CC_ADFORCEDMOVIE_EXT_BEGIN;

CCAdForcedMovieAdLoader::CCAdForcedMovieAdLoader()
: _forcedmovieDelegate(nullptr)
{
    
}

CCAdForcedMovieAdLoader::~CCAdForcedMovieAdLoader()
{
    
}

CCAdForcedMovieAdLoader* CCAdForcedMovieAdLoader::create()
{
    CCAdForcedMovieAdLoader* view = new CCAdForcedMovieAdLoader();
    return view;
}

void CCAdForcedMovieAdLoader::initAd(const char *adUnitId)
{
    if (_forcedmovieDelegate) {
        [[CCFSAdForcedMovieAdLoader sharedInstance] setDelegate:_forcedmovieDelegate];
    }
    [[CCFSAdForcedMovieAdLoader sharedInstance] initAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdForcedMovieAdLoader::loadAd(const char *adUnitId)
{
    [[CCFSAdForcedMovieAdLoader sharedInstance] loadAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdForcedMovieAdLoader::createAd(const char *adUnitId)
{
    [[CCFSAdForcedMovieAdLoader sharedInstance] createAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdForcedMovieAdLoader::loadAndCreateAd(const char *adUnitId)
{
    [[CCFSAdForcedMovieAdLoader sharedInstance] loadAndCreateAdCorcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdForcedMovieAdLoader::showAd(const char *adUnitId)
{
    [[CCFSAdForcedMovieAdLoader sharedInstance] showAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdForcedMovieAdLoader::hideAd(const char *adUnitId)
{
    [[CCFSAdForcedMovieAdLoader sharedInstance] hideAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

bool CCAdForcedMovieAdLoader::isReadyAd(const char *adUnitId)
{
    return [[CCFSAdForcedMovieAdLoader sharedInstance] isReadyAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

bool CCAdForcedMovieAdLoader::isDisplayAd(const char *adUnitId)
{
    return [[CCFSAdForcedMovieAdLoader sharedInstance] isDisplayAdForcedMovie:[NSString stringWithUTF8String:adUnitId]];
}

NS_CC_ADFORCEDMOVIE_EXT_END;

#endif

