#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//Iterative version of Breadth First Search using Stack
void BFSiterative(int startNode, int nodes) {
	queue<int> queue;

	bool visited[nodes] = {false};
	int distance[nodes] = {0};

	queue.push(startNode);
	visited[startNode] = true;

	while (!queue.empty()) {
		int currentVertex = queue.front();
		cout << currentVertex << " ";
		queue.pop();

		for (auto itr : adjacencyList[currentVertex]) {
			if (!visited[itr]) {
				queue.push(itr);
				visited[itr] = true;
				distance[itr] = distance[currentVertex] + 1;
			}
		}
	}
	cout << endl;
}

//Space Efficient, takes less than O(N X N) but Search takes O(Nodes)
void initializeAdjacencyList(int nodes, int edges) {
	int from, to;

	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		adjacencyList[from].push_back(to);
		//If undirected Graph
		adjacencyList[to].push_back(from);
	}
}

//Utility function to print Adjacency List
void printAdjacencyList(int nodes) {
	for (int i = 1; i <= nodes; i++) {
		cout << i << "-->";
		for (auto j = adjacencyList[i].begin(); j != adjacencyList[i].end(); j++) {
			cout << *j << " ";
		}
		cout << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int nodes, edges, startNode;
	cin >> nodes >> edges >> startNode;
	initializeAdjacencyList(nodes, edges);
	BFSiterative(startNode, nodes);
	return 0;
}