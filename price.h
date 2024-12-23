#pragma once
#ifndef TP_PRICE_H
#define TP_PRICE_H
#include <iostream>
class Price
{
private:
	std::string productName;
	int productPrice;
	std::string shopName;
public:
	Price();
	Price(std::string productName, int productPrice, std::string shopName);
	Price(const Price& other);
	~Price();
	std::string getproductName();
	void setproductName(std::string productName);
	int getproductPrice();
	void setproductPrice(int productPrice);
	std::string getshopName();
	void setshopName(std::string shopName);
	friend std::ostream& operator<<(std::ostream& os, const Price& obj);
	friend std::istream& operator>>(std::istream& is, Price& obj);
};
#endif 