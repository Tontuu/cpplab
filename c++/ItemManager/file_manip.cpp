#include "file_manip.h"
#include <iostream>
#include <fstream>
#include <limits>

FileManip::FileManip() {}

int FileManip::getInput(bool error) 
{
	int choice;
	(error == false) ? showAlert = true : showAlert = false;
	
	if (showAlert == true) 
	{
		system("clear");
		std::cout << "INVALID INPUT <==>" << '\n';
		std::cout << "________________________" << "\n\n";
	}
	else 
	{
		std::cout << "1 =={  Normal-Items  }==" << '\n';
		std::cout << "2 =={  Useful-Items  }==" << '\n';
		std::cout << "3 =={  Hurtful-items }==" << '\n';
		std::cout << "4 =={  Modify-Items  }==" << '\n';
		std::cout << "5 =={  Exit-Program  }==" << '\n';
		std::cout << "________________________" << '\n';
		std::cout << "\nCHOICE == ";
	
		std::cin >> choice;
	
		return choice;
	}
	return 0;	
}

void FileManip::printItems(int x) 
{
	std::string name;
	int power;
	std::ifstream fin;
	
	fin.open("objects.txt");

	switch (x) {
		case 1:
			while(fin >> name >> power) 
			{
				if (power == 0){std::cout << "== NORMAL == - " << name << '\n';}
			}
			break;

		case 2:
			while(fin >> name >> power) 
			{
				if (power > 0){std::cout << "== USEFUL == - " << name << '\n';}
			}
			break;

		case 3:
			while(fin >> name >> power) 
			{
				if (power < 0){std::cout << "== HURTFUL == - " << name << '\n';}
			}
			break;

		default:
			break;
	}	
	std::cout << "________________________" << "\n\n";

	fin.close();
}

void FileManip::itemGetInput() 
{
	int itemChoice;
	bool inputLoop = true;

	while (inputLoop == true)
	{
		do 
		{
			if (showAlert == true) 
			{
				std::cout << "INVALID INPUT <==>" << '\n';
				std::cout << "____________________________" << "\n\n";
			}
			
			std::cout << "ITEM MANIPULATION {}" << '\n';
			std::cout << "____________________________" << "\n\n";
			std::cout << "1 =={ === Add-item     ===  }" << '\n';
			std::cout << "2 =={ === Remove-item  ===  }" << '\n';
			std::cout << "3 =={ === Exit-program ===  }" << '\n';
			std::cout << "____________________________" << "\n\n";
			std::cout << "CHOICE == ";

			std::cin >> itemChoice;
			if (itemChoice <= 3 && itemChoice >= 1) {validChoice = true;}
			
			system("clear");
			showAlert = true;
		} while (validChoice == false);
		showAlert = false;

		switch (itemChoice) 
		{
			case 1:
				addItem();	
				break;

			case 2:
				removeItem();
				break;
			case 3:
				inputLoop = false;
				break;

			default:
				break;	
		}
	}
}

void FileManip::addItem() 
{
	std::ofstream fout;
	int itemType;

	std::cout << "ADDING ITEM {}" << '\n';	
	std::cout << "_____________________" << "\n\n";
	std::cout << "Insert the name" << '\n';
	std::cout << "of your new item" << '\n';
	std::cout << "_____________________" << "\n\n";
	std::cout << "ITEM NAME {x to esc} = ";

	std::string itemName;
	std::cin >> itemName;
	system("clear");
	if (itemName == "x") {system("clear"); return;}

	do 
	{
		if (showAlert == true) 
		{
			std::cout << "INVALID INPUT <==>" << '\n';
			std::cout << "_______________________" << "\n\n";
		}

		std::cout << "iTEM NAME - { " << itemName << " }" << '\n';
		std::cout << "______________________" << "\n\n";
		std::cout << "{ normal  =  0 }     |" << '\n';
		std::cout << "{ useful  =  1 }     |" << '\n';
		std::cout << "{ hurtful = -1 }     |" << '\n';
		std::cout << "______________________" << "\n\n";
		std::cout << "ITEM TYPE  = ";

		std::cin >> itemType;
		if (std::cin.fail() || itemType > 1 || itemType < -1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			validChoice = false;
			showAlert = true;
		}  
		else
		{
			validChoice = true;
			showAlert = false;
		}

		system("clear");

	} while (validChoice == false);

	fout.open("objects.txt", std::ios::app);
	if (!fout.is_open()) {std::cout << "can't open the file." << '\n';}

	fout << itemName << " " << itemType << '\n';
	fout.close();
}

void FileManip::removeItem() 
{
	std::string itemToRemove, line;
	std::ifstream fin("objects.txt");
	std::ofstream fout("temp.txt");

	if (!fin.is_open()){std::cout << "can't open the file." << '\n';}

	do 
	{
		if (showAlert == true)
		{
			std::cout << "INVALID INPUT <==>" << '\n';
			std::cout << "_______________________" << "\n\n";
		}
		showAlert = false;

		listOfItems();
		std::cout << "ITEM NAME {x to esc} = ";
		std::cin >> itemToRemove;
		
		if (itemToRemove.length() == 1 && itemToRemove != "x")
		{
			showAlert = true;
			validChoice = false;
		}
		else {validChoice = true;}

	} while (validChoice == false);
	

	if (itemToRemove == "x") {system("clear"); return;}

	while (getline(fin, line))
	{
		if (line.substr(0,	itemToRemove.size()) != itemToRemove)
		{
			fout << line << '\n';
		}
	}
	fin.close();
	fout.close();

	remove("object.txt");
	rename("temp.txt", "objects.txt");

	system("clear");
}

//this function is for listing ALL items, used at 214:9
void FileManip::listOfItems()
{
	std::string name;
	int power;
	std::ifstream fin;

	fin.open("objects.txt");
	if (!fin.is_open()) {std::cout << "couldn't be able to open the file." << '\n';}

	while(fin >> name >> power)
	{
		if (power == 0)
		{
			std::cout << "==  NORMAL  == - " << name << '\n';
		}
	}
	std::cout << "------------------------" << '\n';

	fin.clear();
	fin.seekg(0, fin.beg);		

	while(fin >> name >> power)
	{
		if (power > 0)
		{
			std::cout << "== USEFUL == - " << name << '\n';
		}
	}
	std::cout << "------------------------" << '\n';

	fin.clear();
	fin.seekg(0, fin.beg);		

	while(fin >> name >> power)
	{
		if (power < 0)
		{
			std::cout << std::left << "== HURTFUL == - " << name << '\n';
		}
	}
	std::cout << "------------------------" << '\n';

	fin.close();
}
