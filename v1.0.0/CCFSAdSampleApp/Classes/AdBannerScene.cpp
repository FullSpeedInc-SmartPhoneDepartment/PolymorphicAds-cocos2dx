//
//  AdBannerScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdBannerScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_FSADBANNERVIEW;


Scene* AdBannerScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdBannerScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdBannerScene::init()
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
    auto label = Label::createWithSystemFont("Ad Banner Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdBannerScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    auto menu = Menu::create(backButton, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "3f48888f7b64ce90";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc1dfb675ce57ffbaa2";
#endif
    
    // バナー表示
    adBannerView = CCAdBannerView::create();
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

void AdBannerScene::pushBtnBackScene(Ref* sender)
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

void AdBannerScene::finishInitAdFSAdBannerView()
{
    CCLOG("ADBannerScene - finishInitAdFSBannerView");
    
    adBannerView->loadAndShowAd();
    _labelStatus->setString("load");
}

void AdBannerScene::failedInitAdFSAdBannerView()
{
    CCLOG("ADBannerScene - failedInitAdFSAdBannerView");
    
    _labelStatus->setString("failed init");
}

void AdBannerScene::failedSendAdRequestFSAdBannerView()
{
    CCLOG("ADBannerScene - failedSendAdRequestFSAdBannerView");
    
    _labelStatus->setString("failed sendAd");
}

void AdBannerScene::finishedResponseAdRequestFSAdBannerView()
{
    CCLOG("ADBannerScene - finishedResponseAdRequestFSAdBannerView");
    
    _labelStatus->setString("show");
}

void AdBannerScene::failedResponseAdRequestFSAdBannerView()
{
    CCLOG("ADBannerScene - failedResponseAdRequestFSAdBannerView");
    
    _labelStatus->setString("ready show");
}

void AdBannerScene::emptyAdResponseAdRequestFSAdBannerView()
{
    CCLOG("ADBannerScene - emptyAdResponseAdRequestFSAdBannerView");
    
    _labelStatus->setString("empty ad");
}

void AdBannerScene::finishedCreateFSAdBannerView()
{
    CCLOG("ADBannerScene - finishedCreateFSAdBannerView");
    
    _labelStatus->setString("finish create");
}

void AdBannerScene::failedCreateFSAdBannerView()
{
    CCLOG("ADBannerScene - failedCreateFSAdBannerView");
    
    _labelStatus->setString("failed create");
}

void AdBannerScene::finishedAdClickFSAdBannerView()
{
    CCLOG("ADBannerScene - finishedAdClickFSAdBannerView");
    
    _labelStatus->setString("finish click ad");
}

void AdBannerScene::failedAdClickFSAdBannerView()
{
    CCLOG("ADBannerScene - failedAdClickFSAdBannerView");
    
    _labelStatus->setString("failed click ad");
}

