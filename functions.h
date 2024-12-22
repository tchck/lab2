#pragma once
#ifndef TP_FUNCTIONS_H
#define TP_FUNCTIONS_H
#include "price.h"
#include "exception.h"
void Menu()
{
	std::cout << "\nMenu:\n"
		"1. Add product\n"
		"2. Add product by index\n"
		"3. Remove product\n"
		"4. Print products\n"
		"5. Edit product\n"
		"6. Sort products\n"
		"7. Check product\n"
		"8. Exit\n"
		"Enter a command:\n";
}
void addProduct(Price*& pr, int& cnt)
{
	Price prod;
	std::cin >> prod;
	cnt++;
	Price* temp = new Price[cnt];
	for (int i = 0; i < cnt - 1; i++)
	{
		Price copy_prod(pr[i]);
		temp[i] = copy_prod;
	}
	delete[] pr;
	temp[cnt - 1] = prod;
	pr = temp;
}
void addProdByIndex(Price*& pr, int& cnt)
{
	int index;
	if (!cnt)
		throw Exception("There is no place for the object!\n");
	std::cout << "Enter index from 0 to " << cnt - 1 << ":\n";
	std::cin >> index;
	if (0 > index >= cnt)
		throw Exception("It is impossible to insert into this position!\n");
	Price prod;
	std::cin >> prod;
	pr[index] = prod;
}
void removeProd(Price*& pr, int& cnt)
{
	if (!cnt)
		throw Exception("There is no place for the object!\n");
	int index;
	std::cout << "Enter product index to remove:\n";
	std::cin >> index;
	if (0 > index || index >= cnt)
		throw Exception("There is no such product!\n");
	Price* temp = new Price[cnt - 1];
	for (int i = 0; i < index; i++)
	{
		temp[i] = pr[i];
	}
	for (int i = index + 1; i < cnt; i++)
	{
		temp[i - 1] = pr[i];
	}
	delete[] pr;
	pr = temp;
	cnt--;
}
void printProducts(Price*& pr, int& cnt)
{
	if (!cnt)
		throw Exception("The list of products is empty!\n");
	std::cout << "There are " << cnt << " products:\n";
	for (int i = 0; i < cnt; i++) {
		std::cout << i + 1 << ". \n" << pr[i] << "\n";
	}
}
void editProducts(Price*& pr, int& cnt)
{
	if (!cnt)
		throw Exception("The list of products is empty!\n");
	int index;
	std::cout << "Enter product index to edit from 0 to " << cnt - 1 << ":\n";
	std::cin >> index;
	if (0 > index || index >= cnt)
		throw Exception("There is no such product!\n");
	Price prod;
	std::cin >> prod;
	pr[index] = prod;
}
void sortProd(Price*& pr, int& cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt - 1; j++)
		{
			if (pr[j].getproductName() > pr[j + 1].getproductName())
			{
				Price temp(pr[j]);
				pr[j] = pr[j + 1];
				pr[j + 1] = temp;
			}
		}
	}
}
void checkProd(Price*& pr, int& cnt)
{
	std::string name;
	std::cout << "Enter product name:\n";
	std::cin >> name;
	bool flag = false;
	for (int i = 0; i < cnt; i++)
	{
		std::string productName = pr[i].getproductName();
		if (name == productName)
		{
			std::cout << "Product price: " << pr[i].getproductPrice() << ", "
				<< "Shop name: " << pr[i].getshopName() << std::endl;
			flag = true;
		}
	}
	if (!flag)
		std::cout << "There are no such products!\n";
}
#endif 