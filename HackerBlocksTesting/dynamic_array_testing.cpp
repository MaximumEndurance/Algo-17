#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int *a;
	a = new int[20]	;
	a[0] =2;
	a[1] = 3;
	cout<<(sizeof(a)/sizeof(int))<<endl;
	cout<<a[0]<<a[1]<<endl;
}

