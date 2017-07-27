#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define uint unsigned

	char result_arr[100];

void combos(char arr[], int curr_index, int result_index) {
	if(arr[curr_index] == '\0')	{
		result_arr[result_index] = '\0';
		cout << result_arr<<endl;
		return;
	}

	unsigned digit = arr[curr_index] - '1' + 1;

	result_arr[result_index] = digit + 'A' - 1;

	combos(arr, curr_index+1, result_index+1);

	if(arr[curr_index+1] == '\0')	return; 	//means we are at the last digit

	unsigned next_digit = arr[curr_index+1] - '1' + 1;
	unsigned next_no = 10*digit + next_digit;

	if(next_no > 26)	return;

	result_arr[result_index] = next_no + 'A' - 1;

	combos(arr, curr_index+2, result_index+1);
}

int main() {
	char arr[100];
	cout << "Enter digit string ";
	cin >> arr;
	combos(arr, 0, 0);
}