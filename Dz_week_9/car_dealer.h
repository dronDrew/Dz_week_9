#pragma once
#include "dependies.h"
struct car {
	std::string name_car;
	int year_of_car;
	double volume_engine;
	float price;
public:
	car(std::string name_car, int year_of_car, double engine_volume, float price);
	void Print_info();
};
//_____________________________________________________________
class Functor_print {
public:
	void operator()(std::vector<car>a);
};
class Functor_clear {
public:
	void operator()(std::vector<car>&a);
};
class Functor_add {
public:
	void operator()(std::vector<car>&a);
};
class Functor_sort_by_name {
public:
	void operator()(std::vector<car>& a);
};
class Functor_sort_by_year {
public:
	void operator()(std::vector<car>& a);
};
class Functor_sort_by_volume {
public:
	void operator()(std::vector<car>& a);
};
class Functor_sort_by_price {
public:
	void operator()(std::vector<car>& a);
};
class Functor_search_by_name {
public:
	void operator()(std::vector<car>& a);
};
class Functor_search_by_year {
public:
	void operator()(std::vector<car>& a);
};
class Functor_search_by_volume {
public:
	void operator()(std::vector<car>& a);
};
class Functor_search_by_price {
public:
	void operator()(std::vector<car>& a);
};
//____________________________________________________________________
class car_dealer
{
	std::vector<car>solded_car;
public:
	void Menu();
};

