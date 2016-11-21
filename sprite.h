#pragma once
#include"cocos2d.h"
USING_NS_CC;

class Sp:public Sprite
{
public:
	static Sprite* create(const char*);
	Sp(const char*);
	~Sp(){};
	virtual bool init(const char*);
	bool Touchbegin(Touch*, Event*);
	void Touchmove(Touch*, Event*);
	void Touchend(Touch*, Event*);

	EventListenerTouchOneByOne* SinglePoint;
	bool zt;
};