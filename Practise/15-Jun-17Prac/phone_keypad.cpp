#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const string arr_all[] = {".,", "abc", "def",
						"ghi", "jkl" ,"mno",
						"pqrs", "tuv", "wxyz"};

char result_arr[100];

void keypad(char arr[100], int curr_loc, unsigned result_index) {

	if(arr[curr_loc] == '\0'){
		result_arr[result_index] = '\0';
		cout << result_arr << endl;
	}
	int digit = arr[curr_loc] - '0';
	string required = arr_all[digit];

	for(int i = 0; i<required.length(); ++i){
		result_arr[result_index] = required[i];
		keypad(arr, curr_loc+1, result_index+1) ;
	}
}

int main() {
	cout<< "Enter string ";
	char inp_arr[100];
	cin >> inp_arr;
	keypad(inp_arr, 0 ,0);
}