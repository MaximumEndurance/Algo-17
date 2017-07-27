#include <iostream>

using namespace std;

typedef long long ll;

char str[100];

void inBinary(int num, int i = 0) {
	if(num == 0) {
		str[i] = '\0';
		return;
	}
	str[i++] = num%2;
	num >> 1; 
	inBinary(num, i);
}


int main() {
	int x, y;
	cin >> x >> y;

	int notofy = ~y;

	if(notofy > x) {
		cout<<(y^notofy)<<endl;
		return 0;
	}

	int max = 0;
	while(x != y) {
		int val = x^y;
		if(val > max) {
			//inBinary(y)<<endl<<inBinary(x)<<endl;
			//cout<<"in "<<x<<endl;
			max = val;
		}
		++x;
	}
	cout<<max<<endl;
	}