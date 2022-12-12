#include <iostream>

void generator(char a, char b){
	for(int i=a;i<=b;i++){
		for (int j=a;j<=b;j++){
			std::cout << char(i) << " ";
		}
		std::cout << '\n';
	}
}

int main(){
	char a,b;

	std::cout << "Enter a char[A]: ";
	std::cin >> a;
	std::cout << "Enter a char[B]: ";
	std::cin >> b;

	generator(a,b);

	return 0;
}
