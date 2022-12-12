#include <iostream>

void generator(int a){
	int b;

	for(int i=1;i<=a;i++){
		b=a-i+1;
		for(int j=1;j<=a;j++){
			std::cout << b << " ";
			b=b+a;
		}
		std::cout << '\n';
	}
}

int main(){
	int a;

	std::cout << "Enter a number[1-50]: ";
	std::cin >> a;

	generator(a);
}
