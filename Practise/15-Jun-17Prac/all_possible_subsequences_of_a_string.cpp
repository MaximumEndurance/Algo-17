#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char result_arr[100];
void combos(char arr[100], int beg, int result_index) {
	if(arr[beg] == '\0'){
		result_arr[result_index] = '\0';
		cout << result_arr << endl;
		return;
	}
	combos(arr, beg+1, result_index);

	result_arr[result_index] = arr[beg];
	combos(arr, beg+1, result_index+1);

}


int main() {
	cout << "Enter string "<<endl;
	char arr[100];
	cin >> arr;
	combos(arr, 0, 0);	
}