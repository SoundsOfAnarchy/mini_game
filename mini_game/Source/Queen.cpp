#include "Queen.h"
#include"Field.h"


const double Queen::default_queen_speed = 3;
const char Queen::default_queen_symbol = 'Q';
const double Queen::default_spawn_speed = 2;

void Queen::action(double deltaTime)
{
	bool correct = false;
	int i = 0;
	int j = 0;
	_accum += _speed * deltaTime;
	_spawn_accum += deltaTime;
	int spawnAcc = _spawn_accum;
	int iAcc = _accum;
	if (spawnAcc > 100)
	{
		_field->add_to_spiders(spawn());
		_field->_spiders[_field->_spiders.size()-1].draw();
		_spawn_accum -= spawnAcc;
	}
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

Spider Queen::spawn()
{
	bool correct = false;
	int j = 0;
	int i = 0;
	while (!correct)
	{
		i = pos_i + rand() % 3 - 1;
		j = pos_j + rand() % 3 - 1;
		if (i != pos_i && j != pos_j && _field->get_element(i, j) == _field->get_floor_symbol()) { correct = true; }
	}
	return Spider(i, j, _field);
}
