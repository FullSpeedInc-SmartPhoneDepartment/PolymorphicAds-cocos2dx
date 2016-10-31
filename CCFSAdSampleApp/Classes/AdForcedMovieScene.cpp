//
//  AdForcedMovieScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdForcedMovieScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* AdForcedMovieScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdForcedMovieScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdForcedMovieScene::init()
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
    auto label = Label::createWithSystemFont("Ad ForcedMovie Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    // 状態ラベル
    label_state = Label::createWithSystemFont("ad init...", "Arial", 16);
    label_state->setColor(Color3B::BLACK);
    label_state->setPosition(Point(winSize.width * 0.5, winSize.height * 0.6));
    this->addChild(label_state, 1);
    
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdForcedMovieScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    
    auto showLabel = Label::createWithSystemFont("show Forced Movie", "Arial", 16);
    showLabel->setColor(Color3B::GREEN);
    auto showBtn = MenuItemLabel::create(showLabel, CC_CALLBACK_1(AdForcedMovieScene::pushBtnShow, this));
    showBtn->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    
    auto menu = Menu::create(backButton, showBtn, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "ef62fad1bc625754";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc19f0e802776c66967";
#endif
    
    // リワード動画広告
    forcedMovieAdLoader = CCAdForcedMovieAdLoader::create();
    forcedMovieAdLoader->setDelegate(this);
    forcedMovieAdLoader->initAd(adUnitId);
    
    label_state->setString("init");
    
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

void AdForcedMovieScene::pushBtnBackScene(Ref* sender)
{
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}

void AdForcedMovieScene::pushBtnShow(Ref* sender)
{
    CCLOG("%s", __func__);
    
    if (forcedMovieAdLoader->isReadyAd(adUnitId)) {
        forcedMovieAdLoader->showAd(adUnitId);
    }
    label_state->setString("show");
}


#pragma mark - 

void AdForcedMovieScene::finishInitAdFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::finishInitAdFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("load");
    forcedMovieAdLoader->loadAd(adUnitId);
}

void AdForcedMovieScene::failedInitAdFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedInitAdFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed init");
}

void AdForcedMovieScene::failedSendAdRequestFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedSendAdRequestFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed sendAd");
}

void AdForcedMovieScene::finishedResponseAdRequestFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::finishedResponseAdRequestFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("create");
    forcedMovieAdLoader->createAd(adUnitId);
}

void AdForcedMovieScene::failedResponseAdRequestFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedResponseAdRequestFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed load");
}

void AdForcedMovieScene::emptyAdResponseAdRequestFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::emptyAdResponseAdRequestFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("empty ad");
}

void AdForcedMovieScene::finishedReadyMovieFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::finishedReadyMovieFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("ready");
    forcedMovieAdLoader->showAd(adUnitId);
}

void AdForcedMovieScene::failedReadyMovieFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedReadyMovieFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed ready");
}

void AdForcedMovieScene::finishedCreateFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::finishedCreateFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("finish create");
}

void AdForcedMovieScene::failedCreateFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedCreateFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed create");
}

void AdForcedMovieScene::completedMovieFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::completedMovieFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("complete movie");
}

void AdForcedMovieScene::finishedAdClickFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::finishedAdClickFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("finish click ad");
}

void AdForcedMovieScene::failedAdClickFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::failedAdClickFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("failed click ad");
}

void AdForcedMovieScene::hideAdViewFSAdForcedMovie(const char* adUnitId)
{
    CCLOG("AdForcedMovieScene::hideAdViewFSAdForcedMovie - adUnitId : %s", adUnitId);
    
    label_state->setString("stop");
}

