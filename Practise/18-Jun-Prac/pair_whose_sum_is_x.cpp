#include <iostream>
#include <climits>

using namespace std;

int arr2[100000] = {};

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i =0 ;i<n; ++i) {
        cin >> a[i];
        arr2[a[i]] = arr2[a[i]] + 1;
    }

     
    int target;
    cin >> target;
    
    for(int i =0 ;i<n;++i) {
        if(target-a[i] >= 0) {
            int diff = target-a[i];
            if(diff == a[i] && arr2[diff]<2)
                continue;

            if(arr2[diff]>0){
                cout<<min(a[i], diff)<<" and "<<max(a[i], diff)<<endl;
                arr2[diff] = arr2[diff] - 1;
                arr2[a[i]] = arr2[a[i]] - 1;
            }
        }
    }
   
}

