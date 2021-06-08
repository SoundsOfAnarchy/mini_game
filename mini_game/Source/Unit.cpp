#include "Unit.h"
#include "Field.h"

Unit::Unit(char symbol, double speed)
	:_field(nullptr), pos_i(-1), pos_j(-1), _symbol(symbol), _speed(speed), _accum(0)
{}


void Unit::place(Field * field)
{
	_field = field;
	int n = _field->get_width();
	int m = _field->get_length();
	bool correct = false;
	while (!correct)
	{
		pos_i = rand() % n;
		pos_j = rand() % m;
		if (_field->get_element(pos_i, pos_j) == _field->get_floor_symbol()) { correct = true; }
	}
	draw();
}

void Unit::udalenie()
{
	clear();
	//_field->edit_element(pos_i, pos_j, '-');
	pos_i = -1;
	pos_j = -1;
}

void Unit::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cInfo;
	cInfo.bVisible = false;
	SetConsoleCursorInfo(console, &cInfo);
	SetConsoleCursorPosition(console, COORD{ (SHORT)pos_i, (SHORT)pos_j });
	//_field->edit_element(pos_i, pos_j, _symbol);
	cout << _symbol;
}

void Unit::clear()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cInfo;
	cInfo.bVisible = false;
	SetConsoleCursorInfo(console, &cInfo);
	SetConsoleCursorPosition(console, COORD{ (SHORT)pos_i, (SHORT)pos_j });
	//_field->edit_element(pos_i, pos_j, _field->get_floor_symbol());
	cout << _field->get_element(pos_i, pos_j);
}

