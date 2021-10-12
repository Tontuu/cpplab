#include <iostream>

void generator(int a) {
	for (int i=1; i<=a-a/2;i++){
		for (int j=0; j<=a;j++){
			std::cout << i;
		}
		std::cout << '\n';
	}
}

int main() {
	int a;

	std::cout << "Enter a number: ";
	std::cin >> a;

	generator(a);
	
	return 0;
}
