#include "strings.h"
#include <fstream>
#include "exception.h"
Strings::Strings()
{
	alphabet = "aeiouyAEIOUY";
	std::cout << "Strings default constructor called\n";
}
Strings::~Strings()
{
	std::cout << "Strings default destructor called\n";
}
std::string Strings::getAlphabet()
{
	return alphabet;
}
void Strings::checkFile(const std::string& file)
{
	std::ifstream gin;
	gin.open(file);
	if (!gin)
		throw Exception("There is no such file in the directory!\n");
	std::string line, alp = this->getAlphabet();
	std::cout << "\nWords with a vowel letter:\n";
	while (gin >> line)
	{
		std::string line_rem = "";
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z')
				line_rem += line[i];
		}
		line = line_rem;
		bool flag = false;
		for (int i = 0; i < 12; i++)
		{
			if (alp[i] == line[0])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			std::cout << line << std::endl;
	}
	std::cout << "\n";
	gin.close();
}