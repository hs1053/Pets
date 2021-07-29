#include "Pets.h"
void Data::set_time()
{
	char c1, c2;
	cout << "Please enter the date (format year-month-day)" << endl;
	while (1)
	{
		cin >> year >> c1 >> month >> c2 >> day;
		if (c1 != '-' || c2 != '-')
			cout << "The format is incorrect, please re-enter" << endl;
		else
			break;
	}
}
void Data::show_time()
{
	cout << year << "-" << month << "-" << day << endl;
}
list<Inventory>ProductList;
void Inventory::Insert()
{
	Inventory Pet;
	char ch;
	int symbol = 0;
	list<Inventory>::iterator first, last;
	first = ProductList.begin();
	last = ProductList.end();
	do {
		cout << "Please enter item related information!" << endl;
		cout << "serial number:";
		cin >> Pet.Cnumber;
		cout << "name:";
		cin >> Pet.Cname;
		cout << "Type of Product (TOY,FOOD,BOOK,ACCESSORIES):";
		cin >> Pet.Ctype;
		cout << "Price:";
		cin >> Pet.Cprice;
		cout << "Customer Name:";
		cin >> Pet.Cpeople;
		for (; first != last; ++first)
		{
			if ((Pet.Cname == (*first).Cname) && (Pet.Cprice == (*first).Cprice)
				&& (Pet.Ctype == (*first).Ctype))
			{
				symbol = 1;
				cout << endl << "The Product already exists!" << endl;
				cout << "Serial number:" << (*first).Cnumber << endl;
				cout << "Name:" << (*first).Cname << endl;
				cout << "Type of Product:" << (*first).Ctype << endl;
				cout << "Price:" << (*first).Cprice << endl;
				cout << "Customer Name:" << (*first).Cpeople;
			}
		}
		if (symbol == 0)
		{
			ProductList.insert(ProductList.end(), Pet);
		}
		cout << endl << "Continue to add pet information [Y or N]?";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
}

bool Inventory::Look()
{
	string name, price, type;
	int symbol = 0;
	int option;
	list <Inventory>::iterator first, last;
	do
	{
		cout << "\tPlease enter the way you search!" << endl;
		cout << "\t1. Search by name" << endl;
		cout << "\t2. Search by price" << endl;
		cout << "\t3. Search by category" << endl;
		cout << "\t4. Exit!" << endl;
		cin >> option;
		switch (option)
		{
		case 1: cout << "Please enter a name:";
			cin >> name; break;
		case 2: cout << "Please enter the price:";
			cin >> price; break;
		case 3: cout << "Please enter the type:";
			cin >> type; break;
		case 4:break;
		}
		first = ProductList.begin();
		last = ProductList.end();
		for (; first != last; ++first)
		{
			if ((name == (*first).Cname) && (option == 1))
			{
				symbol = 1;
				cout << "Product Name is" + (*first).Cname + "The product information is as follows:" << endl;
				cout << "Serial number:" + (*first).Cnumber << endl;
				cout << "Name:" + (*first).Cname << endl;
				cout << "Product Type:" + (*first).Ctype << endl;
				cout << "Price:" + (*first).Cprice << endl;
				cout << "Customer Name:" + (*first).Cpeople << endl;
			}
			if ((price == (*first).Cprice) && (option == 2))
			{
				symbol = 1;
				cout << "Pet price is" + (*first).Cprice + "The pet information is as follows:" << endl;
				cout << "serial number:" + (*first).Cnumber << endl;
				cout << "name:" + (*first).Cname << endl;
				cout << "species:" + (*first).Ctype << endl;
				cout << "price:" + (*first).Cprice << endl;
				cout << "the host:" + (*first).Cpeople << endl;
			}
			if ((type == (*first).Ctype) && (option == 3))
			{
				symbol = 1;
				cout << "Product is" + (*first).Ctype + "The product information is as follows:" << endl;
				cout << "Serial number:" + (*first).Cnumber << endl;
				cout << "Name:" + (*first).Cname << endl;
				cout << "Product Type:" + (*first).Ctype << endl;
				cout << "Price:" + (*first).Cprice << endl;
				cout << "Customer Name:" + (*first).Cpeople << endl;
			}
		}
	} while (option != 4);
	if ((first == last) && (symbol == 0))
	{
		cout << "There is no such Product information!";
		return false;
	}
	else
		return true;
}

bool Inventory::Change()
{
	Inventory pet;
	string name, price, type;
	int symbol = 0;
	cout << "Please enter a name:";
	cin >> name;
	cout << "Please enter the price:";
	cin >> price;
	cout << "Please enter the type:";
	cin >> type;
	list <Inventory>::iterator first, last;
	first = ProductList.begin();
	last = ProductList.end();
	for (; first != last; ++first)
	{
		if ((name == (*first).Cname) && (price == (*first).Cprice) && (type == (*first).Ctype))
		{
			symbol = 1;
			cout << endl << "The pet information is found. The pet information before modification is:" << endl;
			cout << "Serial number:" + (*first).Cnumber << endl;
			cout << "Name:" + (*first).Cname << endl;
			cout << "Product Type:" + (*first).Ctype << endl;
			cout << "Price:" + (*first).Cprice << endl;
			cout << "Customer Name:" + (*first).Cpeople << endl;
			break;
		}
	}
	if (symbol)
	{
		cout << endl << "The revised product information is:" << endl;
		cout << "Customer";
		cin >> pet.Cpeople;
		pet.Cname = name;
		pet.Cprice = price;
		pet.Ctype = type;
		for (; first != last; ++first)
		{
			if ((name == (*first).Cname) && (price == (*first).Cprice) && (type == (*first).Ctype))
			{
				(*first) = pet;
			}
		}
		return true;
	}
	else
	{
		cout << "There is no such product information!";
		return false;
	}
}

void Inventory::Show()
{
	list <Inventory>::iterator first, last, it;
	first = ProductList.begin();
	last = ProductList.end();
	for (; first != last; ++first)
	{
		cout << "******************Your pet information**********************" << endl;
		cout << "Serial number:" << (*first).Cnumber << endl;
		cout << "Name:" << (*first).Cname << endl;
		cout << "Product Type:" << (*first).Ctype << endl;
		cout << "Price:" << (*first).Cprice << endl;
		cout << "Customer Name:" << (*first).Cpeople << endl;
		cout << "****************************************" << endl;
	}
}

bool Inventory::Delete()
{
	string name, price, type;
	int symbol = 0;
	cout << "Please enter a name:";
	cin >> name;
	cout << "Please enter the price:";
	cin >> price;
	cout << "Please enter the type:";
	cin >> type;
	list <Inventory>::iterator first, last, it;
	first = ProductList.begin();
	last = ProductList.end();
	for (; first != last; ++first)
	{
		if ((name == (*first).Cname) && (price == (*first).Cprice) && (type == (*first).Ctype))
		{
			symbol = 1;
			cout << "Found the Product information! Can be deleted!" << endl;
			it = first;
			ProductList.erase(first);
		}
	}
	if ((first == last) && (symbol == 0))
	{
		cout << "There is no such Product information!";
		return false;
	}
	else
	{
		ProductList.erase(it);
		return true;
	}
}

void Inventory::Write()
{
	char file[256];
	string FileName;
	cout << "Please enter the file name: (extension can be added! Such as .txt)";
	cin >> FileName;
	if (FileName.find(".") > FileName.length())
	{
		FileName = FileName + ".txt";
	}
	ofstream fout(file);
	if (!fout)
	{
		cout << "File writing failed! Please check your file name!" << endl;
		return;
	}
	else
	{
		list <Inventory>::iterator first, last;
		first = ProductList.begin();
		last = ProductList.end();
		for (; first != last; ++first)
		{
			fout << endl << "Serial number:" << (*first).Cnumber << endl << "Name:" << (*first).Cname << endl
				<< "Product Type:" << (*first).Ctype << endl << "Price:" << (*first).Cprice << endl << "Customer Name:" << (*first).Cpeople << endl;
		}
		cout << "The file is saved successfully!" << endl;
	}
	fout.close();
}

void Inventory::Read()
{
	char file[256];
	string FileName;
	cout << "Please enter the file name: (extension can be added! Such as .txt)";
	cin >> FileName;
	if (FileName.find(".") > FileName.length())
	{
		FileName = FileName + ".txt";
	}
	ifstream fin(file);
	int index;
	if (!fin)
	{
		cout << "File writing failed! Please check your file name!" << endl;
		return;
	}
	else
	{
		ProductList.clear();
		while (!fin.eof())
		{
			Inventory pet;
			string str;
			fin >> str;
			index = str.find(":");
			pet.Cnumber = str.substr(index + 1);
			fin >> str;
			index = str.find(":");
			pet.Cname = str.substr(index + 1);
			fin >> str;
			index = str.find(":");
			pet.Ctype = str.substr(index + 1);
			fin >> str;
			index = str.find(":");
			pet.Cprice = str.substr(index + 1);
			fin >> str;
			index = str.find(":");
			pet.Cpeople = str.substr(index + 1);
			ProductList.insert(ProductList.end(), pet);

		}
		cout << "\n" << "Please Visit Us Again For More Products (^.^*)!" << endl;
		cout << "File read successfully! " << endl;
	}
	fin.close();
}
int main()
{
	Inventory pet;
	int option;
	do
	{
		cout << endl << "Welcome to the pet store management system! Please select the menu:" << endl;
		cout << " \t┌-------------------------┐" << endl;
		cout << "\t┊ 1. Add Product information ┊" << endl;
		cout << "\t┊ 2. Find Product information ┊" << endl;
		cout << "\t┊ 3. Modify Product information ┊" << endl;
		cout << "\t┊ 4. Display (browse) Product information┊" << endl;
		cout << "\t┊ 5. Delete Product information ┊" << endl;
		cout << "\t┊ 6. Save the file ┊" << endl;
		cout << "\t┊ 7. Read file ┊" << endl;
		cout << "\t┊ 8. Exit the system ┊" << endl;
		cout << " \t└-------------------------┘\n" << endl;
		cin >> option;
		switch (option) 
		{
		case 1: { pet.Insert(); break; }
		case 2: { pet.Look(); break; }
		case 3: { pet.Change(); break; }
		case 4: { pet.Show(); break; }
		case 5: { pet.Delete(); break; }
		case 6: { pet.Write(); break; }
		case 7: { pet.Read(); break; }
		case 8: { break; }
		}
	} while (option != 8);
	return 0;
}
