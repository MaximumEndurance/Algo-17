#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>class heap {
	int size;
	vector<T> v;
	int parent(int i) { return i >> 1;}
	int left(int i) { return i<< 1;}
	int right(int i) { return (i<<1 + 1);}

	void heapify(int i) {
		if(i >= size)	return;

		int pos = i;

		if(left(i) <= size && v[left(i)] < v[pos]) {
			pos =left(i);
		}
		if(right(i) <= size && v[right(i)] < v[pos]) {
			pos = right(i);
		}

		if(pos == i) {
			return;
		}

		swap(v[pos], v[i]);
		heapify(pos);
	}

public:
	heap() {
		// T def_val = T('\0');
		// v.push_back(def_val);
		v.push_back(T());	//int 
		size = 0;
	}

	void push(T data) {
		v.push_back(data);
		++size;

		int i =size;

		while(parent(i) >= 1 && v[i] < v[parent(i)]) {	//parent 1 se aage ja chuka hai
			swap(v[parent(i)], v[i]);
			i = parent(i);
		}
	}

	void pop() {
		if(size < 1) {
			return;
		}
		swap(v[1], v[size]);
		--size;
		v.pop_back();
		heapify(1);
	} 

	T top() {
		if(size < 1) { return T();}
		return v[1];
	}
};

class Book {
	int ID;
	string name;
public:
	Book(){}

	Book(int id, string name1) {
		ID = id;
		name = name1;
	}

	bool operator<(const Book& B) {
		return (name.length() < B.name.length());
	}
};

int main() {
	// heap<string> h1;
	// heap<int> h1;
	// h1.push("sre");
	// h1.push("uyrye");
	// h1.push("frev");

	// h1.push(3);
	// h1.push(8);
	// h1.push(1);

		// heap<float> h1;

	// h1.push(9.8);
	// h1.push(5.6);
	// h1.push(8.2);

	heap<Book> b1(1, "Rohan");
	


	cout<<h1.top()<<endl;
	h1.pop();
	cout<<h1.top()<<endl;
	h1.pop();
	cout<<h1.top()<<endl;
}