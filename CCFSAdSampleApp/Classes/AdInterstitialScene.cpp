//
//  AdInterstitialScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdInterstitialScene.h"
#include "HelloWorldScene.h"
#include <ui/CocosGUI.h>

USING_NS_CC;
using namespace ui;


Scene* AdInterstitialScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdInterstitialScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdInterstitialScene::init()
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
    auto label = Label::createWithSystemFont("Ad Interstitial Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.7));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    // Back
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdInterstitialScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    
    auto showLabel = Label::createWithSystemFont("show Interstitial", "Arial", 16);
    showLabel->setColor(Color3B::GREEN);
    auto showBtn = MenuItemLabel::create(showLabel, CC_CALLBACK_1(AdInterstitialScene::pushBtnShow, this));
    showBtn->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    
    auto menu = Menu::create(backButton, showBtn, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "79af9ceba9873a48";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc14c4b32f15e33c18b";
#endif
    
    // インタースティシャル広告
    interstitialAdLoader = CCAdInterstitialAdLoader::create();
    interstitialAdLoader->setDelegate(this);
    interstitialAdLoader->initAd(adUnitId);
    
    _labelStatus->setString("init");
    
    // フォアグラウンド時のイベント
    auto foreground_listener = EventListenerCustom::create("EVENT_COME_TO_FOREGROUND_ROGUE", [this](EventCustom* event){
        
    });
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(foreground_listener, this);
    // バックグラウンド時のイベント
    auto background_listener = EventListenerCustom::create("EVENT_COME_TO_BACKGROUND_ROGUE", [this](EventCustom* event){
        
    });
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(background_listener, this);
    
    return true;
}

void AdInterstitialScene::pushBtnBackScene(Ref* sender)
{
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}

void AdInterstitialScene::pushBtnShow(Ref* sender)
{
    CCLOG("%s", __func__);
    
    interstitialAdLoader->showAd(adUnitId);
    _labelStatus->setString("show");
}


#pragma mark - 

void AdInterstitialScene::finishInitAdFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - finishInitAdFSAdInterstitial");
    
    interstitialAdLoader->loadAd(adUnitId);
    _labelStatus->setString("load");
}

void AdInterstitialScene::failedInitAdFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - failedInitAdFSAdInterstitial");
    
    _labelStatus->setString("failed init");
}

void AdInterstitialScene::skipAdCreateFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - skipAdCreateFSAdInterstitial");
}

void AdInterstitialScene::finishedAdCreateFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - finishedAdCreateFSAdInterstitial");
    
    _labelStatus->setString("ready show");
}

void AdInterstitialScene::failedAdCreateFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - failedAdCreateFSAdInterstitial");
    
    _labelStatus->setString("failed create");
}

void AdInterstitialScene::failedSendAdRequestFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - failedSendAdRequestFSAdInterstitial");
    
    _labelStatus->setString("failed sendAd");
}

void AdInterstitialScene::finishedResponseAdRequestFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - finishedResponseAdRequestFSAdInterstitial");
    
    _labelStatus->setString("finish load");
}

void AdInterstitialScene::failedResponseAdRequestFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - failedResponseAdRequestFSAdInterstitial");
    
    _labelStatus->setString("failed load");
}

void AdInterstitialScene::emptyAdResponseAdRequestFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - emptyAdResponseAdRequestFSAdInterstitial");
    
    _labelStatus->setString("empty ad");
}

void AdInterstitialScene::finishedAdClickFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - finishedAdClickFSAdInterstitial");
    
    _labelStatus->setString("finish click ad");
}

void AdInterstitialScene::failedAdClickFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - failedAdClickFSAdInterstitial");
    
    _labelStatus->setString("failed click ad");
}

void AdInterstitialScene::hideFSAdInterstitial()
{
    CCLOG("AdInterstitialScene - hideFSAdInterstitial");
    
    _labelStatus->setString("hide");
}

