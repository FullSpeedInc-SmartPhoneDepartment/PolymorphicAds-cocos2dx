//
//  CCFSAdOption.m
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/23.
//
//

#include "CCFSAdOption.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS

#import <FSAdNetwork/FSAdOption.h>


NS_CC_FSADOPTION_EXT_BEGIN;

void CCFSAdOption::debugLogEnable(bool enable)
{
    // ad unit log enabled
    [FSAdOption debugLogEnable:enable];
}

void CCFSAdOption::testModeEnable(bool enable)
{
    // test mode enabled
    [FSAdOption testModeEnable:enable];
}

NS_CC_FSADOPTION_EXT_END;



#endif
