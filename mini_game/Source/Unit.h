#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <Windows.h>

using namespace std;

class Field;

class Unit
{
protected:
	Field* _field;

	int pos_i;
	int pos_j;


	double _speed;
	double _accum;
	bool _moved;


	char _symbol;

public:
	Unit(char symbol, double speed);

	Unit(int i, int j, Field* field, char symbol, double speed)
		:pos_i(i), pos_j(j), _field(field), _speed(speed), _symbol(symbol), _moved(false), _accum(0)
	{}

	virtual void action(double deltaTime) = 0;

	int get_i()
	{
		return pos_i;
	}

	int get_j()
	{
		return pos_j;
	}

	virtual char get_symbol() = 0;

	void place(Field* field);

	void udalenie();
	void clear();
	void draw();
protected:
	
	
};



