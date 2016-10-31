//
//  CCFSAdRectangleBannerView.m
//  CCSampleApp
//
//  Created by RN-079 on 2016/10/11.
//
//
#include "CCFSAdRectangleBannerView.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
#import <Foundation/Foundation.h>
#import <FSAdNetwork/FSAdRectangleBannerView.h>

#include "cocos2d.h"


#pragma mark - CCFSAdRectangleBannerView

@interface CCFSAdRectangleBannerView : NSObject <FSAdRectangleBannerViewDelegate>
{
    void* object;
}

@property (nonatomic, strong) FSAdRectangleBannerView* adView;

@end


@implementation CCFSAdRectangleBannerView

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdRectangleBannerView *loader = [[self alloc] init];
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
    self.adView = [[FSAdRectangleBannerView alloc] initWithFrame:CGRectMake(x, y, w, h)];
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


#pragma mark - FSAdRectangleBannerViewDelegate

- (void)finishInitAdFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishInitAdFSAdRectangleBannerView();
    }
}

- (void)failedInitAdFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedInitAdFSAdRectangleBannerView();
    }
}

- (void)failedSendAdRequestFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedSendAdRequestFSAdRectangleBannerView();
    }
}

- (void)finishedResponseAdRequestFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedResponseAdRequestFSAdRectangleBannerView();
    }
}

- (void)failedResponseAdRequestFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedResponseAdRequestFSAdRectangleBannerView();
    }
}

- (void)emptyAdResponseAdRequestFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->emptyAdResponseAdRequestFSAdRectangleBannerView();
    }
}

- (void)finishedCreateFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender
{
    NSLog(@"%s", __func__);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedCreateFSAdRectangleBannerView();
    }
}

- (void)failedCreateFSAdRectangleBannerView:(FSAdRectangleBannerView *)sender error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedCreateFSAdRectangleBannerView();
    }
}

- (void)finishedAdClickFSAdRectangleBannerView:(FSAdRectangleBannerView *)adView
{
    NSLog(@"%s", __func__);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedAdClickFSAdRectangleBannerView();
    }
}

- (void)failedAdClickFSAdRectangleBannerView:(FSAdRectangleBannerView *)adView error:(FSError *)error
{
    NSLog(@"%s %@", __func__, error.errorMessage);
    
    fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate* pDelegate = (fsadrectanglebannerview_plugin::CCAdRectangleBannerViewDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedAdClickFSAdRectangleBannerView();
    }
}

@end



#pragma mark - CCAdRectangleBannerView

USING_NS_CC;
NS_CC_FSADRECTANGLEBANNERVIEW_EXT_BEGIN;

CCAdRectangleBannerView::CCAdRectangleBannerView()
: _bannerViewDelegate(nullptr)
{
    
}

CCAdRectangleBannerView::~CCAdRectangleBannerView()
{
    
}

CCAdRectangleBannerView* CCAdRectangleBannerView::create()
{
    CCAdRectangleBannerView* view = new CCAdRectangleBannerView();
    return view;
}

void CCAdRectangleBannerView::initAd(const char *adUnitId, int x, int y, int w, int h)
{
    if (_bannerViewDelegate != NULL) {
        [[CCFSAdRectangleBannerView sharedInstance] setDelegate:_bannerViewDelegate];
    }
    [[CCFSAdRectangleBannerView sharedInstance] initAdBanner:[NSString stringWithUTF8String:adUnitId] x:x y:y w:w h:h];
    
    UIView* adBannerView = [[CCFSAdRectangleBannerView sharedInstance] GetAdBiew];
    UIView* rootView = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    [rootView addSubview:adBannerView];
}

void CCAdRectangleBannerView::hideAd()
{
    [[CCFSAdRectangleBannerView sharedInstance] hideAdBanner];
}

void CCAdRectangleBannerView::loadAndShowAd()
{
    [[CCFSAdRectangleBannerView sharedInstance] loadAdBanner];
}

void CCAdRectangleBannerView::pause()
{
    [[CCFSAdRectangleBannerView sharedInstance] pauseAdBanner];
}

void CCAdRectangleBannerView::resume()
{
    [[CCFSAdRectangleBannerView sharedInstance] resumeAdBanner];
}

void CCAdRectangleBannerView::setRectAd(int x, int y, int w, int h)
{
    [[CCFSAdRectangleBannerView sharedInstance] setRectAdBanner:x y:y w:w h:h];
}

NS_CC_FSADRECTANGLEBANNERVIEW_EXT_END;


#endif

