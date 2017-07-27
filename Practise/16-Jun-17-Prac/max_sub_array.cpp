#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

unsigned index_of_right_bound, index_of_left_bound;

void max_sub_array(int a[], int n) {
	int general_sum =0, max_sum =0;
	index_of_right_bound = 0;

	for(int i = 0;i<n;++i) {
		general_sum += a[i];

		if(general_sum > max_sum) {
			max_sum = general_sum;
			index_of_right_bound = i;
			//cout<<"index_of_right_bound"<<index_of_right_bound<<endl;
		} 

	}

	//figuring out the left bound
	index_of_left_bound = index_of_right_bound;
	general_sum = 0;
	max_sum = 0;

	for(int i = index_of_right_bound;i>=0; --i) {
		general_sum += a[i];

		if(general_sum > max_sum){
			max_sum = general_sum;
			index_of_left_bound = i;
		}
	}
}

void print(int arr[]) {

	cout<<"Left bound "<<index_of_left_bound<<"\nRight bound "<<index_of_right_bound<<endl;

	for(int i = index_of_left_bound;i<=index_of_right_bound;++i)
		cout<<arr[i]<<' ';

	cout<<endl;
}

int main() {
	freopen("max_sub_array.in", "r", stdin);

	int t;
	cin >> t;

	int a[10000];

	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;++i) {
			cin >> a[i];
		}

			max_sub_array(a, n);

			print(a);

		// printing


		}
	
}