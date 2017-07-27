#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char result[1000];
int times = 0;
void allCodes(char str[], int beg, int res_index) {
	if(str[beg] == '\0') {
		 if(times++ == 0) {
            result[res_index] = '\0';

            cout<<"["<<result;
            return;
        }
		result[res_index] = '\0';
		cout<<", "<<result;
		return;
	}

	int digit1 = str[beg] - '0';

	char c1 = char(digit1 + 'a' - 1);

	result[res_index] = c1;

	allCodes(str, beg+1, res_index+1);

	int digit2 = str[beg] - '0';
	int num = digit1*10 + digit2;

	if(num<=26) {
	char c2 = char(num + 'a' - 1);
	result[res_index] = c1;
	result[res_index+1] = c2;
	

	allCodes(str, beg+1	, res_index+2);
}
}

int main() {
	char str[1000];
	cin >> str;
	allCodes(str, 0, 0);
	cout<<"]";
}