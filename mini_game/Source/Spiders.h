#pragma once
#include<vector>
#include "Spider.h"

using namespace std;

class Spiders
{
	static const int default_spider_count;
	vector<Spider> _spiders;

	/*Spider* _spiders;
	int _spider_count;*/
public:
	Spiders();

	Spiders(int spider_count);

	Spiders* get_Spiders();

	void udalenie(int number);

	//void add_spider(Spider *spider);

	int get_size()
	{
		return _spider_count;
	}

	int get_i(int i)
	{
		if (i < _spider_count && i >= 0) { return _spiders[i].get_i(); }
		else throw 2;
	}

	int get_j(int i)
	{
		if (i < _spider_count && i >= 0) { return _spiders[i].get_j(); }
		else throw 2;
	}


	Spider& operator[](int i);

	~Spiders();

};

