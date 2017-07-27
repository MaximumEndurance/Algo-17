#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll no_of_setBits(ll n, int count = 0) {
	if(n==0) return count;

	return no_of_setBits((n&n-1), count+1);
}
int main() {
	ll n;
	cin >> n;

	cout<<no_of_setBits(n)<<endl;
}