#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minPages(int pages[], int students, int beg, int end) {
	int atmost = (beg+end)/2;

	int sum = 0, i=0, nstudents=0;
	
	while(nstudent < students) {
		int tempsum = 0;
		while((tempsum + pages[i]) < atmost)
			tempsum += pages[i++];
	sum += tempsum;
	++nstudent;
	}

	
	if(sum == accumulate(pages+beg, pages+end+1, 0){
		return minPages(pages, students, beg, mid-1);  
	}

	else{
		return minPages(pages, students, atmost+1, end);
	}
}

int main() {
	int n;
	 cin>> n;

	 for(int i =0;i<n;++i)
	 	
	int sum = accumulate(pages, pages+n, 0);
	
	int pages[n];

	for(int i = 0;i<n;++i)
		cin >> a[i];

	int students;
	cin >> students;

	cout<<minPages(pages, students, 0, n-1)<<endls;
}
