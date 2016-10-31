//
//  CCFSAdBannerView.m
//  SampleApp
//
//  Created by RN-079 on 2016/05/31.
//
//
#include "CCFSAdBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdBannerView.h>

#include "cocos2d.h"


#pragma mark - CCFSAdBannerView

@interface CCFSAdBannerView : NSObject <FSAdBannerViewDelegate>
{
    void* object;
}

@property (nonatomic, strong) FSAdBannerView* adView;

@end


@implementation CCFSAdBannerView

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdBannerView *loader = [[self alloc] init];
        sharedInstance = loader;
    });
    return sharedInstance;
}

- (id)init
{
    self = [super init];
    if (self) {
        //        [self.adView initAd:AdBannerAdUnitId];
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
    self.adView = [[FSAdBannerView alloc] initWithFrame:CGRectMake(x, y, w, h)];
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


#pragma mark - FSAdBannerViewDelegate

- (void)finishInitAdFSAdBannerView:(FSAdBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdBannerView();
    }
}

- (void)failedInitAdFSAdBannerView:(FSAdBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdBannerView();
    }
}

- (void)failedSendAdRequestFSAdBannerView:(FSAdBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdBannerView();
    }
}

- (void)finishedResponseAdRequestFSAdBannerView:(FSAdBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdBannerView();
    }
}

- (void)failedResponseAdRequestFSAdBannerView:(FSAdBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdBannerView();
    }
}

- (void)emptyAdResponseAdRequestFSAdBannerView:(FSAdBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdBannerView();
    }
}

- (void)finishedCreateFSAdBannerView:(FSAdBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdBannerView();
    }
}

- (void)failedCreateFSAdBannerView:(FSAdBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdBannerView();
    }
}

- (void)finishedAdClickFSAdBannerView:(FSAdBannerView *)adView
{
    NSLog(@"%s", __func__);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdBannerView();
    }
}

- (void)failedAdClickFSAdBannerView:(FSAdBannerView *)adView error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadbannerview_plugin::CCAdBannerViewDelegate* pDelegate = (fsadbannerview_plugin::CCAdBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdBannerView();
    }
}

@end



#pragma mark - CCAdBannerView

USING_NS_CC;
NS_CC_FSADBANNERVIEW_EXT_BEGIN;

CCAdBannerView::CCAdBannerView()
: _bannerViewDelegate(nullptr)
{
    
}

CCAdBannerView::~CCAdBannerView()
{
    
}

CCAdBannerView* CCAdBannerView::create()
{
    CCAdBannerView* view = new CCAdBannerView();
    return view;
}

void CCAdBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    if (_bannerViewDelegate != NULL) {
        [[CCFSAdBannerView sharedInstance] setDelegate:_bannerViewDelegate];
    }
    [[CCFSAdBannerView sharedInstance] initAdBanner:[NSString stringWithUTF8String:adUnitId] x:x y:y w:w h:h];
    
    UIView* adBannerView = [[CCFSAdBannerView sharedInstance] GetAdBiew];
    UIView* rootView = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    [rootView addSubview:adBannerView];
}

void CCAdBannerView::hideAd()
{
    [[CCFSAdBannerView sharedInstance] hideAdBanner];
}

void CCAdBannerView::loadAndShowAd()
{
    [[CCFSAdBannerView sharedInstance] loadAdBanner];
}

void CCAdBannerView::pause()
{
    [[CCFSAdBannerView sharedInstance] pauseAdBanner];
}

void CCAdBannerView::resume()
{
    [[CCFSAdBannerView sharedInstance] resumeAdBanner];
}

void CCAdBannerView::setRectAd(int x, int y, int w, int h)
{
    [[CCFSAdBannerView sharedInstance] setRectAdBanner:x y:y w:w h:h];
}

NS_CC_FSADBANNERVIEW_EXT_END;


#endif

