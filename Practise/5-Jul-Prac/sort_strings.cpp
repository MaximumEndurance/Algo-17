#include <iostream>

using namespace std;

bool compare(string x, string y) {
    return (x < y);
}

int main() {
    int n;
     cin >> n;
     
     string arr[n];
     int i =0;
     for(int i =0;i<n;++i) {
        cin >> arr[i];
     }
     for(int i =0;i<n-1;++i) {  

        for(int j = i; j<n-1;++j) {
         if(arr[j] > arr[j+1]) {
             swap(arr[j], arr[j+1]);
         }
        }
     }
     
     for(int i = 0;i<n;++i) {
         cout<<arr[i]<<endl;
     }
}
