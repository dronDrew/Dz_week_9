#include "car_dealer.h"
#include "Predicat_car.h"
car::car(std::string name_car, int year_of_car, double engine_volume, float price) {
	this->name_car = name_car;
	this->year_of_car = year_of_car;
	this->volume_engine = engine_volume;
	this->price = price;
}
void car::Print_info() {
	std::cout << "Car name : " << this->name_car << std::endl;
	std::cout << "Car year : " << this->year_of_car << std::endl;
	std::cout << "Engine volume : " << this->volume_engine << std::endl;
	std::cout << "Price : " << this->price << std::endl;
}
void Functor_print::operator()(std::vector<car>a) {
	for (auto elem : a)
	{
		elem.Print_info();
	}
}
void Functor_clear::operator()(std::vector<car>&a) {
	a.clear();
}
void Functor_add::operator()(std::vector<car>&a) {
	std::string name;
	int year{0};
	double engine_value{0};
	float Price{0};
	std::cout << "Enter name of car\n";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Enter year of car\n";
	while (year<1915||year>2021)
	{
		std::cin >> year;
	}
	std::cout << "Enter engine volume in mm3 of car\n";
	std::cin >> engine_value;
	std::cout << "Enter price of car\n";
	std::cin >> Price;
	car temp(name, year, engine_value, Price);
	a.push_back(temp);
}
void Functor_sort_by_name::operator()(std::vector<car>& a) {

	std::sort(a.begin(),a.end(),Car_name_sort());
}
void Functor_sort_by_year::operator()(std::vector<car>& a) {
	//int year;
	//std::sort(a.begin(), a.end(),year);
}
void Functor_sort_by_volume::operator()(std::vector<car>& a) {
	//std::sort(a.begin(), a.end());
}
void Functor_sort_by_price::operator()(std::vector<car>& a){
	//std::sort(a.begin(), a.end());
}
void Functor_search_by_name::operator()(std::vector<car>& a) {
	//std::string name;
	//std::find_if(a.begin(), a.end(),name);
}
void Functor_search_by_year::operator()(std::vector<car>& a) {
	//std::find_if(a.begin(), a.end());
}
void Functor_search_by_volume::operator()(std::vector<car>& a) {
	//std::find_if(a.begin(), a.end());
}
void  Functor_search_by_price::operator()(std::vector<car>& a) {
	//std::find_if(a.begin(), a.end());
}

//
void car_dealer::Menu() {
	int choice{ 0 };
	while (true)
	{
		std::cout << "Press 1 to add car\n";
		std::cout << "Press 2 to print all saled cars\n";
		std::cout << "Press 3 to clear database\n";
		std::cout << "Press 4 to sort cars\n";
		std::cout << "Press 5 to search\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			Functor_add add;
			add(this->solded_car);
			system("CLS");
			break;
		case 2:
			Functor_print print;
			print(this->solded_car);
			system("CLS");
			break;
		case 3:
			Functor_clear clear;
			clear(this->solded_car);
			system("CLS");
			break;
		case 4:
			std::cout << "Press 1 to sort by name\n";
			std::cout << "Press 2 to sort by year\n";
			std::cout << "Press 3 to sirt by engine volume\n";
			std::cout << "Press 4 to sort by price\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1 :
				Functor_sort_by_name name;
				name(this->solded_car);
				break;
			case 2:
				Functor_sort_by_year year;
				year(this->solded_car);
				break;
			case 3:
				Functor_sort_by_volume volume;
				volume(this->solded_car);
				break;
			case 4:
				Functor_sort_by_price price;
				price(this->solded_car);
				break;
			}
			break;
		case 5:
			std::cout << "Press 1 to search by name\n";
			std::cout << "Press 2 to search by year\n";
			std::cout << "Press 3 to search by engine volume\n";
			std::cout << "Press 4 to search by price\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				Functor_search_by_name na;
				na(this->solded_car);
				break;
			case 2:
				Functor_search_by_year ye;
				ye(this->solded_car);
				break;
			case 3:
				Functor_search_by_volume vol;
				vol(this->solded_car);
				break;
			case 4:
				Functor_search_by_price pri;
				pri(this->solded_car);
				break;
			}
			break;
			
		}

	}


}