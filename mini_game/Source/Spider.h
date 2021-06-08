#pragma once
#include "Unit.h"

class Spider : public Unit
{
	static const double default_spider_speed;
	static const char default_spider_symbol;
public:
	Spider(int i, int j, Field* field, char symbol = default_spider_symbol, float speed = default_spider_speed)
		: Unit(i, j, field, symbol, speed)
	{
		place(field);
	}
	Spider(char symbol = default_spider_symbol, float speed = default_spider_speed)
		:Unit(symbol, speed)
	{}

	void action(double deltaTime);

	char get_symbol()
	{
		return _symbol;
	}
};
