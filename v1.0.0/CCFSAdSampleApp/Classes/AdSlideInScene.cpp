//
//  AdSlideInScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdSlideInScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* AdSlideInScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdSlideInScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdSlideInScene::init()
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
    auto label = Label::createWithSystemFont("Ad SlideIn Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.7));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdSlideInScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.2));
    
    auto showLabel = Label::createWithSystemFont("show Slide in", "Arial", 16);
    showLabel->setColor(Color3B::GREEN);
    auto showBtn = MenuItemLabel::create(showLabel, CC_CALLBACK_1(AdSlideInScene::pushBtnShow, this));
    showBtn->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    
    auto menu = Menu::create(backButton, showBtn, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "196569da8af682e0";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc10a452d3a9e92b44a";
#endif
    
    // スライドイン広告
    slideinAdLoader = CCAdSlideInAdLoader::create();
    slideinAdLoader->setDelegate(this);
    slideinAdLoader->initAd(adUnitId);
    
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

void AdSlideInScene::pushBtnBackScene(Ref* sender)
{
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}

void AdSlideInScene::pushBtnShow(Ref* sender)
{
    CCLOG("%s", __func__);
    
    slideinAdLoader->showAd(adUnitId);
    _labelStatus->setString("show");
}



#pragma mark - CCAdSlideInAdLoaderDelegate

void AdSlideInScene::finishInitAdFSAdSlideIn()
{
    CCLOG("AdSlideInScene::finishInitAdFSAdSlideIn");
    
    slideinAdLoader->loadAd(adUnitId);
    _labelStatus->setString("load");
}

void AdSlideInScene::failedInitAdFSAdSlideIn()
{
    CCLOG("AdSlideInScene::failedInitAdFSAdSlideIn");
    
    _labelStatus->setString("failed init");
}

void AdSlideInScene::failedSendAdRequestFSAdSlideIn()
{
    CCLOG("AdSlideInScene::failedSendAdRequestFSAdSlideIn");
    
    _labelStatus->setString("failed sendAd");
}

void AdSlideInScene::finishedResponseAdRequestFSAdSlideIn()
{
    CCLOG("AdSlideInScene::finishedResponseAdRequestFSAdSlideIn");
    
    _labelStatus->setString("finish load");
}

void AdSlideInScene::failedResponseAdRequestFSAdSlideIn()
{
    CCLOG("AdSlideInScene::failedResponseAdRequestFSAdSlideIn");
    
    _labelStatus->setString("failed load");
}

void AdSlideInScene::emptyAdResponseAdRequestFSAdSlideIn()
{
    CCLOG("AdSlideInScene::emptyAdResponseAdRequestFSAdSlideIn");
    
    _labelStatus->setString("empty ad");
}

void AdSlideInScene::finishedAdCreateFSAdSlideIn()
{
    CCLOG("AdSlideInScene::finishedAdCreateFSAdSlideIn");
    
    _labelStatus->setString("finish create");
}

void AdSlideInScene::failedAdCreateFSAdSlideIn()
{
    CCLOG("AdSlideInScene::failedAdCreateFSAdSlideIn");
    
    _labelStatus->setString("failed create");
}

void AdSlideInScene::finishedAdClickFSAdSlideIn()
{
    CCLOG("AdSlideInScene::finishedAdClickFSAdSlideIn");
    
    _labelStatus->setString("finish click ad");
}

void AdSlideInScene::failedAdClickFSAdSlideIn()
{
    CCLOG("AdSlideInScene::failedAdClickFSAdSlideIn");
    
    _labelStatus->setString("failed click ad");
}

void AdSlideInScene::skipAdCreateFSAdSlideIn()
{
    CCLOG("AdSlideInScene::skipAdCreateFSAdSlideIn");
    
    _labelStatus->setString("skip create");
}

void AdSlideInScene::hideFSAdSlideIn()
{
    CCLOG("AdSlideInScene::hideFSAdSlideIn");
    
    _labelStatus->setString("hide ad");
}


