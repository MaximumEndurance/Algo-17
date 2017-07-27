#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


string replacePi(string& org, string b, string c) {
	cout << org <<endl;
	if(org == "" || org.length() < b.length())
		return "";
	else if(org.substr(0, b.length()) == b)	{
		org = c + org.substr(b.length(), string::npos);
		return replacePi(org, b, c);
	}
	else {
		org = org.substr(b.length()-1, string::npos);
		return replacePi(org, b, c);
	}
	
}

int main() {
	cout<< "Enter string to replace with" <<endl;
	string str;
	getline(cin, str);
	str=replacePi(str, "Pi", "3.14");
	cout << str << endl;
}