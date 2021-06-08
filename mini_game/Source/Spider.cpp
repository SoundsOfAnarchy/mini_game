#include "Spider.h"
#include"Field.h"

const double Spider::default_spider_speed = 2;
const char Spider::default_spider_symbol = 'S';

void Spider::action(double deltaTime)
{
	bool correct = false;
	int i = 0;
	int j = 0;
	_accum += _speed * deltaTime;
	int iAcc = _accum;

	if (iAcc > 0)
	{
		clear();
		while (!correct)
		{
			i = pos_i + (rand() % (iAcc + iAcc + 1) - iAcc);
			j = pos_j + (rand() % (iAcc + iAcc + 1) - iAcc);
			if (i >= 0 && j >= 0 && i < _field->get_width() && j < _field->get_length()
			&& _field->get_element(i, j) == _field->get_floor_symbol())
			{
				correct = true;
			}
		}
		
		_moved = true;	
		_accum -= iAcc;
		pos_i = i;
		pos_j = j;
		draw();
	}
	else
	{
		_moved = false;
	}

}

