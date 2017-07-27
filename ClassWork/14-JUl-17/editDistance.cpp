#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s1, s2;

int editDistance(string s1, int i, string s2, int j) {

		if(i<0) {
			return j+1;
		}
		if(j<0){
			return i+1;
		} 
	
	if(s1[i] == s2[j]) {
		return editDistance(s1, i-1, s2, j-1);
	}
	return min(editDistance(s1, i, s2, j-1), min (editDistance(s1, i-1, s2, j) , editDistance(s1, i-1, s2, j-1))) + 1;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	cout<<editDistance(s1, s1.length()-1, s2, s2.length()-1)<<endl;	
}