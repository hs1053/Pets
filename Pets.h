#pragma once
#ifndef Pets
#define Pets
#include<iostream> 
#include<cstring>
#include<vector>
#include<fstream>
#include"list"
using namespace std;
class Data
{
public:
	void set_time();
	void show_time();
private:
	bool is_time(int, int, int);
	int year;
	int month;
	int day;
};
class Pet_Shop
{
public:
	void Shop_inventory() {}
	void Shop_inventory(string Barcode_number, string Product_name, string Product_type,
		string Nature, string Price, string Customer)
	{
		Cnumber = Barcode_number;
		Cname = Product_name;
		Ctype = Product_type;
		Cprice = Price;
		Cpeople = Customer;
	}
	string Cnumber;
	string Cname;
	string Ctype;
	string Cprice;
	string Cpeople;
};
class guest
{
public:
	string Cnumber;
	string Cname;
	string Ctype;
	string Cprice;
	string Cpeople;
};
class Inventory :public Pet_Shop
{
public:
	void Insert();
	bool Look();
	bool Change();
	void Show();
	bool Delete();
	void Read();
	void Write();
};



#endif