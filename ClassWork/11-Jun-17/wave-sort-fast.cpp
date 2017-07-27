#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void wave_sort(int a[], int n) {
	for(int i =0;i<n; i+=2) {
		if( (i-1>0) && a[i] < a[i-1] )
			swap(a[i], a[i-1]);

		else if((i+1<n && a[i]<a[i+1]))
			swap(a[i], a[i+1]);
		}
}
int main() {
	int arr[] = {-2, 4, 9, 2, 11, 0};
	wave_sort(arr, sizeof(arr)/sizeof(int));

	for(int i = 0;i<sizeof(arr)/sizeof(int); ++i)
	cout<<arr[i]<<' '; 	

}