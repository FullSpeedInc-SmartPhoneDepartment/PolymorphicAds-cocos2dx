//
//  CCFSAdInterstitialAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//
#include "CCFSAdInterstitialAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdInterstitialAdLoader.h>

#include "cocos2d.h"


#pragma mark - CCFSAdInterstitialAdLoader NSObject

@interface CCFSAdInterstitialAdLoader : NSObject <FSAdInterstitialAdLoaderDelegate>
{
    void* object;
}

@end


@implementation CCFSAdInterstitialAdLoader

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdInterstitialAdLoader *loader = [[self alloc] init];
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

- (void)initAd:(NSString*)adUnitId
{
    [FSAdInterstitialAdLoader sharedInstance].delegate = self;
    [[FSAdInterstitialAdLoader sharedInstance] initAd:adUnitId intervalTime:0 skipCount:0];
}

- (void)initAd:(NSString *)adUnitId intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount
{
    [FSAdInterstitialAdLoader sharedInstance].delegate = self;
    [[FSAdInterstitialAdLoader sharedInstance] initAd:adUnitId intervalTime:intervalTime skipCount:skipCount];
}

- (void)loadAd:(NSString *)adUnitId
{
    [[FSAdInterstitialAdLoader sharedInstance] loadAd:adUnitId];
}

- (void)showAd:(NSString *)adUnitId
{
    [[FSAdInterstitialAdLoader sharedInstance] showAd:adUnitId];
}

- (void)hideAd
{
    [[FSAdInterstitialAdLoader sharedInstance] hideAd];
}

- (BOOL)isReadyAd:(NSString *)adUnitId
{
    return [[FSAdInterstitialAdLoader sharedInstance] isReadyAd:adUnitId];
}


#pragma mark - FSAdInterstitialAdLoaderDelegate

/**
 initialization finished successfully
 */
- (void)finishInitAdFSAdInterstitial:(FSAdInterstitialAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdInterstitial();
    }
}

/**
 initialization failed
 */
- (void)failedInitAdFSAdInterstitial:(FSAdInterstitialAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdInterstitial();
    }
}

/**
 failed to send ad request
 */
- (void)failedSendAdRequestFSAdInterstitial:(FSAdInterstitialAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdInterstitial();
    }
}

/**
 received ad response successfully
 */
- (void)finishedResponseAdRequestFSAdInterstitial:(FSAdInterstitialAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdInterstitial();
    }
}

/**
 failed to receive ad response
 */
- (void)failedResponseAdRequestFSAdInterstitial:(FSAdInterstitialAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdInterstitial();
    }
}

/**
 ad response was empty
 */
- (void)emptyAdResponseAdRequestFSAdInterstitial:(FSAdInterstitialAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdInterstitial();
    }
}

/**
 finished to create ad view successfully
 */
- (void)finishedAdCreateFSAdInterstitial:(FSAdInterstitialAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdCreateFSAdInterstitial();
    }
}

/**
 failed to create ad view
 */
- (void)failedAdCreateFSAdInterstitial:(FSAdInterstitialAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdCreateFSAdInterstitial();
    }
}

/**
 succeeded to send ad click
 */
- (void)finishedAdClickFSAdInterstitial:(FSAdInterstitialAdLoader *)adView
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdInterstitial();
    }
}

/**
 failed to send ad click
 */
- (void)failedAdClickFSAdInterstitial:(FSAdInterstitialAdLoader *)adView error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdInterstitial();
    }
}

/**
 skipped create ad view
 */
- (void)skipAdCreateFSAdInterstitial:(FSAdInterstitialAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->skipAdCreateFSAdInterstitial();
    }
}

/**
 hidden ad view
 */
- (void)hideFSAdInterstitial:(FSAdInterstitialAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate* pDelegate = (fsadinterstitial_plugin::CCAdInterstitialAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->hideFSAdInterstitial();
    }
}

@end


#pragma mark - CCAdInterstitialAdLoader

USING_NS_CC;
NS_CC_ADINTERSTITIAL_EXT_BEGIN;

CCAdInterstitialAdLoader::CCAdInterstitialAdLoader()
: _interstitialAdDelegate(nullptr)
{
    
}

CCAdInterstitialAdLoader::~CCAdInterstitialAdLoader()
{
    
}

CCAdInterstitialAdLoader* CCAdInterstitialAdLoader::create()
{
    CCAdInterstitialAdLoader* view = new CCAdInterstitialAdLoader();
    return view;
}

void CCAdInterstitialAdLoader::initAd(const char *adUnitId)
{
    if (_interstitialAdDelegate != NULL) {
        [[CCFSAdInterstitialAdLoader sharedInstance] setDelegate:_interstitialAdDelegate];
    }
    [[CCFSAdInterstitialAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdInterstitialAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount)
{
    if (_interstitialAdDelegate != NULL) {
        [[CCFSAdInterstitialAdLoader sharedInstance] setDelegate:_interstitialAdDelegate];
    }
    [[CCFSAdInterstitialAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId] intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount];
}

void CCAdInterstitialAdLoader::loadAd(const char *adUnitId)
{
    [[CCFSAdInterstitialAdLoader sharedInstance] loadAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdInterstitialAdLoader::showAd(const char *adUnitId)
{
    [[CCFSAdInterstitialAdLoader sharedInstance] showAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdInterstitialAdLoader::hideAd()
{
    [[CCFSAdInterstitialAdLoader sharedInstance] hideAd];
}

bool CCAdInterstitialAdLoader::isReadyAd(const char *adUnitId)
{
    return [[CCFSAdInterstitialAdLoader sharedInstance] isReadyAd:[NSString stringWithUTF8String:adUnitId]];
}

NS_CC_ADINTERSTITIAL_EXT_END;

#endif

