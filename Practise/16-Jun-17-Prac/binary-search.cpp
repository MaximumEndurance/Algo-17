#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


template <typename T>

T binary_search(T arr[], int begin, int end, T key) {

	if(begin > end){
		return -1;
	}

	int mid = (begin + end)/2;

	if(arr[mid] == key)	{
		return mid;
	}

	else if(arr[mid] < key){
		return binary_search(arr, mid+1, end, key );
	}

	else{

		return binary_search(arr, begin, mid-1, key);
	}
}



int main() {
	
	//double arr[] = {-9.0, -1.0, 45.0, 233.0, 1222.0, 1224.0};
	int arr[] = {2, 5, 7, 12, 14, 16, 18, 20, 22};
	cout<< "Key found at "<< binary_search(arr, 0, (sizeof(arr)/sizeof(int))-1, 7)<<endl;
}