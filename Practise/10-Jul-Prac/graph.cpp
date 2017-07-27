#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Graph {
	vector<int>* adjList;
	int no_of_vertices;

	void dfs_helper(int src, bool isVisited[]) {
		std::vector<int>::iterator ii;
		isVisited[src] = true;
		cout<<src<<' ';

		for(ii = adjList[src].begin(); ii!=adjList[src].end(); ++ii) {
			int neighbour = (*ii);

			if(isVisited[neighbour] == false) {
				//visit neighbour
				dfs_helper(neighbour, isVisited);
			}
		}
	}


 	void printQueue(queue<int> q) {
 		while(!q.empty()) {
 			cout<<q.front()<<' ';
 			q.pop();
 		}
 	}
 	queue<int> q;
	void bfs_helper(int  src, bool isVisited[]) {
	 		isVisited[src] = true;

 		std::vector<int>::iterator ii;
 		while(!q.empty()) {
 			int curr = q.front();

 		for(ii = adjList[curr].begin(); ii!=adjList[curr].end(); ++ii) {
			if(isVisited[(*ii)] == false) {
				isVisited[(*ii)] = true;
				q.push(*ii);
			}
		}	
			 		cout<<curr<<' ';

				 q.pop();
				 // bfs_helper(q.front(), isVisited);

 		
 	}
 

 		// printQueue(q);
	}


public:
	Graph(int no_of_vertices) {
		adjList = new vector<int>[no_of_vertices+1];
		this->no_of_vertices = no_of_vertices;
	}

	~Graph() {
		delete [] adjList;
	}

	void addEdge(int src, int dest, int weight = 1, bool isDirected = true) {
		adjList[src].push_back(dest);

		if(isDirected == true) return;

		adjList[dest].push_back(src);
	}

	// void deleteEdge(int src, int dest, bool isDirected = true) {
	// 	std::vector<int>::iterator ii = find(adjList->begin(), adjList->end(), src);

	// 	if(ii == adjList->end()) {
	// 	}
	// 		return;

	// 	adjList[src].pop_back(dest);

	// 	if(isDirected == true) return;

	// 	ii = find(adjList->begin(), adjList->end(), src);

	// 	if(ii = adjList->end()) {
	// 		return;
	// 	}

	// 	adjList[dest].pop_back(src);
	// }


	void dfs(int src) {
		// std::vector<int>::iterator ii = find(adjList->begin(), adjList->end(), src);

		// if(ii == adjList->end()) {
		// 	return;
		// }

		bool* isVisited = new bool[no_of_vertices+1]();
		dfs_helper(src, isVisited);
		delete [] isVisited;
	 	}


	void bfs(int src) {
 		bool* isVisited = new bool[no_of_vertices+1]();
		bfs_helper(src, isVisited);
		delete [] isVisited;	
 	}

 	void printConnected() {
 		bool* isVisited = new bool[no_of_vertices+1]();

 		for(int i = 1;i<=no_of_vertices;++i) {
 			if(isVisited[i] == false) {
				dfs_helper(i, isVisited);
				cout<<endl;
			}
		}
	}

};

int main() {
	
	Graph G(14);

	G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(2,5);
	G.addEdge(5,6);
	G.addEdge(5,7);
	G.addEdge(6,7);
	G.addEdge(3,4);	
	G.addEdge(12, 13);
	G.addEdge(13, 14);
	//G.dfs(1);
	// G.bfs(1);	
	G.printConnected();
}