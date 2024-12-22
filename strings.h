#pragma once
#ifndef TP_STRINGS_H
#define TP_STRINGS_H
#include <iostream>
class Strings
{
private:
	std::string sentence;
public:
	Strings();
	~Strings();
	void checkFile(const std::string& file);
	std::string getAlphabet();
};
#endif