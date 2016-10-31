//
//  AdRectangleBannerScene.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/10/14.
//
//

#include "AdRectangleBannerScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_FSADRECTANGLEBANNERVIEW;


Scene* AdRectangleBannerScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdRectangleBannerScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdRectangleBannerScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    //画面サイズを取得
    Size winSize = Director::getInstance()->getWinSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto background = LayerColor::create(Color4B::WHITE, winSize.width, winSize.height);
    this->addChild(background, 0);
    
    auto header = LayerColor::create(Color4B(240, 240, 240, 255), winSize.width, 44);
    header->setPosition(Point(0, winSize.height - header->getContentSize().height));
    this->addChild(header, 0);
    
    //
    auto label = Label::createWithSystemFont("Ad RectangleBanner Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.7));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdRectangleBannerScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    auto menu = Menu::create(backButton, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "4173d2df883041d0";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "d53b605de1198219f09f3a23b3272e0e";
#endif
    
    // バナー表示
    adBannerView = CCAdRectangleBannerView::create();
    adBannerView->setDelegate(this);
    adBannerView->initAd(adUnitId, 0, winSize.height - 200, 300, 250);
    
    _labelStatus->setString("init");
    
    // フォアグラウンド時のイベント
    auto foreground_listener = EventListenerCustom::create("EVENT_COME_TO_FOREGROUND_ROGUE", [this](EventCustom* event){
        adBannerView->resume();
    });
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(foreground_listener, this);
    // バックグラウンド時のイベント
    auto background_listener = EventListenerCustom::create("EVENT_COME_TO_BACKGROUND_ROGUE", [this](EventCustom* event){
        adBannerView->pause();
    });
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(background_listener, this);
    
    return true;
}

void AdRectangleBannerScene::pushBtnBackScene(Ref* sender)
{
    // バナー非表示
    adBannerView->hideAd();
    
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}


#pragma mark -

void AdRectangleBannerScene::finishInitAdFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - finishInitAdFSRectangleBannerView");
    
    adBannerView->loadAndShowAd();
    _labelStatus->setString("load");
}

void AdRectangleBannerScene::failedInitAdFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - failedInitAdFSAdRectangleBannerView");
    
    _labelStatus->setString("failed init");
}

void AdRectangleBannerScene::failedSendAdRequestFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - failedSendAdRequestFSAdRectangleBannerView");
    
    _labelStatus->setString("failed sendAd");
}

void AdRectangleBannerScene::finishedResponseAdRequestFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - finishedResponseAdRequestFSAdRectangleBannerView");
    
    _labelStatus->setString("show");
}

void AdRectangleBannerScene::failedResponseAdRequestFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - failedResponseAdRequestFSAdRectangleBannerView");
    
    _labelStatus->setString("ready show");
}

void AdRectangleBannerScene::emptyAdResponseAdRequestFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - emptyAdResponseAdRequestFSAdRectangleBannerView");
    
    _labelStatus->setString("empty ad");
}

void AdRectangleBannerScene::finishedCreateFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - finishedCreateFSAdRectangleBannerView");
    
    _labelStatus->setString("finish create");
}

void AdRectangleBannerScene::failedCreateFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - failedCreateFSAdRectangleBannerView");
    
    _labelStatus->setString("failed create");
}

void AdRectangleBannerScene::finishedAdClickFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - finishedAdClickFSAdRectangleBannerView");
    
    _labelStatus->setString("finish click ad");
}

void AdRectangleBannerScene::failedAdClickFSAdRectangleBannerView()
{
    CCLOG("AdRectangleBannerScene - failedAdClickFSAdRectangleBannerView");
    
    _labelStatus->setString("failed click ad");
}


