#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <iterator>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> ss;
	int arr1[n], arr2[n];

	for(int i = 0;i<n; ++i) {
		cin >> arr1[i];
		ss.insert(arr1[i]);
	}

	for(int i = 0;i<n; ++i) {
		cin >> arr2[i];
	}

	cout<<'[';
	//bool is_executed = 0;
	set<int>::iterator ii;
	
	for(ii = ss.begin(); ii!= --ss.end(); ++ii){
		int count1 = count(arr1, arr1+n, *ii);
		int count2 = count(arr2, arr2+n, *ii);

		if(count1 && count2) {
			for(int i = 0;i<min(count1, count2);++i) {
				//is_executed = 1;
				cout << (*ii) <<", ";
			}
		}
	}
	    
	    int count1 = count(arr1, arr1+n, *ii);
		int count2 = count(arr2, arr2+n, *ii);

		if(count1 && count2) {
			for(int i = 0;i<min(count1, count2);++i) {
				//is_executed = 1;
				cout << (*ii) <<"]";
			}
		}

#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <iterator>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> ss;
	int arr1[n], arr2[n];

	for(int i = 0;i<n; ++i) {
		cin >> arr1[i];
		ss.insert(arr1[i]);
	}

	for(int i = 0;i<n; ++i) {
		cin >> arr2[i];
	}

	cout<<'[';
	//bool is_executed = 0;
	set<int>::iterator ii;
	
	for(ii = ss.begin(); ii!= --ss.end(); ++ii){
		int count1 = count(arr1, arr1+n, *ii);
		int count2 = count(arr2, arr2+n, *ii);

		if(count1 && count2) {
			for(int i = 0;i<min(count1, count2);++i) {
				//is_executed = 1;
				cout << (*ii) <<", ";
			}
		}
	}
	    
	    int count1 = count(arr1, arr1+n, *ii);
		int count2 = count(arr2, arr2+n, *ii);

		if(count1 && count2) {
			for(int i = 0;i<min(count1, count2);++i) {
				//is_executed = 1;
				cout << (*ii) <<"]";
			}
		}

}