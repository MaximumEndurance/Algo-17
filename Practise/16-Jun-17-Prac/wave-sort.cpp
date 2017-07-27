#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>

void wave_sort_it(T arr[], size_t n) {
	

	for(int i =1 ;i<n; i+=2) {
		if(arr[i] <= arr[i-1] && (i+1<n && arr[i] < arr[i+1]));
		else{
			T ele = min(arr[i-1], arr[i+1]);
			if(ele == arr[i-1])
			   swap(arr[i], arr[i-1]);
			else
				swap(arr[i+1], arr[i]);
		}
	}
}

template <typename T>
void print_arr(T arr[], size_t n) {
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<' ';
	cout<<endl;
}

int main() {
	int arr[] = {3, 12, 4, -2, 5, -1, 14, 15, 10};
	
	size_t arr_len = sizeof(arr)/sizeof(int);

	wave_sort_it(arr, arr_len);
	print_arr(arr, arr_len);
}