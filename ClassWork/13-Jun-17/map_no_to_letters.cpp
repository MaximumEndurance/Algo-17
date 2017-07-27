#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printCombos(char inp[20], int beg) {
	if(inp[beg] == '\0']) return;

	int dig = inp[beg] - '0';
	char c = 'A' + dig - 1;

	result[ridx++] = c;
	printCombos(inp, beg+1);

	if(inp[be+1] == '') return;

	int next_digit = inp[be+1] - '0';
	int num = 10*dig + next_digit;
	if(num > 26)	 return;
	c = 'A' + num - 1; 
	result[ridx++] = c;
	printCombos(inp, beg+2);

}

int main() {
	char inp[20];
	cin >> inp;
	// prints all combinations of the given string
	printCombos(inp, 0);
}