#ifndef _GRAPH_
#define _GRAPH_

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

class Graph{
	int nV;
	int nE;
	vi* adjList;	// adjList is a pointer to a vector of pointers to Nodes.

	void DFS_helper(int src, bool isVisited[]) {
	isVisited[src] = true;
	//if(adjList[src].size()==0)	return;

	cout<<src<<' ';


	for(int i =0; i<adjList[src].size(); ++i) {	
	// neighbour=adjList[src][i];//har ek ke liye. I check if my neighbour is visited or not.
		int neighbour = adjList[src][i];
		if(isVisited[neighbour] == false) {
			DFS_helper(neighbour, isVisited);
		}
	}
}

public:
	Graph(int n) {	// n will always be given
		nV = n;
		nE = 0;
		adjList = new vi[nV+1];	//returns a pointer to a vector of int
	}

	void addEdge(int v1, int v2, bool isDirectionaL = false) {
		adjList[v1].push_back(v2);	// means edge hai
		++nE;

		if(!isDirectionaL){
			adjList[v2].push_back(v1);
			++nE;
		}
	}

	void DFS(int src) {
		bool* isVisited = new bool[nV]();	//() all are initialised to zero 

		DFS_helper(src, isVisited);
	}
};

#endif