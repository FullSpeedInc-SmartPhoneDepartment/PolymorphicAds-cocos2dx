//
//  CCFSAdDoubleBannerView.m
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#include "CCFSAdDoubleBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdDoubleBannerView.h>

#include "cocos2d.h"


#pragma mark - CCFSAdDoubleBannerView

@interface CCFSAdDoubleBannerView : NSObject <FSAdDoubleBannerViewDelegate>
{
    void* object;
}

@property (nonatomic, strong) FSAdDoubleBannerView* adView;

@end

@implementation CCFSAdDoubleBannerView

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdDoubleBannerView *loader = [[self alloc] init];
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

- (UIView*)GetAdBiew
{
    return self.adView;
}

- (void)hideAdBanner
{
    if (self.adView) {
        self.adView.delegate = nil;
        [self.adView removeFromSuperview];
        self.adView = nil;
    }
}

- (void)initAdBanner:(NSString*)adUnitId x:(int)x y:(int)y w:(int)w h:(int)h
{
    self.adView = [[FSAdDoubleBannerView alloc] initWithFrame:CGRectMake(x, y, w, h)];
    self.adView.delegate = self;
    [self.adView initAd:adUnitId];
}

- (void)loadAdBanner
{
    [self.adView loadAd];
}

- (void)pauseAdBanner
{
    [self.adView pause];
}

- (void)resumeAdBanner
{
    [self.adView resume];
}

- (void)setRectAdBanner:(int)x y:(int)y w:(int)w h:(int)h
{
    self.adView.frame = CGRectMake(x, y, w, h);
}

#pragma mark - FSAdDoubleBannerViewDelegate

/**
 initialization finished successfully
 */
- (void)finishInitAdFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdDoubleBannerView();
    }
}

/**
 failed to initalize ad unit
 */
- (void)failedInitAdFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdDoubleBannerView();
    }
}

/**
 failed for send ad request
 */
- (void)failedSendAdRequestFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdDoubleBannerView();
    }
}

/**
 received ad response successfully
 */
- (void)finishedResponseAdRequestFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdDoubleBannerView();
    }
}

/**
 failed to receive ad response
 */
- (void)failedResponseAdRequestFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdDoubleBannerView();
    }
}

/**
 ad response was empty
 */
- (void)emptyAdResponseAdRequestFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdDoubleBannerView();
    }
}

/**
 finished to create ad view successfully
 */
- (void)finishedCreateFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdDoubleBannerView();
    }
}

/**
 failed to create ad view
 */
- (void)failedCreateFSAdDoubleBannerView:(FSAdDoubleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdDoubleBannerView();
    }
}

/**
 succeeded to send ad click
 */
- (void)finishedAdClickFSAdDoubleBannerView:(FSAdDoubleBannerView *)adView
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdDoubleBannerView();
    }
}

/**
 failed to send ad click
 */
- (void)failedAdClickFSAdDoubleBannerView:(FSAdDoubleBannerView *)adView error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate* pDelegate = (fsaddoublebannerview_plugin::CCAdDoubleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdDoubleBannerView();
    }
}

@end


#pragma mark - CCAdDoubleBannerView

USING_NS_CC;
USING_NS_CC_FSADDOUBLEBANNERVIEW;

CCAdDoubleBannerView::CCAdDoubleBannerView()
: _WbannerViewDelegate(nullptr)
{
    
}

CCAdDoubleBannerView::~CCAdDoubleBannerView()
{
    
}

CCAdDoubleBannerView* CCAdDoubleBannerView::create()
{
    CCAdDoubleBannerView* view = new CCAdDoubleBannerView();
    return view;
}

void CCAdDoubleBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    if (_WbannerViewDelegate != NULL) {
        [[CCFSAdDoubleBannerView sharedInstance] setDelegate:_WbannerViewDelegate];
    }
    [[CCFSAdDoubleBannerView sharedInstance] initAdBanner:[NSString stringWithUTF8String:adUnitId] x:x y:y w:w h:h];
    
    UIView* adBannerView = [[CCFSAdDoubleBannerView sharedInstance] GetAdBiew];
    UIView* rootView = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    [rootView addSubview:adBannerView];
}

void CCAdDoubleBannerView::hideAd()
{
    [[CCFSAdDoubleBannerView sharedInstance] hideAdBanner];
}

void CCAdDoubleBannerView::loadAndShowAd()
{
    [[CCFSAdDoubleBannerView sharedInstance] loadAdBanner];
}

void CCAdDoubleBannerView::pause()
{
    [[CCFSAdDoubleBannerView sharedInstance] pauseAdBanner];
}

void CCAdDoubleBannerView::resume()
{
    [[CCFSAdDoubleBannerView sharedInstance] resumeAdBanner];
}

void CCAdDoubleBannerView::setRectAd(int x, int y, int w, int h)
{
    [[CCFSAdDoubleBannerView sharedInstance] setRectAdBanner:x y:y w:w h:h];
}

#endif