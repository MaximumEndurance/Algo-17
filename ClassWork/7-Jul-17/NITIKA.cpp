#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		string str;
		getline(cin, str);
		vector<int> vec;
		int spacecount = 0;

		for(int i =0;i<str.length();++i) {
			if(str.at(i)>='A' && str.at(i)<='Z') {
				str.at(i) = char(str.at(i) + 32);
			}
			if(str.at(i) == ' ') {
				vec.push_back(i);
				++spacecount;
			}
		}
		if(spacecount == 0){
			cout<<(char(str[0] - 32));
			for(int i = 1;i<str.length();++i)
				cout<<str[i];
		}

		if(spacecount == 1) {
			cout<<(char(str[0] + 32))<<". ";
			for(int i = vec[0]+1; i<str.length();++i) {
				cout<<str[i];
			}
		}

		if(spacecount == 2) {
			cout<<(char(str[0]+	32));
			cout<<(str[vec[0]])<<". "<<str[vec[1]]<<". ";
			for(int i = vec[0]+1; i<str.length();++i) {
				cout<<str[i];
			}
		}
		cout<<endl;	
		vec.clear();

	}
}