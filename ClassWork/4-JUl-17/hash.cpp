#include <iostream>
#include <string>

using namespace std;

class Node {
	public:
		string key;
		int data;
		Node* next;

		Node(){}

		Node(string s, int d) {
			key = s;
			data = d;
			next = NULL;
			n=0;
		}

		~Node() {
			if(next != NULL)	delete next;
		}
	};

class hashTable {
		Node** table;
		int size;
		int n; 	// no of elements

		int hashTable(string s) {
			//"abc" = a*37^0 + b*37^1 + ....
			int prime = 37;
			int primeval= 1;
			int idx = 0;
			int result = 0;
			while(pow<=s.length()) {
				result += s[idx] * (prime);
				primeval *= prime;  
				++idx;
			}
			return result;
		}

		void rehash() {
			size oldsize = size;
			size *= 2;

			Node** oldTable = table;
			Node** newTable = new Node*[newSize];

			for(int i =0; i<oldsize; ++i) {
				node* ll = oldtable[i];

				while(ll) {
					node* temp =ll;
					ll =ll->next;
					temp->next = NULL;
					insert(tmp);
				}
			}
			delete [] oldtable[i];
		}

	public:
		hashTable() {
			size = 7; //any prime no
			table = new Node*[size];
		}

		void push(string s, int d) {

			Node* newEle = new Node(s, d);
			int idx = hash_function(s);

			//inserting the new element

			newEle->next = table[idx];
			table[idx] = newEle;
			++n;

			if(load_factor >= 0.7) {
				rehash();
			}
		}

		int getData(string s) {
			int idx = hash_function(s);

			Node* cur = table[idx];

			while(cur) {
				if(cur.key == s) {
					return cur.data;
				}
				cur = cur->next;
			}
			return -1;	//bhai data ni mila 
		}

		bool empty() {
			return (n==0);
		}

		int getSize() {
			return n;
		}

		void remove(string s) {

			if(n==0)	return;

			int idx = hash_function(s);

			//Node* to_delete = table[idx]; 	//returns a Node at this index

			Node* curr = table[idx];
			Node* prev = NULL;

			while(curr) {
				prev = curr;
				if(curr->key == s) {
					if(prev) 
						prev->next = curr->next;
						curr->next = NULL;

					else {
						cur = cur->next;
					}
				}
			}
		}
	};

int main() {
	
}