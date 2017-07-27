#include<iostream>

using namespace std;

int getmoves(int num) {
    if(num == 0)    return 0;
    if(num & 1) {
    return 1+getmoves(num>>1);
    }
    else {
        return getmoves(num>>1);
    }
}

int main() {
    int t;
     cin >> t;
     
     while(t--) {
         int n;
         cin >> n;
         
         cout<<getmoves(n)<<endl;
     }
	return 0;
}