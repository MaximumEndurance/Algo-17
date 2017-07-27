#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class more {
	public:
		bool operator()(int x, int y) {
			return (x>y);
		}
	};

void printMax(priority_queue<int> q) {
	if(q.empty())	return;
	cout<<q.top()<<' ';
	q.pop();
	printMax(q);
}

void printMin(priority_queue<int, vector<int>, more> q) {
	if(q.empty())	return;
	cout<<q.top()<<' ';
	q.pop();
	printMin(q);
}
int main() {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, more> minHeap;

	int n;
	while(cin >> n && n!=0) {
		maxHeap.push(n);
			if(n!=-1) {
			if(maxHeap.size() && (maxHeap.size() - minHeap.size() >= 2)) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}

			else if(maxHeap.size() && minHeap.size() && (maxHeap.top() > minHeap.top())) {
				int temp =maxHeap.top();
				maxHeap.pop();
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(temp);
				}
			}
		else if(maxHeap.size()) {
			cout<<maxHeap.top()<<endl;
			maxHeap.pop();
				int temp =maxHeap.top();
				maxHeap.pop();
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(temp);

				if(maxHeap.size() && minHeap.size() && (maxHeap.top() > minHeap.top())) {
				int temp =maxHeap.top();
				maxHeap.pop();
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(temp);
				}
			}
		// cout<<"maxHeap"<<endl;

		// printMax(maxHeap);

		// cout<<"minHeap"<<endl;
		// printMin(minHeap);
		}

	}
