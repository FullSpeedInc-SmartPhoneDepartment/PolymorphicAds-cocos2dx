//
//  CCFSAdOption.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/23.
//
//

#define USING_NS_CC_FSADOPTION           using namespace fsadoption_plugin
#define NS_CC_FSADOPTION_EXT_BEGIN       namespace fsadoption_plugin {
#define NS_CC_FSADOPTION_EXT_END         }


NS_CC_FSADOPTION_EXT_BEGIN;

class CCFSAdOption
{
public:
    static void debugLogEnable(bool enable);
    static void testModeEnable(bool enable);
};


NS_CC_FSADOPTION_EXT_END;

