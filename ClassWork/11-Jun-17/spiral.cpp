#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define vvi vector< vector<int> >

size_t no_of_rows, no_of_cols;

void goSpiral(vvi& vec, int  count, int currRow, int currCol)	{
	cout<<"within"<<endl;

	if(currRow >=no_of_rows || currCol >= no_of_cols)

	if((no_of_rows & 1 == 0) && (count+1 == no_of_rows-1 || count+1 == no_of_cols-1)){
		cout<<vec[(no_of_rows-1)/2][(no_of_cols-1)/2]<<endl;
		return;
	}

	int i, j;
	//cout<<"wi"<<endl;
	for(j=count; j<no_of_cols-count; ++j) 
		cout<< vec[count][j]<<", ";
	cout<<"within1"<<endl;
	for(i=count+1; i<no_of_rows-count; ++i) 
		cout<< vec[i][no_of_cols-1-count]<<", ";
	cout<<"withinq2"<<endl;
	for(j=no_of_cols-2-count;j>=count; --j)
		cout<<vec[no_of_rows-1-count][j]<<", ";
	cout<<"within3"<<endl;

	for(i=no_of_rows-2-count; i>count;--i)
		cout<<vec[i][count]<<", ";

	cout<<"within4"<<endl;
	cout << endl;
	goSpiral(vec, count+1);
	
}

int main() {
	int okcount = 0;
	const int size = 4;
	vvi vec(size);
	int i, j;
	//vec.resize(9);
	for(i=0;i<size;++i)
		for(j=0;j<size;++j){
					//cout<<"hey"<<endl;
 
			vec[i].push_back(++okcount);

		}

	no_of_rows = vec.size();
	no_of_cols = vec[0].size();
		
		//cout<<"hey1"<<endl;
	goSpiral(vec, 0);

	cout << "Original matrix" <<endl;

	for(i=0;i<size;++i) {
		for(j=0;j<size;++j) {
			cout<< vec[i][j] << ", ";
		}
		cout<<endl;
	}
		//cout<<endl;
	}
