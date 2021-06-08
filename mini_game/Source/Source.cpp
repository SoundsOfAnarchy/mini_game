#include "Spider.h"
#include "Field.h"
#include "Knight.h"
#include "Queen.h"

using namespace std;

int main()
{	
	CONSOLE_CURSOR_INFO cInfo;
	cInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cInfo);



	Queen _queen; //создаю королеву пауков



	Knight _knight; //создаю рыцаря
	_knight.set_queen_locations(&_queen);

	Spider _spider;
	int spider_count = 0;
	int n = 0, m = 0;
	cout << "vvedite razmer polya(shirina/dlina)" << endl;
	cin >> n >> m; //создаю полe
	cout << "vvedite kol-vo paukov" << endl;
	cin >> spider_count;
	Field _field(n,m, &_knight, &_queen, '-', spider_count);

	system("cls");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			//_field.edit_element(i, j, _field.get_floor_symbol());
			cout << _field.get_element(i, j);
		}
		cout << endl;
	}

	for (int i = 0; i < spider_count; ++i)
	{
		_field._spiders.push_back(_spider);
		_field._spiders[i].place(&_field);
		_field._spiders[i].draw();
	}


	_queen.place(&_field);
	_queen.draw();

	_knight.set_queen_locations(&_queen);
	_knight.place(&_field);
	_knight.draw();

	auto start_time = chrono::system_clock().now();
	auto past_time = chrono::system_clock().now();
	chrono::duration<double> diff_from_start = past_time - start_time;
	auto draw_time = chrono::system_clock().now();

	//while (!_field.victory())
	int kills = 0;
	int kol_vo = 0;
	/*system("cls");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << _field.get_element(i, j);
		}
		cout << endl;
	}*/
	while(!_field.victory())
	{	
		auto curr_time = chrono::system_clock().now();
		chrono::duration<double> diff = curr_time - past_time;
		chrono::duration<double> past_draw = curr_time - draw_time;

		_queen.action(diff.count());

		for (int i = 0; i <_field._spiders.size(); ++i)
		{
			_field._spiders[i].action(diff.count());
		}

		kol_vo = _field._spiders.size();
		_knight.action(diff.count());
		kills += kol_vo - _field._spiders.size();

		past_time = curr_time;
		diff_from_start = past_time - start_time;
	}



	system("pause");
	return 0;
}