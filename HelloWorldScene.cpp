#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->scheduleUpdate(); 

	auto m = Sp::create("CloseNormal.png");
	m->setAnchorPoint(Vec2(0, 0));
	m->setPosition(0, 0);

	auto sprite = Sprite::create("map.jpg");
	Size SWG = sprite->getContentSize();
	sprite->setAnchorPoint(Vec2(0,0));

	sprite->addChild(m);
	this->addChild(sprite);

	auto jtq = EventListenerTouchOneByOne::create();	

	jtq->onTouchBegan = [](Touch* t, Event* e)->bool
	{
		return true;
	};
	jtq->onTouchMoved = [sprite, SWG, visibleSize](Touch* t, Event* e)->void{
		
		auto Touchxy = t->getLocation();
		auto Touchpy = t->getDelta();
		auto sss = sprite->getPosition() + Touchpy;
		
		if (sss.x >= 0 || sss.x <= (visibleSize.width - SWG.width))
		{
			sss.x -= Touchpy.x;

		}
		if (sss.y >= 0 || sss.y <= (visibleSize.height - SWG.height))
		{
			sss.y -= Touchpy.y;
		}
		sprite->setPosition(sss);
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(jtq, this);

    return true;
}

void HelloWorld::update(float)
{
	CCLOG("1");
	//this->yingdong(m->getPosition());
}

void HelloWorld::yingdong(Vec2 pos)
{
	
	/*if (m->zt)
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		int x = pos.x < (visibleSize.width / 2) ? (visibleSize.width / 2) : pos.x;
		int y = pos.y < (visibleSize.height) ? (visibleSize.height / 2) : pos.y;

		x = x >(Swg.width - visibleSize.width / 2) ? (Swg.width - visibleSize.width / 2) : x;
		y = x >(Swg.height - visibleSize.height / 2) ? (Swg.height - visibleSize.height / 2) : y;

		Vec2 po(x, y);

		Vec2 poo(visibleSize.width / 2, visibleSize.height / 2);

		Vec2 pooo = po - poo;
		this->setPosition(pooo);
	}*/
}
