#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string result;
vector<string > vec;
//char finalresult[25][25];
//unsigned final_result_index = 0;

void subseq(string arr, int beg, unsigned result_index) {
    
    if(arr[beg] == '\0') {
        //result[result_index]= '\0';
        vec.push_back(result);
        //finalresult[final_result_index++] = result;
        return;
    }
   
   subseq(arr, beg+1, result_index); 
   result[result_index] = arr[beg];
   subseq(arr, beg+1, result_index+1);
}

int main() {
    int n;
    cin >> n;
    
    while(n--) {
        string arr;
        cin >> arr;
        subseq(arr, 0, 0);
        sort(vec.begin(), vec.end());
        
        for(vector<string>::iterator ii = vec.begin(); ii!=vec.end(); ++ii)
            cout<<(*ii) <<endl;
    }
}
