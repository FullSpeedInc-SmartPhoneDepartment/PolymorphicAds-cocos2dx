//
//  CCFSAdPopupAdLoader.m
//  SampleApp
//
//  Created by RN-079 on 2016/06/01.
//
//

#include "CCFSAdPopupAdLoader.h"


#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdPopupAdLoader.h>

#include "cocos2d.h"


#pragma mark - CCFSAdPopupAdLoader NSObject

@interface CCFSAdPopupAdLoader : NSObject <FSAdPopupAdLoaderDelegate>
{
    void* object;
}

@end

@implementation CCFSAdPopupAdLoader

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdPopupAdLoader *loader = [[self alloc] init];
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
    [FSAdPopupAdLoader sharedInstance].delegate = self;
    [[FSAdPopupAdLoader sharedInstance] initAd:adUnitId intervalTime:0 skipCount:0];
}

- (void)initAd:(NSString *)adUnitId intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount
{
    [FSAdPopupAdLoader sharedInstance].delegate = self;
    [[FSAdPopupAdLoader sharedInstance] initAd:adUnitId intervalTime:intervalTime skipCount:skipCount];
}

- (void)loadAd:(NSString *)adUnitId
{
    [[FSAdPopupAdLoader sharedInstance] loadAd:adUnitId];
}

- (void)showAd:(NSString *)adUnitId
{
    [[FSAdPopupAdLoader sharedInstance] showAd:adUnitId];
}

- (void)hideAd
{
    [[FSAdPopupAdLoader sharedInstance] hideAd];
}


#pragma mark - FSAdPopupAdLoaderDelegate

- (void)finishInitAdFSAdPopup:(FSAdPopupAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdPopup();
    }
}

- (void)failedInitAdFSAdPopup:(FSAdPopupAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdPopup();
    }
}

- (void)failedSendAdRequestFSAdPopup:(FSAdPopupAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdPopup();
    }
}

- (void)finishedResponseAdRequestFSAdPopup:(FSAdPopupAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdPopup();
    }
}

- (void)failedResponseAdRequestFSAdPopup:(FSAdPopupAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdPopup();
    }
}

- (void)emptyAdResponseAdRequestFSAdPopup:(FSAdPopupAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdPopup();
    }
}

- (void)finishedAdCreateFSAdPopup:(FSAdPopupAdLoader *)sender
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdCreateFSAdPopup();
    }
}

- (void)failedAdCreateFSAdPopup:(FSAdPopupAdLoader *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdCreateFSAdPopup();
    }
}

- (void)finishedAdClickFSAdPopup:(FSAdPopupAdLoader *)adView
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdPopup();
    }
}

- (void)failedAdClickFSAdPopup:(FSAdPopupAdLoader *)adView error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdPopup();
    }
}

- (void)skipAdCreateFSAdPopup:(FSAdPopupAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->skipAdCreateFSAdPopup();
    }
}

- (void)hideFSAdPopup:(FSAdPopupAdLoader *)adLoader
{
    NSLog(@"%s", __func__);
    
    fsadpopup_plugin::CCAdPopupAdLoaderDelegate* pDelegate = (fsadpopup_plugin::CCAdPopupAdLoaderDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->hideFSAdPopup();
    }
}

@end



#pragma mark - CCAdPopupAdLoader

USING_NS_CC;

NS_CC_ADPOPUP_EXT_BEGIN;

CCAdPopupAdLoader::CCAdPopupAdLoader()
: _popupAdDelegate(nullptr)
{
    
}

CCAdPopupAdLoader::~CCAdPopupAdLoader()
{
    
}

CCAdPopupAdLoader* CCAdPopupAdLoader::create()
{
    CCAdPopupAdLoader* view = new CCAdPopupAdLoader();
    return view;
}

void CCAdPopupAdLoader::initAd(const char *adUnitId)
{
    if (_popupAdDelegate != NULL) {
        [[CCFSAdPopupAdLoader sharedInstance] setDelegate:_popupAdDelegate];
    }
    [[CCFSAdPopupAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPopupAdLoader::initAd(const char *adUnitId, int intervalTime, int skipCount)
{
    if (_popupAdDelegate != NULL) {
        [[CCFSAdPopupAdLoader sharedInstance] setDelegate:_popupAdDelegate];
    }
    [[CCFSAdPopupAdLoader sharedInstance] initAd:[NSString stringWithUTF8String:adUnitId] intervalTime:(NSInteger)intervalTime skipCount:(NSInteger)skipCount];
}

void CCAdPopupAdLoader::loadAd(const char *adUnitId)
{
    [[CCFSAdPopupAdLoader sharedInstance] loadAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPopupAdLoader::showAd(const char *adUnitId)
{
    [[CCFSAdPopupAdLoader sharedInstance] showAd:[NSString stringWithUTF8String:adUnitId]];
}

void CCAdPopupAdLoader::hideAd()
{
    [[CCFSAdPopupAdLoader sharedInstance] hideAd];
}

NS_CC_ADPOPUP_EXT_END;

#endif  //CC_TARGET_PLATFORM == CC_PLATFORM_IOS
