#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const unsigned size = 1000000;

int count_arr[size] ={}	;

int main() {
	int n;
	 cin >> n;
	 int a[size];

	 for(int i = 0;i<n;++i) {
	 	cin >> a[i];
	 	count_arr[a[i]]++;
	 }
	 // cout<<"in"<<endl;
	 // for(int i=0;i<n;++i)
	 // 	cout<<count_arr[i]<<' ';

	 for(int i =0;i<size;++i) {
	 	// cout<<" "<<count_arr[i];
	 	while((count_arr[i]) != 0) {
	 		cout<<i<<' ';
	 		--count_arr[i];
	 	}
	 }
	 cout<<endl;		
}