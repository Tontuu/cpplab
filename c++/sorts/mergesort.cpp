#include <iostream>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r){
	// Compare the arrays number by number and put those numbers in the original
	// array.
	
	// Notice that 'n=r-l+1' refers to number 10 (as example), but we will get number 9
	// that wouldn't work in a loop or would output an error like core dumped.
	int i=l, j=m+1, k=0, n=r-l+1, temp[n];


	// Using 10 as example again, m = 4 & r = 9. To merge, we increment the index
	// of subdivision itself only when the comparison is done, so arr[i](3) < arr[j](1)
	// we assign to the temp array and increment i index or j index.
	while(i<=m && j<=r){
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	// We do it all again but now individually, the last while avoided comparisons
	// of divisions already sorted.
	while(i<=m){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}


	// Assign the temp array into the original.
	for(i=l;i<=r;i++){
		arr[i]=temp[i-l];
	}
}

void mergesort(int arr[], int l, int r){
	// as merge Sort works like a tree creating several subdivisions, when we reach
	// only 1 value in that subdivision, the recursion ends.
	if (l>=r) return;	

	int m = (l+r)/2;

	
	mergesort(arr, l, m);
	mergesort(arr, m+1, r);
	merge(arr, l, m, r);
}

void display(int arr[], int size, bool before){
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	(before) ? std::cout << "\nCurrent array\n" :
		std::cout << "\nSorted array\n";

	for (int i=0;i<size;i++){
		std::cout << "[" << arr[i];
		if (i == size-1) std::cout << "]\n\n";
		else std::cout << "]..";
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

int main(){

	system("clear");
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	std::cout << "            MERGE SORT           \n";
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
	std::cout << "[1] - Random numbers.\n";
	std::cout << "[2] - Choose numbers.\n";
	std::cout << "[3] - Exit.\n\n";
	std::cout << "Choose: ";


	int choice, size;
	std::cin >> choice;
	system("clear");

	switch (choice){
		case 1: 
			{
				bool show;
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
				std::cout << "Size of the array: ";

				std::cin >> size;

				std::cout << "\nDisplay array? [0/1]:";
				std::cin >> show;
				system("clear");

				int arr[size];

				srand(time(NULL));
				for (int i=0;i<size;i++){
					arr[i]=rand()%100;
				}

				if (show) display(arr, size, true);
				mergesort(arr, 0, size-1);
				if (show) display(arr, size, false);

				break;
			}
		case 2: 
			{
				std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
				std::cout << "Size of the array: ";
				std::cin >> size;
				std::cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";

				int arr[size], number;
				int i = 0;

				while(i <= size-1){
					std::cout << "\nEnter number " << i+1 << ": ";
					std::cin >> number;
					arr[i]=number;
					i++;
				}
				system("clear");

				display(arr, size, true);
				mergesort(arr, 0, size-1);
				display(arr, size, false);

				break;
			}
		
		case 3:
			{
				break;
			}
		default:
			{
				break;
			}
	}
}
