#include <iostream>

void generator(int a) {
	for(int i=1;i<a-a/2;i++) {
		for(int j=1;j<a;j++) {
			std::cout << "*";
		}
		std::cout << '\n';
	}
}

int main() {
	int a;

	std::cout << "Enter a number [2-50]" << '\n';
	std::cin >> a;

	generator(a);

	return 0;
}
