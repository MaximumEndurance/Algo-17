#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

double ep;

double sq_root(double num, double beg, double end, int precision) {
	
	double mid;

	if(beg > end) {
		//cout<<"Nahi bhai! Nahi ho sakta";
		return mid;
}

	mid = (beg+end)/2;
	cout<<mid<<endl;
	if(abs(mid*mid - num) < ep)	{
		return mid;
	}

	if((mid*mid - num) < ep){
		sq_root(num, mid+precision, end, precision);
	}

	else	{
		sq_root(num, beg, mid - precision, precision);
	}
}

int main() {
	cout <<"Enter No. ";
	double num;
	cin >> num;
	//cout << "Please enter precision: ";
	int precision = 3;
	ep = pow(10, -(precision+1));
	//cout<<(-(precision+1))<<endl;
	//cout<<"ep"<<ep<<endl;
	//cin >> precision;

	cout<<sq_root(num, 0, num, ep)<<endl;

	}