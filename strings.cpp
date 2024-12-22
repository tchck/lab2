#include "strings.h"
#include <fstream>
#include "exception.h"
Strings::Strings()
{
    std::cout << "Strings default constructor called\n";
}
Strings::~Strings()
{
    std::cout << "Strings default destructor called\n";
}

void Strings::checkFile(const std::string& file)
{
    std::ifstream gin;

    gin.open(file);
    if (!gin)
        throw Exception("There is no such file in the directory!\n");
    while (!gin.eof())
        sentence += gin.get();

    for (int i = sentence.size() - 1; i >= 0; i--)
    {
        if (sentence[i] == '.')
        {
            for (int j = i + 2; j < sentence.size() && sentence[j - 1] != '.'; j++)
                std::cout << sentence[j];

            std::cout << " ";
        }
    }

    for (int j = 0; j < sentence.size() && sentence[j] != '.'; j++)
        std::cout << sentence[j];


    std::cout << "\n";
    gin.close();
}