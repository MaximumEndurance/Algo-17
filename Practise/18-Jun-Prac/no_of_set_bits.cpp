#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int no_of_set_bits(int n) {
	int count = 0; 
	while(n!=0){
	if(n & 1) ++count;

	n/=2;
}
	return count;
}
int main() {
	int n;
	cin >> n;
	cout<< no_of_set_bits(n)<<endl;
}