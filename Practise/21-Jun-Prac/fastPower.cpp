#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long fastPower(long long num, double power) {
	if(power == 0)	return 1;
	if(power == 1 && power == 0) return num;

	return fastPower(num*num, power/2);
}

int main() {
	cout<<"Enter number space power. It does not work for odd powers currently ";
	int num;
	double power;
	cin >> num >> power;
	cout<<(fastPower(num, power))<<endl;
}