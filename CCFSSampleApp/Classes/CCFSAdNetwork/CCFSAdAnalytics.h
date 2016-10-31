//
//  CCFSAdAnalytics.h
//  CCSampleApp
//
//  Created by RN-079 on 2016/06/20.
//
//

#define USING_NS_CC_FSADANALYTICS           using namespace fsadanalytics_plugin
#define NS_CC_FSADANALYTICS_EXT_BEGIN       namespace fsadanalytics_plugin {
#define NS_CC_FSADANALYTICS_EXT_END         }


NS_CC_FSADANALYTICS_EXT_BEGIN;

//////////////
// delegate //
//////////////
class CCAdAnalyticsDelegate
{
public:
    virtual void finishedConversionFSAdAnalytics() {};
    virtual void failedConversionFSAdAnalytics() {};
};


class CCAdAnalytics
{
public:
    static void analyticsDebugLogEnable(bool enable);
    static void analyticsConversion(const char* conversionId);
    static void setDelegate(CCAdAnalyticsDelegate* pDelegate);
};


NS_CC_FSADANALYTICS_EXT_END;

