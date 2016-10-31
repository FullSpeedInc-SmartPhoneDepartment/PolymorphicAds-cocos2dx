//
//  CCFSAdPiPAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/02.
//
//

#include "CCFSAdPiPAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#include "cocos2d.h"

#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdPiPAdLoader.h>


#pragma mark - CCFSAdPiPAdLoader

@interface CCFSAdPiPAdLoader : NSObject <FSAdPiPAdLoaderDelegate>
{
    void* object;
}

@end

@implementation CCFSAdPiPAdLoader

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdPiPAdLoader *loader = [[self alloc] init];
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

- (void)initAdPiP:(NSString*)adUnitId
{
    [FSAdPiPAdLoader sharedInstance].delegate = self;
    [[FSAdPiPAdLoader sharedInstance] initAd:adUnitId];
}

- (void)loadAndCreateAdPiP:(NSString*)adUnitId
{
    [[FSAdPiPAdLoader sharedInstance] loadAndCreateAd:adUnitId];
}

- (void)loadAdPiP:(NSString*)adUnitId
{
    [[FSAdPiPAdLoader sharedInstance] loadAd:adUnitId];
}

- (void)createAdPiP:(NSString*)adUnitId
{
    [[FSAdPiPAdLoader sharedInstance] createAd:adUnitId];
}

- (void)showAdPiP:(NSString*)adUnitId
{
    [[FSAdPiPAdLoader sharedInstance] showAd:adUnitId];
}

- (void)showAdPip:(NSString*)adUnitId position:(int)position
{
    [[FSAdPiPAdLoader sharedInstance] showAd:adUnitId position:(FSAdPiPPositionType)position];
}

- (void)hideAdPiP:(NSString*)adUnitId
{
    [[FSAdPiPAdLoader sharedInstance] hideAd:adUnitId];
}

- (BOOL)isReadyAdPiP:(NSString*)adUnitId
{
    return [[FSAdPiPAdLoader sharedInstance] isReadyAd:adUnitId];
}

- (BOOL)isDisplayAdPiP:(NSString*)adUnitId
{
    return [[FSAdPiPAdLoader sharedInstance] isDisplayAd:adUnitId];
}


#pragma mark - FSAdPiPAdLoaderDelegate

- (void)finishInitAdFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedInitAdFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedSendAdRequestFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)finishedResponseAdRequestFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedResponseAdRequestFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)emptyAdResponseAdRequestFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)finishedReadyMovieFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedReadyMovieFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedReadyMovieFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedReadyMovieFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)finishedCreateFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedCreateFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)completedMovieFSAdPiP:(FSAdPiPAdLoader *)sender adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->completedMovieFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)finishedAdClickFSAdPiP:(FSAdPiPAdLoader *)adView adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)failedAdClickFSAdPiP:(FSAdPiPAdLoader *)adView adUnitId:(NSString *)adUnitId error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)hideAdViewFSAdPiP:(FSAdPiPAdLoader *)adView adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->hideAdViewFSAdPiP([adUnitId UTF8String]);
    }
}

- (void)expandedAdViewFSAdPiP:(FSAdPiPAdLoader *)adView adUnitId:(NSString *)adUnitId
{
    NSLog(@"%s", __func__);
    
    fsadpiploader_plugin::CCAdPiPAdLoaderDelegate* pDelegate = (fsadpiploader_plugin::CCAdPiPAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->expandedAdViewFSAdPiP([adUnitId UTF8String]);
    }
}

@end


#pragma mark - CCAdPiPAdLoader

USING_NS_CC;

NS_CC_ADPIPLOADER_EXT_BEGIN;

CCAdPiPAdLoader::CCAdPiPAdLoader()
: _pipadloaderDelegate(nullptr)
{
    
}

CCAdPiPAdLoader::~CCAdPiPAdLoader()
{
    
}

CCAdPiPAdLoader* CCAdPiPAdLoader::create()
{
    CCAdPiPAdLoader* view = new CCAdPiPAdLoader();
    return view;
}

void CCAdPiPAdLoader::initAd(const char *adUnitId)
{
    if (_pipadloaderDelegate) {
        [[CCFSAdPiPAdLoader sharedInstance] setDelegate:_pipadloaderDelegate];
    }
    [[CCFSAdPiPAdLoader sharedInstance] initAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPiPAdLoader::loadAd(const char *adUnitId)
{
    [[CCFSAdPiPAdLoader sharedInstance] loadAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPiPAdLoader::createAd(const char *adUnitId)
{
    [[CCFSAdPiPAdLoader sharedInstance] createAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPiPAdLoader::loadAndCreateAd(const char *adUnitId)
{
    [[CCFSAdPiPAdLoader sharedInstance] loadAndCreateAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPiPAdLoader::showAd(const char *adUnitId)
{
    [[CCFSAdPiPAdLoader sharedInstance] showAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPiPAdLoader::showAd(const char *adUnitId, CCAdPipPositionType position)
{
    [[CCFSAdPiPAdLoader sharedInstance] showAdPip:[NSString stringWithUTF8String:adUnitId] position:(int)position];
}

void CCAdPiPAdLoader::hideAd(const char *adUnitId)
{
    [[CCFSAdPiPAdLoader sharedInstance] hideAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

bool CCAdPiPAdLoader::isReadyAd(const char *adUnitId)
{
    return [[CCFSAdPiPAdLoader sharedInstance] isReadyAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

bool CCAdPiPAdLoader::isDisplayAd(const char *adUnitId)
{
    return [[CCFSAdPiPAdLoader sharedInstance] isDisplayAdPiP:[NSString stringWithUTF8String:adUnitId]];
}

NS_CC_ADPIPLOADER_EXT_END;

#endif
