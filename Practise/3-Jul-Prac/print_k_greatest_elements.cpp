#include <queue>
#include <iostream>

using namespace std;

void print_k_greatest(priority_queue<int> q, int k) {
	while(k--) {
		cout<<q.top()<<' ';
		q.pop();
	}
	cout<<endl;
}
int main() {
	int n;
	priority_queue<int> q;
	while(cin >> n && n!=-1) {
		q.push(n);
	}
	int k;
	cin >> k;
	print_k_greatest(q, k);
}