#include <iostream>

void generator(int a){
	for (int i=1;i<=a;i++){
		for(int j=a-1;j>=i;j--){
			std::cout << " ";
		}
		for(int k=1;k<=i;k++){
			std::cout << " *";
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
