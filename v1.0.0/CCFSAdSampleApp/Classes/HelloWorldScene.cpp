
#include "HelloWorldScene.h"

#include "AdBannerScene.h"
#include "AdDoubleBannerScene.h"
#include "AdTwinPanelScene.h"
#include "AdRectangleBannerScene.h"
#include "AdInterstitialScene.h"
#include "AdPopupScene.h"
#include "AdSlideInScene.h"
#include "AdPiPScene.h"
#include "AdForcedMovieScene.h"

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }
    _contents = {
        "AD Banner sample",
        "Ad Double Banner sample",
        "Ad Twin Panel sample",
        "Ad Rectangle Banner sample",
        "AD Interstitial sample",
        "AD Popup sample",
        "AD Slide in sample",
        "AD Picture in Picture sample",
        "AD Forced Movie sample",
    };
    
    window_size = Director::getInstance()->getWinSize();
    //    CCLOG("window  width : %f, height : %f", window_size.width, window_size.height);
    //    auto background = LayerColor::create(Color4B::WHITE, window_size.width, window_size.height);
    //    this->addChild(background, 0);
    
    // テーブルのヘッダー空間
    TableView* tableView = TableView::create(this, Size(window_size.width, window_size.height-60));
    tableView->setAnchorPoint(Point(0.5, 0.5));
    tableView->setPosition(Point(0, 30));
    tableView->setDirection(TableView::Direction::VERTICAL);
    tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    tableView->setDelegate(this);
    addChild(tableView);
    
    tableView->reloadData();
    
    return true;
}


#pragma mark - TableViewDataSource

Size HelloWorld::cellSizeForTable(TableView *table)
{
    return Size(table->getContentSize().width, 60);
}

TableViewCell* HelloWorld::tableCellAtIndex(TableView *table, ssize_t idx)
{
    TableViewCell* cell = table->dequeueCell();
    
    cell = new TableViewCell();
    cell->autorelease();
    
    // 背景
    Sprite* bg = Sprite::create();
    bg->setAnchorPoint(Point(0, 0));
    bg->setTextureRect(Rect(0, 0, window_size.width, 59));
    bg->setColor(Color3B(230, 230, 230));
    bg->setTag(100);
    cell->addChild(bg);
    
    // テキスト部分
    auto text = StringUtils::format("%s", _contents[idx].c_str());
    auto label = Label::createWithSystemFont(text.c_str(), "Arial", 16);
    label->setAnchorPoint(Point(0, 0.5));
    label->setPosition(Point(50, 30));
    label->setColor(Color3B(100, 100, 100));
    cell->addChild(label);
    
    return cell;
}

ssize_t HelloWorld::numberOfCellsInTableView(TableView *table)
{
    return _contents.size();
}

void HelloWorld::tableCellTouched(TableView *table, TableViewCell *cell)
{
    CCLOG("push : %s", _contents[ cell->getIdx() ].c_str());
    
    if (cell->getIdx() == 0) {
        // Ad Banner
        auto scene = AdBannerScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 1) {
        // Ad Double Banner
        auto scene = AdDoubleBannerScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 2) {
        // Ad Twin Panel
        auto scene = AdTwinPanelScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 3) {
        // Ad Rectangle Banner
        auto scene = AdRectangleBannerScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 4) {
        // Ad Interstitial
        auto scene = AdInterstitialScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 5) {
        // Ad Popup
        auto scene = AdPopupScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 6) {
        // Ad Slide In
        auto scene = AdSlideInScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 7) {
        // Ad Picture In Picture
        auto scene = AdPiPScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    if (cell->getIdx() == 8) {
        // Ad Forced Movie
        auto scene = AdForcedMovieScene::createScene();
        Director::getInstance()->pushScene(scene);
    }
    
}
