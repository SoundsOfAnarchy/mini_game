#pragma once
#include "Spider.h"

class Queen : public Spider
{
	static const double default_queen_speed;
	static const char default_queen_symbol;
	static const double default_spawn_speed;

	double _spawn_accum;
	double _spawn_speed;

public:
	Queen(char symbol = default_queen_symbol, double speed = default_queen_speed, double spawn_speed = default_spawn_speed)
		:Spider(symbol, speed), _spawn_accum(0), _spawn_speed(spawn_speed)
	{}
	Queen(int i, int j, Field* field, char symbol = default_queen_symbol, double speed = default_queen_speed)
		: Spider(i, j, field, speed, symbol)
	{}

	void action(double deltaTime);

	char get_symbol()
	{
		return _symbol;
	}

	Spider spawn();


};