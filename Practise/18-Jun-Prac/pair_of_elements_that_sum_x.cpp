#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int x;
	cin >> x;
	
	//cin >> n;
	
	int arr[] = {2, 3, 4, 5, 6, 7, 8 };
	int n = sizeof(arr)/sizeof(int);

	int arr2[n+1]= {};

	size_t arr2_count = 0;
	for(int i = 0;i<n;++i) {
		arr2[arr[i]]++;
		//++arr2_count;
	}	//abhi dekh liya ki ye log hai ki nahi

	for(int i = 0;i<n; ++i) {
		if(x>arr[i]){
			int v = x-arr[i];	//complement kya hoga
			if(arr2[v] != 0){	// kya complement hai for every element in x
				cout<<arr[i]<<" "<<(x-arr[i])<<endl;
				arr2[v]--;
				arr2[arr[i]]--; //because complemetn bhi to kam ho rah hai
			}
		}
		//if(arr2[arr[i]])
		//	cout<<arr2[i]<<" "<<(x-arr2[i])<<endl;
	}


}