#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


class Graph{
	int nV;
	list<int>* adjList;

	void dfs_helper(int src, bool visited[], int count = 1) {
		
		visited[src] = true;
		cout<<src<<' ';

		for(list<int>::iterator ii = adjList[src].begin(); ii!=adjList[src].end(); ++ii) {
			if(visited[(*ii)] == false) {
				dfs_helper(*ii, visited, count+1);
			}
		}
		cout<<endl;
	}
public:
	Graph(int no_of_vertices) {
		nV = no_of_vertices;
		adjList = new list<int>[nV+1];
	}

	~Graph() {
		delete [] adjList;
	}

	void addEdge(int src, int dest) {
		adjList[src].push_back[dest];


		adjList[dest].push_back[src];
	}

	void dfs(int src) {
		bool* visited = new bool[nV+1];
		dfs_helper(src, visited);
		delete [] visited;
	} 

	int connected() {
		bool* visited = new bool[nV+1];
		int count = 0;
		for(int i =0; i<nV;++i) {
			if(visited[i] == false)
				dfs_helper(i, visited);
				++count;
		}
		return count;
	}
};

int main() {

	int n, p;
	cin >> n>> p;

	Graph G(n);
	int x, y;

	for(int i = 0; i<p;++i) {
		cin >> x >> y;
		G.addEdge(x, y);
	}
}