#include <iostream>
#include "price.h"
#include "functions.h"
#include "strings.h"
using namespace std;
int main()
{
	int command;
	int cnt = 0;
	Price* pr = new Price[cnt];
	cout << "1. Task 1\n"
		"2. Task 2\n"
		"Enter a command:\n";
	cin >> command;
	switch (command) {
	case 1: {
		while (true) {
			Menu();
			cin >> command;
			try {
				switch (command) {
				case 1: {
					addProduct(pr, cnt);
					break;
				}
				case 2: {
					addProdByIndex(pr, cnt);
					break;
				}
				case 3: {
					removeProd(pr, cnt);
					break;
				}
				case 4: {
					printProducts(pr, cnt);
					break;
				}
				case 5: {
					editProducts(pr, cnt);
					break;
				}
				case 6: {
					sortProd(pr, cnt);
					break;
				}
				case 7: {
					checkProd(pr, cnt);
					break;
				}
				case 8: {
					cout << "Goodbye!\n";
					delete[] pr;
					return 0;
				}
				default: {
					cout << "Command is not found!\n";
				}
				}
			}
			catch (Exception error) {
				cout << error;
			}
		}
	}
	case 2: {
		while (true)
		{
			try
			{
				cout << "Enter file name:\n";
				std::string file;
				cin >> file;
				Strings object;
				object.checkFile(file);
				return 0;
			}
			catch (Exception error) {
				cout << error;
			}
		}
	}
	}
}
