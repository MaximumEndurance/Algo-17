#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll no_of_bits_in_no(ll n, int count = 0){
	if(!n) return count;

	return no_of_bits_in_no(n>>1, count+1);
}

ll sum_of_set(ll n) {

	int count = no_of_bits_in_no(n);
	cout<<count<<endl;
	--count;
	return (1<<(count) + (n&1?0:1));
}

int main() {
	ll n;
	cin >> n;

	cout<<sum_of_set(n)<<endl;
}