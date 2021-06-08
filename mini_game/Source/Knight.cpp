#include<iostream>
#include "Knight.h"
#include "Field.h"

const double Knight::default_knight_speed = 4;
const char Knight::default_knight_symbol = 'K';

void Knight::move_to_enemy(Unit* unit, int iAcc)
{
	int i = unit->get_i();
	int j = unit->get_j();
	if ((i < pos_i + iAcc && i > pos_i - iAcc) && (j < pos_j + iAcc && j > pos_j - iAcc))
	{		
		pos_i = i;
		pos_j = j;
		draw();
		//_field->edit_element(pos_i, pos_j, _symbol);
		//std::cout << "Clear Spider" << endl;
	}
	else
	{
		int direction_i = 0;
		int direction_j = 0;
		for (int k = 0; k < iAcc; ++k)
		{
			direction_i = i - pos_i;
			direction_j = j - pos_j;

			pos_i += direction_i / (direction_i ? abs(direction_i) : 1);

			pos_j += direction_j / (direction_j ? abs(direction_j) : 1);
		}
		draw();
		//_field->edit_element(pos_i, pos_j, _symbol);
	}
}

void Knight::action(double deltaTime)
{
	int i = 0;
	int j = 0;
	int spider_count =	_field->get_spiders_count();

	_accum += _speed * deltaTime;
	int iAcc = _accum;

	if (iAcc > 0)
	{
		clear();
		//_field->edit_element(pos_i, pos_j, _field->get_floor_symbol());
	
		if (spider_count != 0)
		{
			unsigned int target = 0;

			float distance = 0;
			float min_distance = sqrt((pos_i - _field->_spiders[0].get_i())*(pos_i - _field->_spiders[0].get_i()) +
				(pos_j - _field->_spiders[0].get_j())*(pos_j - _field->_spiders[0].get_j()));

			//Spider* sp_target = &((*spiders_locations)[0]);
			Spider* sp_target = &(_field->_spiders[0]);

			for (unsigned int k = 1; k < spider_count; ++k)
			{
				i = _field->_spiders[k].get_i();
				j = _field->_spiders[k].get_j();
				distance = sqrt((pos_i - i)*(pos_i - i) +
					(pos_j - j)*(pos_j - j));
				if (min_distance > distance)
				{
					min_distance = distance;
					target = k;
					sp_target = &(_field->_spiders[k]);
				}
			}

			move_to_enemy(sp_target, iAcc);
			if (sp_target->get_i() == pos_i && sp_target->get_j() == pos_j)
			{
				_field->_spiders[target].clear();
				_field->delete_spider(target);
				draw();
				//spiders_locations->udalenie(target);
				//sp_target->udalenie();
			}
		}
		else
		{
			move_to_enemy(queen_location, iAcc);
		}

		_accum -= iAcc;
	}
}

