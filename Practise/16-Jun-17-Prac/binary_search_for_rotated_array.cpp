#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


template <typename T>

T binary_search(T arr[], int begin, int end, T key, int shift) {

	if(begin-shift > end-shift){
		return -1;
	}

	int mid = (begin - shift + end)/2;

	if(arr[mid] == key)	{
		return mid;
	}

	else if(arr[mid] < key){
		return binary_search(arr, mid+1, end, key, shift );
	}

	else{
		return binary_search(arr, begin, mid-1, key, shift);
	}
}


int main() {
	
	//double arr[] = {-9.0, -1.0, 45.0, 233.0, 1222.0, 1224.0};
	int arr[] = { 12, 14, 16, 18, 20, 22, 2, 5, 7};
	//cout<< "Key found at "<< binary_search(arr, 0, (sizeof(arr)/sizeof(int))-1, 7)<<endl;

	//checking for index from where the real rotated array starts.
	int i;
	int n = (sizeof(arr)/sizeof(int));
	for(i = 0;i<n-1;++i) {
		if(arr[i] > arr[i+1])
			break;
	}
	// So i+1 represented the shift

	cout<< "Key found at "<< binary_search(arr, 0+(i+1), (n-1+(i+1))%n, 7, i+1)<<endl;

}