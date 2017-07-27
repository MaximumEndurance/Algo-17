#include <iostream>

using namespace std;

const int BITS =32;
int count1[BITS] ={};

void countBits(int num) {
	int i = 0;
	while(i<32 && num!=0) {
		if(num&1 == 1) {
			count1[i]++;
		}
		++i;
	}
}

int getUnique(int a[], int n) {
	for(int i =0;i<n;++i) {
		countBits(a[i]);
	}
	int num =0 ;
	for(int i = 0;i<BITS;++i) {
		count1[i] = count1[i] % 3;
		if(count1[i] != 0) {
		num += (1<<i); 
		}
	}
	return num;

}

int main() {
	int n;
	cin >> n;

	int temp =0 ;
	int a[n];
	while(temp!=n) {
		cin >> a[temp++];
	}
	cout<<getUnique(a, n)<<endl;

}