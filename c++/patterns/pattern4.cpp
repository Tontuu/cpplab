#include <iostream>

void generator(int a, int b) {
	for (int i=1; i<=a;i++){
		for (int j=1; j<=a;j++){
			std::cout << b++ << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	int a, b;
	b = 1;

	std::cout << "Enter a number: ";
	std::cin >> a;

	generator(a, b);
	
	return 0;
}
