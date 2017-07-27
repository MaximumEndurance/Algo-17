#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareByLength(string str1, string str2)	{
	return str1.length() < str2.length();
}

int main() {
	std::vector<string> v;
	int n, i;
	cin >> n;
	v.resize(n);
	

	for(i=0;i<n;++i)
		cin >> v[i];

	sort(v.begin(), v.end(), compareByLength);

	cout << "Sorted Awesomeness" <<endl;

	for(i=0;i<n;++i)
		cout << v[i] <<endl;

}