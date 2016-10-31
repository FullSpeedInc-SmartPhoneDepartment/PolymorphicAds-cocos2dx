//
//  CCFSAdAnalytics.m
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/20.
//
//

#include "CCFSAdAnalytics.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#import <FSAdAnalytics/FSAdAnalytics.h>
#import <FSAdAnalytics/FSAnalyticsOption.h>


static fsadanalytics_plugin::CCAdAnalyticsDelegate* pAnalyticsDelegate = nullptr;


@interface CCFSAdAnalytics : NSObject <FSAdAnalyticsDelegate>
{
    void* object;
}

@end

@implementation CCFSAdAnalytics

+ (instancetype)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CCFSAdAnalytics *loader = [[self alloc] init];
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

- (void)analyticsDebugLogEnable:(BOOL)enable
{
    [FSAnalyticsOption debugLogEnable:enable];
}

- (void)analyticsConversion:(NSString*)conversionId
{
    [FSAdAnalytics sharedInstance].delegate = self;
    [[FSAdAnalytics sharedInstance] conversion:conversionId];
}

- (void)finishedConversionFSAdAnalytics
{
    NSLog(@"%s", __func__);
    
    fsadanalytics_plugin::CCAdAnalyticsDelegate* pDelegate = (fsadanalytics_plugin::CCAdAnalyticsDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->finishedConversionFSAdAnalytics();
    }
}

- (void)failedConversionFSAdAnalytics
{
    NSLog(@"%s", __func__);
    
    fsadanalytics_plugin::CCAdAnalyticsDelegate* pDelegate = (fsadanalytics_plugin::CCAdAnalyticsDelegate*)object;
    if (pDelegate != NULL) {
        pDelegate->failedConversionFSAdAnalytics();
    }
}

@end


NS_CC_FSADANALYTICS_EXT_BEGIN;

void CCAdAnalytics::analyticsDebugLogEnable(bool enable)
{
    [[CCFSAdAnalytics sharedInstance] analyticsDebugLogEnable:enable];
}

void CCAdAnalytics::analyticsConversion(const char* conversionId)
{
    if (pAnalyticsDelegate != NULL) {
        [[CCFSAdAnalytics sharedInstance] setDelegate:pAnalyticsDelegate];
    }
    [[CCFSAdAnalytics sharedInstance] analyticsConversion:[NSString stringWithUTF8String:conversionId]];
}

void CCAdAnalytics::setDelegate(fsadanalytics_plugin::CCAdAnalyticsDelegate *pDelegate)
{
    pAnalyticsDelegate = pDelegate;
}

NS_CC_FSADANALYTICS_EXT_END;


#endif


