#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int setBits(int num) {
	if(!num) return 0;

	if(num & 1)
	return 1+setBits(num/2);
	else
		return setBits(num/2);
}

int main() {
	int num;
	cin>>num;
	cout<<setBits(num)<<endl;
}