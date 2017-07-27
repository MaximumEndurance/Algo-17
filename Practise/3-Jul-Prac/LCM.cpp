#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll HCF(ll n ,ll m) {

		if(m == 0)	{
			return n;
		}
	return HCF(m, n%m);
}

ll LCM(ll n, ll m) {
	return (max(n, m)/HCF(n, m) * min(n, m));
}

int main() {
	ll n1, n2;
	cin >> n1>> n2;
	cout<<LCM(n1, n2)<<endl;	
}