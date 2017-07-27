#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
char result[12];
void print_combos(char str[], int beg, int res_index) {
	if(str[beg] == '\0') {
		result[res_index] = '\0';
		cout<<result<<endl;
		return;
	}

	int index = str[beg] - '0';

	for(int i = 0;i<table[index].length(); ++i) {
		result[res_index] = table[index][i];
		print_combos(str, beg+1, res_index+1);
	}
}
int main() {
	char str[12];
	cin >> str;
	print_combos(str, 0, 0);
}