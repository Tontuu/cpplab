#include <iostream>

void generator(int a){
	for (int i = 1; i <= a; i++){
		for(int j = 1; j <= 2*a; j++){
			if (j == i || j == 2*a-i || j == a){
				std::cout << "1 ";
			}
			else std::cout << "0 ";
		}
		std::cout << '\n';
	}
}

int main(){
	int a;
	std::cout << "Enter a number [1-50]: ";
	std::cin >> a;

	generator(a);
}
