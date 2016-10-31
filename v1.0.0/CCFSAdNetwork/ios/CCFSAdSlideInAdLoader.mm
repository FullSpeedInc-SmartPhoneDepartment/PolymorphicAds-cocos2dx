//
//  CCFSAdSlideInAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#include "CCFSAdSlideInAdLoader.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdSlideInAdLoader.h>

#include "cocos2d.h"


#pragma mark - CCFSAdSlideInAdLoader NSObject

@interface CCFSAdSlideInAdLoader : NSObject <FSAdSlideInAdLoaderDelegate>
{
    void* object;
}

@end

@implementation CCFSAdSlideInAdLoader

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdSlideInAdLoader *loader = [[self alloc] init];
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
    [FSAdSlideInAdLoader sharedInstance].delegate = self;
    [[FSAdSlideInAdLoader sharedInstance] initAd:adUnitId intervalTime:0 skipCount:0 displayTime:6];
}

- (void)initAd:(NSString *)adUnitId intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount displayTime:(NSInteger)displayTime
{
    [FSAdSlideInAdLoader sharedInstance].delegate = self;
    [[FSAdSlideInAdLoader sharedInstance] initAd:adUnitId intervalTime:intervalTime skipCount:skipCount displayTime:displayTime];
}

- (void)loadAd:(NSString *)adUnitId
{
    [[FSAdSlideInAdLoader sharedInstance] loadAd:adUnitId];
}

- (void)showAd:(NSString *)adUnitId
{
    [[FSAdSlideInAdLoader sharedInstance] showAd:adUnitId];
}

- (void)hideAd
{
    [[FSAdSlideInAdLoader sharedInstance] hideAd];
}


#pragma mark - FSAdSlideInAdLoaderDelegate

- (void)finishInitAdFSAdSlideIn:(FSAdSlideInAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdSlideIn();
    }
}

- (void)failedInitAdFSAdSlideIn:(FSAdSlideInAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdSlideIn();
    }
}

- (void)failedSendAdRequestFSAdSlideIn:(FSAdSlideInAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdSlideIn();
    }
}

- (void)finishedResponseAdRequestFSAdSlideIn:(FSAdSlideInAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdSlideIn();
    }
}

- (void)failedResponseAdRequestFSAdSlideIn:(FSAdSlideInAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdSlideIn();
    }
}

- (void)emptyAdResponseAdRequestFSAdSlideIn:(FSAdSlideInAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdSlideIn();
    }
}

- (void)finishedAdCreateFSAdSlideIn:(FSAdSlideInAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdCreateFSAdSlideIn();
    }
}

- (void)failedAdCreateFSAdSlideIn:(FSAdSlideInAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdCreateFSAdSlideIn();
    }
}

- (void)finishedAdClickFSAdSlideIn:(FSAdSlideInAdLoader *)adView
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdSlideIn();
    }
}

- (void)failedAdClickFSAdSlideIn:(FSAdSlideInAdLoader *)adView error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdSlideIn();
    }
}

- (void)skipAdCreateFSAdSlideIn:(FSAdSlideInAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->skipAdCreateFSAdSlideIn();
    }
}

- (void)hideFSAdSlideIn:(FSAdSlideInAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadslidein_plugin::CCAdSlideInAdLoaderDelegate* pDelegate = (fsadslidein_plugin::CCAdSlideInAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->hideFSAdSlideIn();
    }
}

@end


#pragma mark - CCAdSlideInAdLoader

USING_NS_CC;

NS_CC_ADSLIDEIN_EXT_BEGIN;

CCAdSlideInAdLoader::CCAdSlideInAdLoader()
: _slideinAdDelegate(nullptr)
{
    
}

CCAdSlideInAdLoader::~CCAdSlideInAdLoader()
{
    
}

CCAdSlideInAdLoader* CCAdSlideInAdLoader::create()
{
    CCAdSlideInAdLoader* view = new CCAdSlideInAdLoader();
    return view;
}

void CCAdSlideInAdLoader::initAd(const char *adUnitId)
{
    if (_slideinAdDelegate != NULL) {
        [[CCFSAdSlideInAdLoader sharedInstance] setDelegate:_slideinAdDelegate];
    }
    [[CCFSAdSlideInAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdSlideInAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount, int displayTime)
{
    if (_slideinAdDelegate != NULL) {
        [[CCFSAdSlideInAdLoader sharedInstance] setDelegate:_slideinAdDelegate];
    }
    [[CCFSAdSlideInAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId] intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount displayTime:(NSInteger)displayTime];
}

void CCAdSlideInAdLoader::loadAd(const char *adUnitId)
{
    [[CCFSAdSlideInAdLoader sharedInstance] loadAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdSlideInAdLoader::showAd(const char *adUnitId)
{
    [[CCFSAdSlideInAdLoader sharedInstance] showAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdSlideInAdLoader::hideAd()
{
    [[CCFSAdSlideInAdLoader sharedInstance] hideAd];
}

NS_CC_ADSLIDEIN_EXT_END;

#endif  //CC_TARGET_PLATFORM == CC_PLATFORM_IOS
