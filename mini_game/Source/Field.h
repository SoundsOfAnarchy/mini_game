#pragma once
#include<vector>
#include"Spider.h"
#include"Queen.h"
#include"Knight.h"


class Field
{
	static const char default_floor_symbol;
	//static const int default_spider_count;
	char** _battleField;
	//bool** _Spawn_Field;
	int _width;
	int _length;
	char _floor_symbol;
	Knight* _knight;
	Queen* _queen;

public:
	Field();

	Field(int width, int length, Knight* knight, Queen* queen, char floor_symbol = default_floor_symbol, unsigned int _spider_count = 5);
	Field* get_field();

	std::vector<Spider> _spiders;

	int get_width() const
	{
		return _width;
	}

	int get_length() const
	{
		return _length;
	}

	char get_floor_symbol()
	{
		return _floor_symbol;
	}

	int get_spiders_count()
	{
		return _spiders.size();
	}

	void init_empty_field();

	void delete_spider(unsigned int number);
	
	Spider get(int index) { return _spiders[index]; }

	void add_to_spiders(Spider spider);

	char& get_element(int i, int j); //можно ли перегрузить "[][]"?

	//void edit_element(int i, int j, char ch);


	bool victory();

	void clear()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cInfo;
		cInfo.bVisible = false;
		SetConsoleCursorInfo(console, &cInfo);
		SetConsoleCursorPosition(console, COORD{ (SHORT)_width, (SHORT)_length });
		cout << _floor_symbol;
		//SetConsoleCursorPosition(console, COORD{ 10, 10 });
	}

	~Field()
	{
		delete[] _battleField;
	}
};