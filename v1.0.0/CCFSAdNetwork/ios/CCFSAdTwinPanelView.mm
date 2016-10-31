//
//  CCFSAdTwinPanelView.m
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#include "CCFSAdTwinPanelView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdTwinPanelView.h>

#include "cocos2d.h"


#pragma mark - CCFSAdTwinPanelView

@interface CCFSAdTwinPanelView : NSObject <FSAdTwinPanelViewDelegate>
{
    void* object;
}

@property (nonatomic, strong) FSAdTwinPanelView* adView;

@end

@implementation CCFSAdTwinPanelView

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdTwinPanelView *loader = [[self alloc] init];
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
    self.adView = [[FSAdTwinPanelView alloc] initWithFrame:CGRectMake(x, y, w, h)];
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


#pragma mark - FSAdTwinPanelViewDelegate

/**
 initialization finished successfully
 */
- (void)finishInitAdFSAdTwinPanelView:(FSAdTwinPanelView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdTwinPanelView();
    }
}

/**
 failed to initalize ad unit
 */
- (void)failedInitAdFSAdTwinPanelView:(FSAdTwinPanelView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdTwinPanelView();
    }
}

/**
 failed for send ad request
 */
- (void)failedSendAdRequestFSAdTwinPanelView:(FSAdTwinPanelView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdTwinPanelView();
    }
}

/**
 received ad response successfully
 */
- (void)finishedResponseAdRequestFSAdTwinPanelView:(FSAdTwinPanelView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdTwinPanelView();
    }
}

/**
 failed to receive ad response
 */
- (void)failedResponseAdRequestFSAdTwinPanelView:(FSAdTwinPanelView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdTwinPanelView();
    }
}

/**
 ad response was empty
 */
- (void)emptyAdResponseAdRequestFSAdTwinPanelView:(FSAdTwinPanelView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdTwinPanelView();
    }
}

/**
 finished to create ad view successfully
 */
- (void)finishedCreateFSAdTwinPanelView:(FSAdTwinPanelView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdTwinPanelView();
    }
}

/**
 failed to create ad view
 */
- (void)failedCreateFSAdTwinPanelView:(FSAdTwinPanelView *)sender error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdTwinPanelView();
    }
}

/**
 succeeded to send ad click
 */
- (void)finishedAdClickFSAdTwinPanelView:(FSAdTwinPanelView *)adView
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdTwinPanelView();
    }
}

/**
 failed to send ad click
 */
- (void)failedAdClickFSAdTwinPanelView:(FSAdTwinPanelView *)adView error:(FSError *)error
{
    NSLog(@"%s", __func__);
    
    fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate* pDelegate = (fsadtwinpanelview_plugin::CCAdTwinPanelViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdTwinPanelView();
    }
}

@end


#pragma mark - CCAdTwinPanelView

USING_NS_CC;
USING_NS_CC_FSADTWINPANELVIEW;

CCAdTwinPanelView::CCAdTwinPanelView()
: _twinPanelViewDelegate(nullptr)
{
    
}

CCAdTwinPanelView::~CCAdTwinPanelView()
{
    
}

CCAdTwinPanelView* CCAdTwinPanelView::create()
{
    CCAdTwinPanelView* view = new CCAdTwinPanelView();
    return view;
}

void CCAdTwinPanelView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    if (_twinPanelViewDelegate != NULL) {
        [[CCFSAdTwinPanelView sharedInstance] setDelegate:_twinPanelViewDelegate];
    }
    [[CCFSAdTwinPanelView sharedInstance] initAdBanner:[NSString stringWithUTF8String:adUnitId] x:x y:y w:w h:h];
    
    UIView* adBannerView = [[CCFSAdTwinPanelView sharedInstance] GetAdBiew];
    UIView* rootView = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    [rootView addSubview:adBannerView];
}

void CCAdTwinPanelView::hideAd()
{
    [[CCFSAdTwinPanelView sharedInstance] hideAdBanner];
}

void CCAdTwinPanelView::loadAndShowAd()
{
    [[CCFSAdTwinPanelView sharedInstance] loadAdBanner];
}

void CCAdTwinPanelView::pause()
{
    [[CCFSAdTwinPanelView sharedInstance] pauseAdBanner];
}

void CCAdTwinPanelView::resume()
{
    [[CCFSAdTwinPanelView sharedInstance] resumeAdBanner];
}

void CCAdTwinPanelView::setRectAd(int x, int y, int w, int h)
{
    [[CCFSAdTwinPanelView sharedInstance] setRectAdBanner:x y:y w:w h:h];
}

#endif