#include <iostream>

void generator(int a) {
	for (int i=1;i<=a;i++) {
		for(int j=1;j<=a-2;j++) {
			std::cout << j << " " << i << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	// Fun fact: the format is fixed on numbers smaller than 10!!!
	int a;

	std::cout << "Enter a number [1-50]: ";
	std::cin >> a;

	generator(a);

	return 0;
}
