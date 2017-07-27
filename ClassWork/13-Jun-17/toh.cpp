/*void toh(src, dest, helper, n) {
	cout << "Move "<< "disk "<< endl;

	toh( helper , dest, src, n-1);
}
*/
//Complexity Time 2^n
// Space 0(n)
// Time complexity cannot be reduced if their are redundant steps.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void toh(int n, char src, char dest, char help) {
	if(n == 0 )	return;
	toh(n-1, src, help, dest);

	cout << "Move disk "<<n<< "th from "<<src<<" to "<<dest<<endl;

	toh(n-1, help, dest, src);
}
int main() {
	int n;
	cin >>n;

	toh(n, 'A', 'B', 'C');
}