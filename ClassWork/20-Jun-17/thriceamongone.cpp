#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void thriceAmongOne(int arr[], int n) {
	int final_xor = 0;
	for(int i =0;i<n;++i) {
		final_xor = final_xor ^ arr[i];
	}

}

int main() {
	int n;
	cin >> n;
	int a[n];
	int no[32] = {};
	for(int i = 0;i<n; ++i)
		cin >> a[i];

	for(int i =0;i<n;++i){

		int no_count=0;
		int temp =a[i];
		while(temp){
			if(temp & 1)
				no[no_count]++;
			temp/=2;
			no_count++;
		}
	}

	//for(int i =0;i<32;++i)
	//	cout<<a[i]<<' ';
	int sum = 0;
	for(int i=0;i<n;++i) {
		no[i] = no[i]%3;

		if(no[i])
			sum += int(pow(2, i));
	}

	cout<<sum<<endl;


}