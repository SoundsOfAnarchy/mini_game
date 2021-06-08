#include <stdexcept>
#include "Spiders.h"


Spiders::Spiders()
{
	_spider_count = default_spider_count;
	_spiders = new Spider[_spider_count];
}

Spiders::Spiders(int spider_count)
{
	_spider_count = spider_count;
	_spiders = new Spider[_spider_count];
}

Spiders * Spiders::get_Spiders()
{
	return this;			
}


void Spiders::udalenie(int number)
{	
	//_spiders[number].udalenie();
	for (int i = number; i < _spider_count - 1; ++i)
	{
		_spiders[i] = _spiders[i + 1];
	}
	--_spider_count;
}

void Spiders::add_spider(Spider * spider)
{

}

Spider & Spiders::operator[](int i)
{
	if (i < _spider_count && i >= 0 ) { return _spiders[i]; }
	else throw out_of_range("incorrect spider index");
}

Spiders::~Spiders()
{
	delete[] _spiders;
}

int const Spiders::default_spider_count = 5;