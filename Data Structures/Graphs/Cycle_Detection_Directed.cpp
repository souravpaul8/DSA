#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//Recursive utility function
//Time Complexity: O(V+E) due to use of DFS
bool isCylcicUtil(int node, bool visited[], bool recStack[]) {

	if (visited[node] == false) {
		visited[node] = true;
		recStack[node] = true;

		for (auto itr : adjacencyList[node]) {
			if (!visited[itr] && isCylcicUtil(itr, visited, recStack))
				return true;
			else if (recStack[itr])
				return true;
		}
	}
	recStack[node] = false;
	return false;
}

bool isCylcic(int nodes) {

	bool visited[nodes] = {false};
	bool recStack[nodes] = {false};

	//This loops helps in case of Disconnected Graph
	for (int node = 0; node < nodes; node++) {
		if (isCylcicUtil(node, visited, recStack)) {
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