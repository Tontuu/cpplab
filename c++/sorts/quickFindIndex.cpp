#include <iostream>

int main() {
	int arr [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int index = sizeof(arr)/sizeof(arr[0])/2;
	int number = 5;
	
	
	if (number == arr[index-1]) std::cout << "FOUND AT " << index << " index" << '\n';
	if (number >= index) {
		for (int i = index; i < index*2; i++) {
			if (arr[i] == number) {
				std::cout << "FOUND AT " << i+1 << " index" << '\n';
			}
		}
	}
	else  {
		for (int i = index; i > 0; i--) {
			if (arr[i] == number) {
				std::cout << "FOUND AT " << i+1 << " index" << '\n';
			}
		}
	}
}
