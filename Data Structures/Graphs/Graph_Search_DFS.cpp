#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//Recursive version of Depth First Search
//Actual DFS function
void DFSrecursive(int startNode, bool visited[]) {
	visited[startNode] = true;
	cout << startNode << " ";

	for (auto itr = adjacencyList[startNode].begin(); itr != adjacencyList[startNode].end(); itr++) {
		if (!visited[*itr]) {
			DFSrecursive(*itr, visited);
		}
	}
}
//Utility func to initialize visited array
void DFSrecursiveUtil(int startNode, int nodes) {
	bool visited[nodes] = {false};
	DFSrecursive(startNode, visited);
}

//Iterative version of Depth First Search using Stack
void DFSiterative(int startNode, int nodes) {
	stack<int> stack;
	bool visited[nodes] = {false};

	stack.push(startNode);
	while (!stack.empty()) {
		int currentVertex = stack.top();
		stack.pop();

		if (!visited[currentVertex]) {
			cout << currentVertex << " ";
			visited[currentVertex] = true;
		}

		for (auto itr = adjacencyList[currentVertex].begin(); itr != adjacencyList[currentVertex].end(); itr++) {
			if (!visited[*itr]) {
				stack.push(*itr);
			}
		}
	}
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
	DFSiterative(startNode, nodes);
	DFSrecursiveUtil(startNode, nodes);
	return 0;
}