//
//  AdTwinPanelScene.cpp
//  CCSampleApp
//
//  Created by RN-079 on 2016/07/04.
//
//

#include "AdTwinPanelScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_FSADTWINPANELVIEW;

Scene* AdTwinPanelScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdTwinPanelScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdTwinPanelScene::init()
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
    auto label = Label::createWithSystemFont("Ad Double Banner Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdTwinPanelScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    auto menu = Menu::create(backButton, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "d8fd04e45351b930";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc1f956e089ce30a971";
#endif
    
    // バナー表示
    adBannerView = CCAdTwinPanelView::create();
    adBannerView->setDelegate(this);
    adBannerView->initAd(adUnitId, 0, winSize.height, 320, 50);
    
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

void AdTwinPanelScene::pushBtnBackScene(Ref* sender)
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

void AdTwinPanelScene::finishInitAdFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - finishInitAdFSAdTwinPanelView");
    
    adBannerView->loadAndShowAd();
    _labelStatus->setString("load");
}

void AdTwinPanelScene::failedInitAdFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - failedInitAdFSAdTwinPanelView");
    
    _labelStatus->setString("failed init");
}

void AdTwinPanelScene::failedSendAdRequestFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - failedSendAdRequestFSAdTwinPanelView");
    
    _labelStatus->setString("failed sendAd");
}

void AdTwinPanelScene::finishedResponseAdRequestFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - finishedResponseAdRequestFSAdTwinPanelView");
    
    _labelStatus->setString("show");
}

void AdTwinPanelScene::failedResponseAdRequestFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - failedResponseAdRequestFSAdTwinPanelView");
    
    _labelStatus->setString("ready show");
}

void AdTwinPanelScene::emptyAdResponseAdRequestFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - emptyAdResponseAdRequestFSAdTwinPanelView");
    
    _labelStatus->setString("empty ad");
}

void AdTwinPanelScene::finishedCreateFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - finishedCreateFSAdTwinPanelView");
    
    _labelStatus->setString("finish create");
}

void AdTwinPanelScene::failedCreateFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - failedCreateFSAdTwinPanelView");
    
    _labelStatus->setString("failed create");
}

void AdTwinPanelScene::finishedAdClickFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - finishedAdClickFSAdTwinPanelView");
    
    _labelStatus->setString("finish click ad");
}

void AdTwinPanelScene::failedAdClickFSAdTwinPanelView()
{
    CCLOG("AdTwinPanelScene - failedAdClickFSAdTwinPanelView");
    
    _labelStatus->setString("failed click ad");
}

