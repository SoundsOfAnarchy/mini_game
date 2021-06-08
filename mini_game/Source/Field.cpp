#include "Field.h"

const char Field::default_floor_symbol = '-';
//const int default_spider_count = 5;

Field::Field()
{
	_width = 10;
	_length = 10;
	_battleField = new char*[_width];
	_floor_symbol = default_floor_symbol;
	_spiders = { 0 };
	//_Spawn_Field = new bool*[_width];
	for (int i = 0; i < _width; ++i)
	{
		//_Spawn_Field[i] = new bool[_length];
		_battleField[i] = new char[_length];
	}
	init_empty_field();
}

Field::Field(int width, int length, Knight* knight, Queen* queen, char floor_symbol, unsigned int _spider_count)
{
	_knight = knight;
	_queen = queen;
	_floor_symbol = floor_symbol;
	_width = width;
	_length = length;	
	_battleField = new char*[_width];
	//_Spawn_Field = new bool*[_width];
	for (int i = 0; i < _width; ++i)
	{
		_battleField[i] = new char[_length];
		//_Spawn_Field[i] = new bool[_length];
	}
	init_empty_field();
}

Field* Field::get_field()
{
	return this;
}

void Field::init_empty_field()
{
	for (int i = 0; i < _width; ++i)
		for (int j = 0; j < _length; ++j)
			_battleField[i][j] = _floor_symbol;
}

void Field::delete_spider(unsigned int number)
{
	if (number >= 0 && number <= _spiders.size())
	{
		for (int i = number; i < _spiders.size()-1; i++)
		{
			_spiders[i] = _spiders[i + 1];
		}
		_spiders.pop_back();
	}
}

void Field::add_to_spiders(Spider spider)
{
	_spiders.push_back(spider);
}

char & Field::get_element(int i, int j)
{
	if (i < _width && j < _length && i >= 0 && j >= 0) { return _battleField[i][j]; }
	else throw 1;
}

//void Field::edit_element(int i, int j, char ch)
//{
//	if (i < _width && j < _length && i >= 0 && j >= 0) { _battleField[i][j] = ch; }
//}


bool Field::victory()
{
	return _spiders.size() == 0 && _queen->get_i() == _knight->get_i() && _queen->get_j() == _knight->get_j();
}



