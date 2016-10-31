#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <extensions/cocos-ext.h>

USING_NS_CC;
using namespace extension;

class HelloWorld : public cocos2d::Layer,
public TableViewDataSource,
public TableViewDelegate
{
    Size window_size;
    std::vector<std::string> _contents;
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    // TableViewDataSourceの抽象メソッド
    virtual Size cellSizeForTable(TableView* table);
    virtual TableViewCell* tableCellAtIndex(TableView* table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(TableView* table);
    
    // TableViewDelegateの抽象メソッド
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    
    // TableViewDelegateが継承しているScrollViewの抽象メソッド
    virtual void scrollViewDidScroll(ScrollView* view){};
    virtual void scrollViewDidZoom(ScrollView* view){};
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
