//
//  AdPiPScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdPiPScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* AdPiPScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdPiPScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdPiPScene::init()
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
    auto label = Label::createWithSystemFont("Ad PiP Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.3));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdPiPScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    
    auto loadLabel = Label::createWithSystemFont("ad load", "Arial", 16);
    loadLabel->setColor(Color3B::GREEN);
    auto loadBtn = MenuItemLabel::create(loadLabel, CC_CALLBACK_1(AdPiPScene::pushBtnAdLoad, this));
    loadBtn->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.8));
    
    auto createLabel = Label::createWithSystemFont("ad create", "Arial", 16);
    createLabel->setColor(Color3B::GREEN);
    auto createBtn = MenuItemLabel::create(createLabel, CC_CALLBACK_1(AdPiPScene::pushBtnAdCreate, this));
    createBtn->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.72));
    
    auto showLabel = Label::createWithSystemFont("ad show", "Arial", 16);
    showLabel->setColor(Color3B::GREEN);
    auto showBtn = MenuItemLabel::create(showLabel, CC_CALLBACK_1(AdPiPScene::pushBtnAdShow, this));
    showBtn->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.64));
    
    auto loadcreateLabel = Label::createWithSystemFont("ad load & create", "Arial", 16);
    loadcreateLabel->setColor(Color3B::GREEN);
    auto loadcreateBtn = MenuItemLabel::create(loadcreateLabel, CC_CALLBACK_1(AdPiPScene::pushBtnAdLoadCreate, this));
    loadcreateBtn->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.5));
    
    auto showLabel2 = Label::createWithSystemFont("ad show", "Arial", 16);
    showLabel2->setColor(Color3B::GREEN);
    auto showBtn2 = MenuItemLabel::create(showLabel2, CC_CALLBACK_1(AdPiPScene::pushBtnAdShow, this));
    showBtn2->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.42));
    
    auto menu = Menu::create(backButton, loadBtn, createBtn, showBtn, loadcreateBtn, showBtn2, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "b607a33beb0208e0";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc1f13d0e28cce289ff";
#endif
    
    // Picture in Picture広告
    pipAdLoader = CCAdPiPAdLoader::create();
    pipAdLoader->setDelegate(this);
    pipAdLoader->initAd(adUnitId);
    
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

void AdPiPScene::pushBtnBackScene(Ref* sender)
{
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}

void AdPiPScene::pushBtnAdLoad(Ref* sender)
{
    pipAdLoader->loadAd(adUnitId);
    _labelStatus->setString("load");
}
void AdPiPScene::pushBtnAdCreate(Ref* sender)
{
    pipAdLoader->createAd(adUnitId);
    _labelStatus->setString("create");
}
void AdPiPScene::pushBtnAdLoadCreate(Ref* sender)
{
    pipAdLoader->loadAndCreateAd(adUnitId);
    _labelStatus->setString("load & create");
}
void AdPiPScene::pushBtnAdShow(Ref* sender)
{
    if (!pipAdLoader->isReadyAd(adUnitId)) {
        return;
    }
    if (!pipAdLoader->isDisplayAd(adUnitId)) {
        pipAdLoader->showAd(adUnitId, CCAdPiPPositionTypeRightBottom);
        _labelStatus->setString("show");
    }
}


#pragma mark - 

void AdPiPScene::finishInitAdFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::finishInitAdFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("finish init");
}

void AdPiPScene::failedInitAdFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedInitAdFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed init");
}

void AdPiPScene::failedSendAdRequestFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedSendAdRequestFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed sendAd");
}

void AdPiPScene::finishedResponseAdRequestFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::finishedResponseAdRequestFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("finish load");
}

void AdPiPScene::failedResponseAdRequestFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedResponseAdRequestFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed load");
}

void AdPiPScene::emptyAdResponseAdRequestFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::emptyAdResponseAdRequestFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("empty ad");
}

void AdPiPScene::finishedReadyMovieFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::finishedReadyMovieFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("ready movie");
}

void AdPiPScene::failedReadyMovieFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedReadyMovieFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed ready");
}

void AdPiPScene::finishedCreateFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::finishedCreateFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("finish create");
}

void AdPiPScene::failedCreateFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedCreateFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed create");
}

void AdPiPScene::completedMovieFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::completedMovieFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("complete movie");
}

void AdPiPScene::finishedAdClickFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::finishedAdClickFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("finish click ad");
}

void AdPiPScene::failedAdClickFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::failedAdClickFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("failed click ad");
}

void AdPiPScene::hideAdViewFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::hideAdViewFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("hide view");
}

void AdPiPScene::expandedAdViewFSAdPiP(const char* adUnitId)
{
    CCLOG("AdPiPScene::expandedAdViewFSAdPiP - adUnitId : %s", adUnitId);
    
    _labelStatus->setString("expanded ad view");
}

