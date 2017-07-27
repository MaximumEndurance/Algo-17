#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define vi std::vector<int>

vi stockSpan(int price[], int n) {
	stack<int> s;
	vi vec;
	int best  =0 ;
	for(int i =0; i<n;++i) {
		
		while(!s.empty() && price[i] > price[s.top()]) {
				cout<<price[s.top()]<< ' ';
				s.pop();
				best = i;
		}
		cout<<i<<endl<<endl;
		// cout<<"yu "<<s.top()<<endl;
		s.empty() ? cout<<'\0' : cout<<"te "<<price[s.top()]<<endl;

		s.push(i);
		vec.push_back(i-best);
	}

	return vec;
}

void print(stack<int>& s) {
	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
	cout<<endl;
}

void printL(int x) {

	cout<<x<<' ';
}

int main() {
	int n;
	cin >> n;

	int price[n];

	for(int i  =0;i<n;++i)
		cin >> price[i];

	vi vec = stockSpan(price, n);

	//print(s);
	cout<<"her"<<endl;
	for_each(price, price+n, printL);

	// for_each(vec.begin(), vec.end(), printL);
	cout<<endl;	
	for(vi::iterator ii =vec.begin(); ii!=vec.end(); ++ii)
		cout<<(*ii) <<' ';
}