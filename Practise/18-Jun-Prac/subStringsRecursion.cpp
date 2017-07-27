#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char result[100];

void subString(char s[], int beg, int res_index) {
	if(s[beg] == '\0') {
		result[res_index] = '\0';
		cout<<result<<endl;
		return;
	}
	result[res_index] = s[beg];
	subString(s, beg+1, res_index+1);
}

int main() {
	char s[100];
	cin >> s;

	for(int i=0;s[i];++i) {
		result[0] = s[i];
		subString(s, i, 1);
		cout<<"\n\n"<<endl;
	}
}