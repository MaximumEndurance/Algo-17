#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char n[10000];

bool isGreater(char str[], int beg) {
	if(str[beg] == '\0') {
		return false;
	}

	if(str[beg] == n[beg]) {
		return isGreater(str, beg+1);
	} 

	if(str[beg] > n[beg]) {
		return true;
	}
	else
	return false;
}
static 	bool found = 0;

void permu(char str[], int beg) {
	if(str[beg] == '\0') {
		//cout<<str<<endl;
		if(found!=1) {

			for(int i = 0;i<strlen(n);++i) {
				if(str[i] > n[i]) {
					cout<<str<<endl;
					found =1;
					break;
				}
				else if(str[i] < n[i])
					break;
		}
	}
		return;
	
}

	for(int i = beg; i< strlen(str); ++i) {
		swap(str[i], str[beg]);


		permu(str, beg+1);

		swap(str[i], str[beg]);
	}
}

int main() {
	cin >> n;

	permu(n, 0);	
}