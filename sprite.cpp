#include"sprite.h"


Sprite* Sp::create(const char*filename)
{
	auto p = new Sp(filename);
	if (p&&p->init(filename))
	{
		p->autorelease();
	}
	else
	{
		delete p;
		p = nullptr;
	}
	return p;
}

 Sp::Sp(const char*filename)
 {
	 zt = false; 
 }
 bool Sp::init(const char*filename)
{
	this->initWithFile(filename);
	SinglePoint = EventListenerTouchOneByOne::create();

	SinglePoint->setSwallowTouches(true);

	SinglePoint->onTouchBegan = CC_CALLBACK_2(Sp::Touchbegin, this);

	SinglePoint->onTouchMoved = CC_CALLBACK_2(Sp::Touchmove, this);

	SinglePoint->onTouchEnded = CC_CALLBACK_2(Sp::Touchend, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(SinglePoint, this);

	return true;
}


bool Sp::Touchbegin(Touch* t, Event* e)
{
	
	auto zb = t->getLocation();
	auto zbb = this->convertToNodeSpace(zb);
	Rect rectangle = { 0, 0, this->getContentSize().width, this->getContentSize().height };
	if (rectangle.containsPoint(zbb))
	{
		this->setTexture("CloseSelected.png");
		zt = !zt;
		return zt;
	}
	return false;
}

void  Sp::Touchmove(Touch* t, Event* e)
{
	auto py = t->getDelta();
	auto xy = t->getLocation();
	xy = this->getPosition() + py;
	this->setPosition(xy);
}

void  Sp::Touchend(Touch* t, Event* e)
{
	
	auto zb = t->getLocation();
	auto zbb = this->convertToNodeSpace(zb);
	Rect rectangle = { 0, 0, this->getContentSize().width, this->getContentSize().height };
	if (rectangle.containsPoint(zbb))
	{
		int r=rand() % 255;
		int g = rand() % 255;
		int b = rand() % 255;
		this->setTexture("CloseNormal.png");
		this->setColor(Color3B(r, g, b));	
	}
}
