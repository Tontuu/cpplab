#include <iostream>
#include "file_manip.h"

int main() {
	int input;
	FileManip items;
	
	system("clear");

	//I'm using a boolean parameter to show if the input is accepted. 
	input = items.getInput(true);
	while (input != 5) {
		if (input > 5 || input < 1){input = items.getInput(false);}

		switch (input) {
			case 1:
				system("clear");
				items.printItems(input);
				break;
			case 2:
				system("clear");
				items.printItems(input);
				break;
			case 3:
				system("clear");
				items.printItems(input);
				break;
			case 4:
				system("clear");
				items.itemGetInput();
				break;
			default:
				input = items.getInput(false);
		}	
		input = items.getInput(true);
	}
	return 0;

}

