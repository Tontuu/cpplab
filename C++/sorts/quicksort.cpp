#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec){
	for (int i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
}

void shift(int &a, int &b){
	int aux = a;
	a = b;
	b = aux;
}

int partition(std::vector<int> &vec, int l, int r){
	int i, pivot = vec[l], pos = r + 1;
	for (i = r; i >= l; i--){
		if (vec[i] >= pivot){
			pos--;
			shift(vec[i], vec[pos]);
		}
	}
	return pos;
}

void sort(std::vector<int> &vec, int low, int high){
	if (high <= low) return;

	// Choosing the pivot and switching.
	int i = partition(vec, low, high);

	sort(vec, low, i-1);
	sort(vec, i+1, high);
}

int main(){
	std::vector<int> vec = {6, 8, 10, 9, 5, 2, 7, 3, 1, 4};
	int low = 0, high = vec.size()-1;

	std::cout << "\n== Vector before quicksort ==\n";
	printVector(vec);

	sort(vec, low, high);

	std::cout << "\n== Vector after quicksort ==\n";
	printVector(vec);
}
