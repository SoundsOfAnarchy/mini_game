#pragma once
#include "Unit.h"
#include "Spider.h"
#include "Queen.h"

class Knight : public Unit
{	
	Queen* queen_location;
	static const double default_knight_speed;
	static const char default_knight_symbol;

	void move_to_enemy(Unit* unit, int iAcc);

public:

	Knight(int i, int j, Field* field, Queen* qu, char symbol = default_knight_symbol, double speed = default_knight_speed)
		: Unit(i, j, field, symbol, speed), queen_location(qu)
	{}
	Knight(char symbol = default_knight_symbol, double speed = default_knight_speed)
		:Unit(symbol, speed), queen_location(nullptr)
	{}

	void action(double deltaTime);

	void set_queen_locations(Queen* queen)
	{
		queen_location = queen;
	}

	

	char get_symbol()
	{
		return _symbol;
	}

};