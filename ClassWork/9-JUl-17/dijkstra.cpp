#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// class comparator{
// public:
// 	bool operator()(Vertex& x,Vertex& y) {
// 		return A.wt > B.wt;
// 	}
// }
class Vertex {
public:
	int id;
	int wt;

	Vertex(int i, int w) {
		id = i;
		wt = w;
	}

	bool operator<(const Vertex& x) const {
		return (wt > x.wt);
	}
};

class Graph {

	list<Vertex>* adjList;
	int nV;
	int nE;
public:
	Graph(int n) {
		nV = n;
		adjList = new list<Vertex>[nV + 1]();
		nE = 0;
	}


	~Graph() {
		delete [] adjList;
	}

	void addEdge(int src, int dest, int weight, bool isDirectional = true) {
		adjList[src].push_back(Vertex(dest, weight));
		++nE;

		if(isDirectional)	return;

		adjList[dest].push_back(Vertex(src, weight));
		nE;
	}

	int dijkstra(int src, int dest) {
		int* dist = new int[nV+1];
		const int INF = (int)1e7;
		for(int i = 1;i<=nV; ++i) {
			dist[i] = INF;
		}

		// priority_queue<int, vector<int> , comparator> q;
		//OR simply overlaod operator <
		priority_queue<Vertex> q;

		q.push(Vertex(src, 0));	

		while(!q.empty()) {
			Vertex curVer = q.top();
			q.pop();

			dist[curVer.id] = min(curVer.wt, dist[curVer.id]);

			for(list<Vertex>::iterator it = adjList[curVer.id].begin(); it!=adjList[curVer.id].end();++it) {
				Vertex neighbour = *it;

				int distFromSource = neighbour.wt + curVer.wt;

				if(distFromSource < dist[neighbour.id]) q.push(Vertex(neighbour.id, distFromSource));
			}
		}
			int ans = dist[dest];
	delete [] dist;
	return ans;
	}

};

int main() {
	Graph G(7);

	G.addEdge(1, 2, 10);
	G.addEdge(1, 3, 80);
	G.addEdge(2, 5, 20);
	G.addEdge(5, 7, 10);
	G.addEdge(5, 6, 50);
	G.addEdge(6, 7, 5);
	G.addEdge(2, 3, 6);
	G.addEdge(3, 4, 70);

	cout<<G.dijkstra(1, 7)<<endl;
}