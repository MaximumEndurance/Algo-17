#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareByLength(string str1, string str2)	{
	return str1.length() < str2.length();
}

bool compareByLengthSpacesIncluded(string str1, string str2)	{
	size_t spaces_in_string1 = count(str1.begin(), str1.end(), ' ');
	size_t spaces_in_string2 = count(str2.begin(), str2.end(), ' ');
	return (str1.length() - psaces_in_string1) < (str2.length() - spaces_in_string2);
}
/*bool compareChars(string str1, string str2) {


	return
}*/

int main() {
	std::vector<string> v;
	int n, i;
	cout << "No. of strings ";
	cin >> n;
	v.resize(n);
	

	for(i=0;i<n;++i)	{
		//cin.get(*std::cout.rdbuf());	
	getline(cin, v[i]);
		// removing spaces;
		//string str = v[i];
		//str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
		//v[i] = str;
	}



	sort(v.begin(), v.end(), compareByLengthSpacesIncluded);

	cout << "\nSorted Awesomeness" <<endl;

	for(i=0;i<n;++i)
		cout << v[i] <<endl;
}

