#include <iostream>
#include <cstring>

using namespace std;

void subStrings(char str[], int beg, int iterate_till) {
	if(str[iterate_till] == '\0')
		return;

	for(int i = beg ;i<=iterate_till;++i) {
		cout<<str[i];
	}

	cout<<' ';


	subStrings(str, beg, iterate_till+1);
}


int main() {
	char str[1000];
	cin >> str;
	
	int len = strlen(str);

	for(int i = 0; i<strlen(str); ++i) {
	subStrings(str, i, i);
	cout<<endl;
	}
}
