#include <iostream>
#include <string>
#include "price.h"
using namespace std;
Price::Price()
{
	cout << "Price default constructor called\n" << endl;
}
Price::Price(string name, int price, string shop)
{
	productName = name;
	productPrice = price;
	shopName = shop;
	cout << "Price constructor with parameters called\n" << endl;
}
Price::Price(const Price& other)
{
	productName = other.productName;
	productPrice = other.productPrice;
	shopName = other.shopName;
	cout << "Price copy-constructor called\n" << endl;
}
Price::~Price()
{
	cout << "Price default destructor called\n" << endl;
}
string Price::getproductName()
{
	return productName;
}
void Price::setproductName(string name)
{
	productName = name;
}
int Price::getproductPrice()
{
	return productPrice;
}
void Price::setproductPrice(int price)
{
	productPrice = price;
}
string Price::getshopName()
{
	return shopName;
}
void Price::setshopName(string shop)
{
	shopName = shop;
}
ostream& operator<<(ostream& os, const Price& obj)
{
	os << "Product name: " << obj.productName << endl;
	os << "Product price: " << obj.productPrice << endl;
	os << "Shop name: " << obj.shopName << endl;
	return os;
}
istream& operator>>(istream& is, Price& obj) {
	cout << "Enter product name: \n";
	is >> obj.productName;
	cout << "Enter product price: \n";
	is >> obj.productPrice;
	cout << "Enter shop name: \n";
	is >> obj.shopName;
	return is;
}