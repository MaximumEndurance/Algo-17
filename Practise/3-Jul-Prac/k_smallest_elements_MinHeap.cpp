#include <queue>
#include <iostream>

using namespace std;

class heapster{
public:
	bool operator()(int x, int y) {
		return x>y;
	}
};

void print_k_smallest(priority_queue<int, std::vector<int>, heapster> q, int k) {
	while(k--) {
		cout<<q.top()<<' ';
		q.pop();
	}
	cout<<endl;
}

int main() {
	int n;
	priority_queue<int, vector<int>, heapster> q;
	while(cin >> n && n!=-1) {
		q.push(n);
	}
	int k;
	cin >> k;
	print_k_smallest(q, k);
}