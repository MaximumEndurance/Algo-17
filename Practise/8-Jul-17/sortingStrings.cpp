#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	char* a[n];

	for(int i =0 ; i<n;++i) {
		cin >> a[i];
		a[i] = a[i] + 'A' + '\0';
	}

	sort(a, a+n);
	
	for(int i =0 ; i<n;++i) {

		cout << a[i]<<'\b<<endl;
	}	
}
