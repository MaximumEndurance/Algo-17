#include <iostream>

using namespace std;

class Vvector {	//class is templated on T
	int curr;
	int max_curr;
	static int default_size;
	int custom_size;
	int* v1 = NULL;
	int* newVec = NULL;


	void assignOn() {
			newVec = new int[max_curr*2];
		

		for(int i = 0;i<curr;++i) {
			newVec[curr] = v1[curr];
		} 
		delete [] v1;	//truncate hua delete nahi. So, naam hai v1 but is still khaali.
		v1 = newVec;	//v1 is now pointing to newVec
		max_curr *= 2;
		
	}

public:
	Vvector() {
		default_size = 10;
		v1 = new int[default_size];
		max_curr = default_size;
		curr = 0;
		cout<<"default"<<endl;
	}

	Vvector(int n) {
		v1= new int[n];

		max_curr = n;
		curr= 0;	//initialise as zero here
	}


	size_t size() {
		return curr+1;
	}


	void push_back(int num) {
		if(curr < max_curr) {	//indexing starts from zero
			v1[curr] = num;
			++curr;
		}
		else {
			
			assignOn();
			v1[curr] = num;
		}
	}

	int pop_back() {
		if(curr >= 0) {
		return v1[curr];
		curr--;
	}
	else{
		cout<<"No element in vector"<<endl;
		return -123; 	
	}
}

};

void operator<<(int * a) {
	for(int i =0;i<a.size(); ++i) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

int main() {
	cout<<V;
	//Vvector<int> v2;	// Now its templated on int 
	Vvector v2;
}

 