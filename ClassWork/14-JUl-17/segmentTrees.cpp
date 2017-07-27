#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000;

int arr[N];
int tree[3*N];

int left(int i) { return i>>1; }
int right(int i) { return (i<<1) + 1;}

void build(int root, int be, int end) {
	if(be > en) {
		return;
	}

	if(be == en) {
	tree[be] = arr[be];
	return;
		}

	int mid = (en+be)/2;

	build(tree[left(root)], be, mid);
	build(tree[right(root)], mid+1, en);

	tree[root] = min(tree[left(root)], tree[right(root)]);
}

void update(int root, int beg, int end, int key, int val) {

	if(en == be) {
		tree[root] = val;
		return;
	}

	int mid = (end+beg)/2;

	if(mid <= key) {
	update(tree[left(root)], beg, mid);
	}

	else {
	update(tree[right(root)], mid+1, end);
	}
	
	tree[root] = min(tree[left(root)], tree[right(root)]);


}

int search(int root, int beg, int end, int i, int j) {
	if(i>en || j>be) {
		return;
	}

	if(i<en && be<en) {
		return search(root, be);
	}

}

int main() {
	int arr[] = {2, 3, 4 ,51 , 23};

	
	update(0, 0, sizeof(arr)/sizeof(arr[0]), 2, 90);
}