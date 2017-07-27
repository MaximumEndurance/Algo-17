#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pi;

int getEveryOneXored(int a[], int n, int beg=0) {	
	int xored = 0;
	while(beg!=n) {
		xored = a[beg] ^ xored;
		++beg;
	}
	return xored;
}

pi twice(int a[], int n) 
{
	int x_xor_y = getEveryOneXored(a, n);
	//cout<<x_xor_y<<endl;
	int first_set_bit = x_xor_y & (-x_xor_y);
	int no1 = 0;
	for(int i=0;i<n;++i) {
		if(a[i] & first_set_bit != 0) {
			no1 = no1 ^ a[i];
		}
	}

	int no2  = x_xor_y ^ no1;
	pi p(min(no1, no2), max(no1, no2));
	return p;	
		
}

int main() {
	int n;
	cin >> n;

	int temp = 0;

	int a[n];
	
	while(temp!=n) {
		cin >> a[temp++];
	}
	pi p = twice(a, n);

	cout<<p.first<<" "<<p.second<<endl;

}