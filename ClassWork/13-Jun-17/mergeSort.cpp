#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Merge(int arr[], int beg, int end) {
	int count = 0 ;
	int mid = (beg+end)/2;
	int new_arr[100];
	int i =beg, j =mid+1;
	if(a[i] > a[j]) { new_arr[count++] = a[j];
	else	new_arr[count++] = a[i];
	Merge(arr, )
	return new_arr;
}

void mergeSort(int arr[], int beg, int end) {
	int mid = (beg+end)/2;

	mergeSort(arr, beg, mid);
	mergeSort(arr, mid+1, end);
	//declare temp arrays here for part 2
	Merge(arr, beg, en);
}

int main() {
	int arr[100];
	int n;
	cin >> n;

	for(i = 0;i<n ;++i)
		cin >> arr[i];

	mergeSort(arr, 0, n-1);

	for(int i = 0; i<n; ++i)
		cout<<arr[i]<<" ";

}