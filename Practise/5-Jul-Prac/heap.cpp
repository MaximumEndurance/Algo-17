#ifndef _HEAP_
#define _HEAP_

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class heap
{
	int curr_index;
	vector<int> v;

	int parent(int i) { return (i >> 1);}
	int left(int i) { return (i<<1);}
	int right(int i) { return (i<<1 + 1);}

	void heapify(int index) {
		if(index < 1 || index > size)	return;

		int pos = index;

		if(v[index] > v[left(index)]) {
			pos = v[left(index)];
		}

		if(v[index] > v[right(index)]) {
			pos = v[right(index)];
		}

		if(pos == i)	return;

		swap(v[pos], v[i]);
	}
	
public:
	heap() {
		curr_index=0;
		v.push_back(-1);
	}

	void push(int val) {
		v[curr_index] = val;
		++curr_index;
		int i =curr_index;
		while(parent(i) > 0 && v[i] > v[parent(i)] ) {
			swap(v[i], v[parent(i)]);
			i=parent(i);
		}
	}

	void pop() {
		if(curr_index < 1)	return;

		swap(v[curr_index], v[1]);
		--curr_index;
		heapify(1);
	}

	int top() {
		return v[curr_index];
	}

	int size() {
		return curr_index;
	}
	~heap();
	
};
int main() {
	

