#include <iostream>
#include <vector>

using namespace std;

int count;

char result[1000];

void countAllSubsequences(char str[], int beg, int res_index) {
	if(str[beg] == '\0') {
		result[res_index] = '\0';
		++count;
		// cout<<result<<' ';
		// ans.push_back(result);
		return;
	}

	countAllSubsequences(str, beg+1, res_index);
	result[res_index] = str[beg];
	countAllSubsequences(str, beg+1, res_index+1);
}

void printAllSubsequences(char str[], int beg, int res_index) {
	if(str[beg] == '\0') {
		result[res_index] = '\0';
		++count;
		cout<<result<<' ';
		// ans.push_back(result);
		return;
	}

	printAllSubsequences(str, beg+1, res_index);
	result[res_index] = str[beg];
	printAllSubsequences(str, beg+1, res_index+1);
}
int main() {
	char str[1000];
	cin >> str;
	char result[1000];
	countAllSubsequences(str, 0, 0);
	cout<<count<<endl;
	printAllSubsequences(str, 0, 0);
	// for(vector<char*>::iterator ii = ans.begin(); ii!=ans.end(); ++ii){
	// 	cout<<(*ii)<<' ';
	// }
	// cout<<endl;
}