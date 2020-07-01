#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

enum Color {WHITE, GRAY, BLACK};

vector<int> adjacencyList[100];

//Recursive utility function
// A recursive function that uses color(which has 3 values)
// White - No DFS till now. GRAY - Processing the node and its child.
//BLACK - Already processed
//to detect cycle in subgraph reachable from vertex v.
//Time Complexity: O(V+E) due to use of DFS
bool isCylcicUtil(int node, int color[]) {

	// GRAY :  This vertex is being processed (DFS
	//         for this vertex has started, but not
	//         ended (or this vertex is in function
	//         call stack)
	color[node] = GRAY;

	for (auto itr : adjacencyList[node]) {
		if (color[itr] == GRAY)
			return true;
		// If v is not processed and there is a back
		// edge in subtree rooted with v
		if (color[itr] == WHITE && isCylcicUtil(itr, color))
			return true;
	}
	// Mark this vertex as processed
	color[node] = BLACK;
	return false;
}

bool isCylcic(int nodes) {

	int color[nodes] = {WHITE};

	//This loops helps in case of Disconnected Graph
	for (int node = 0; node < nodes; node++) {
		if (isCylcicUtil(node, color)) {
			return true;
		}
	}
	return false;
}

//Space Efficient, takes less than O(N X N) but Search takes O(Nodes)
void initializeAdjacencyList(int nodes, int edges) {
	int from, to;

	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		adjacencyList[from].push_back(to);
		//If undirected Graph
		//adjacencyList[to].push_back(from);
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

	int nodes, edges;
	cin >> nodes >> edges;
	initializeAdjacencyList(nodes, edges);
	if (isCylcic(nodes))
		cout << "Graph is cyclic" << endl;
	else
		cout << "Graph is not cyclic" << endl;
	return 0;
}