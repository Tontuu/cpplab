#include <iostream>

void generator(int a){
	int n1=0,n2=1,r=n1+n2;

	for(int i=1;i<=a;i++){
		for(int j=1;j<=i;j++){
			std::cout << r << " ";
			r=n1+n2;
			n1=n2;
			n2=r;
		}
		std::cout << '\n';
	}
}

int main(){
	int a;

	std::cout << "Enter a number[1-9]: ";
	std::cin >> a;

	generator(a);
}
