//
//  AdPopupScene.cpp
//  SampleApp
//
//  Created by RN-079 on 2016/05/30.
//
//

#include "AdPopupScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* AdPopupScene::createScene()
{
    auto scene = Scene::create();
    auto layer = AdPopupScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool AdPopupScene::init()
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
    auto label = Label::createWithSystemFont("Ad Popup Scene", "Arial", 16);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(winSize.width * 0.5, winSize.height * 0.96));
    this->addChild(label, 1);
    
    _labelStatus = Label::createWithSystemFont("wait", "Arial", 16);
    _labelStatus->setColor(Color3B::BLACK);
    _labelStatus->setPosition(Point(winSize.width * 0.5, winSize.height * 0.7));
    this->addChild(_labelStatus, 1);
    
    // ボタンの設置
    auto labelBack = Label::createWithSystemFont("Back", "Arial", 16);
    auto backButton = MenuItemLabel::create(labelBack, CC_CALLBACK_1(AdPopupScene::pushBtnBackScene, this));
    backButton->setColor(Color3B::BLUE);
    backButton->setPosition(Point(winSize.width * 0.18, winSize.height * 0.96));
    
    auto showLabel = Label::createWithSystemFont("show Popup", "Arial", 16);
    showLabel->setColor(Color3B::GREEN);
    auto showBtn = MenuItemLabel::create(showLabel, CC_CALLBACK_1(AdPopupScene::pushBtnShow, this));
    showBtn->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
    
    auto menu = Menu::create(backButton, showBtn, NULL);
    menu->setPosition(Point::ZERO);
    
    this->addChild(menu, 2);
    
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS   // cocos2dxプラットフォーム別 IOS
    adUnitId = "253699cab2e982d1";
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID   // cocos2dxプラットフォーム別 Android
    adUnitId = "5417960a57a28fc103b266d9bcf185a7";
#endif
    
    // ポップアップ広告
    popupAdLoader = CCAdPopupAdLoader::create();
    popupAdLoader->setDelegate(this);
    popupAdLoader->initAd(adUnitId);
    
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

void AdPopupScene::pushBtnBackScene(Ref* sender)
{
    auto scene = HelloWorld::createScene();
    
    // 0.5秒かけてホワイトアウトしてTopSceneに遷移させる
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    
    //Splashを破棄してTopSceneに遷移する
    Director::getInstance()->replaceScene(fade);
}

void AdPopupScene::pushBtnShow(Ref* sender)
{
    CCLOG("%s", __func__);
    
    popupAdLoader->showAd(adUnitId);
    _labelStatus->setString("show");
}


#pragma mark - 

void AdPopupScene::finishInitAdFSAdPopup()
{
    CCLOG("AdPopupScene - finishInitAdFSAdPopup");
    
    popupAdLoader->loadAd(adUnitId);
    _labelStatus->setString("load");
}

void AdPopupScene::failedInitAdFSAdPopup()
{
    CCLOG("AdPopupScene - failedInitAdFSAdPopup");
    
    _labelStatus->setString("failed init");
}

void AdPopupScene::failedSendAdRequestFSAdPopup()
{
    CCLOG("AdPopupScene - failedSendAdRequestFSAdPopup");
    
    _labelStatus->setString("failed sendAd");
}

void AdPopupScene::finishedResponseAdRequestFSAdPopup()
{
    CCLOG("AdPopupScene - finishedResponseAdRequestFSAdPopup");
    
    _labelStatus->setString("finish load");
}

void AdPopupScene::failedResponseAdRequestFSAdPopup()
{
    CCLOG("AdPopupScene - failedResponseAdRequestFSAdPopup");
    
    _labelStatus->setString("failed load");
}

void AdPopupScene::emptyAdResponseAdRequestFSAdPopup()
{
    CCLOG("AdPopupScene - emptyAdResponseAdRequestFSAdPopup");
    
    _labelStatus->setString("empty ad");
}

void AdPopupScene::finishedAdCreateFSAdPopup()
{
    CCLOG("AdPopupScene - finishedAdCreateFSAdPopup");
    
    _labelStatus->setString("finish create");
}

void AdPopupScene::failedAdCreateFSAdPopup()
{
    CCLOG("AdPopupScene - failedAdCreateFSAdPopup");
    
    _labelStatus->setString("failed create");
}

void AdPopupScene::finishedAdClickFSAdPopup()
{
    CCLOG("AdPopupScene - finishedAdClickFSAdPopup");
    
    _labelStatus->setString("finish click ad");
}

void AdPopupScene::failedAdClickFSAdPopup()
{
    CCLOG("AdPopupScene - failedAdClickFSAdPopup");
    
    _labelStatus->setString("failed click ad");
}

void AdPopupScene::skipAdCreateFSAdPopup()
{
    CCLOG("AdPopupScene - skipAdCreateFSAdPopup");
    
    _labelStatus->setString("skip ad create");
}

void AdPopupScene::hideFSAdPopup()
{
    CCLOG("AdPopupScene - hideFSAdPopup");
    
    _labelStatus->setString("hide ad");
}


