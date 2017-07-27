#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;

template<typename T>
void printContainer(T be, T end) {
	while(be!=end) {
		cout<<(*be)<<' ';
		++be;
	}
}

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

	~Graph() {	//dynamic hai varna nahi hoga
		delete [] adjList;
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
		bool* isVisited = new bool[nV+1]();	//() all are initialised to zero 

		DFS_helper(src, isVisited);
		delete [] isVisited;
	}

	void printConnected(int src) {
		bool* isVisited = new bool[nV+1]();	//() all are initialised to zero 

		for(int src = 1; src<=nV; ++src  ) {
			if(isVisited[src] == false) {
				DFS_helper(src, isVisited);
				cout<<endl;				
			}
		}
		delete [] isVisited;
	}

	void BFS(int src)  {
		bool* isVisited = new bool[nV+1];	//nV+1 since we are counting from 1. First edge is 1 and not 0
		queue<int> notVisited;

		notVisited.push(adjList[src][0]);

		while(!notVisited.empty()) {
			int currVertex = notVisited.front();
			notVisited.pop();

			cout<<currVertex<<' ';

			for(int i=0;i<adjList[currVertex].size();++i) {
				int neighbour = adjList[currVertex][i];

				if(isVisited[neighbour] == false) {
					notVisited.push(neighbour);
					isVisited[neighbour] = true;
				}
			}

		}
		delete [] isVisited;
	}

	int shortestPath(int src, int dest) {
		int * dist = new int[nV+1];
		bool* visited = new bool[nV+1]();

		queue<int> q;

		dist[src] = 0;
		visited[src] = true;

		q.push(src);

		while(!q.empty()) {

			int curr = q.front();
			q.pop();
			for(int i =0;i<adjList[curr].size();++i) {
				int neighbour = adjList[curr][i];

				if(visited[neighbour] == false) {
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[curr] + 1;
				}
			}
		}
		int ans = dist[dest];
		delete [] dist;
		delete [] visited;
		return ans;
 	}

 		vi printShortestPath(int src, int dest) {
 		int * dist = new int[nV+1];
		bool* visited = new bool[nV+1]();
		int* parent = new int[nV+1]();
		queue<int> q;

		dist[src] = 0;
		visited[src] = true;

		q.push(src);

		while(!q.empty()) {

			int curr = q.front();
			q.pop();
			for(int i =0;i<adjList[curr].size();++i) {
				int neighbour = adjList[curr][i];

				if(visited[neighbour] == false) {
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[curr] + 1;
				}
			}
		}
		// int ans = dist[dest];
		vi ans;

		int i = dest;
		ans.push_back(i);

		while(i!=src) {
			ans.push_back(parent[i]);
			 i = parent[i];
		}
		 
		delete [] parent;
		delete [] dist;
		dede		delete [] visited;
lete [] visited;
		return ans;
 	}
};

int main() {
	Graph G(7);

	G.addEdge(1, 2);
	G.addEdge(1, 3);
	G.addEdge(2, 5);
	G.addEdge(5, 6);
	G.addEdge(6, 7);
	G.addEdge(3, 4);
	G.addEdge(5, 7);

	// G.DFS(1);
	// G.DFS(5);

	// G.addEdge(8, 0);
	// G.printConnected(1);	

	// G.BFS(1);

	// cout<<G.shortestPath(1, 7)<<endl	;

	// vi ans = G.printShortestPath(1, 7);
}