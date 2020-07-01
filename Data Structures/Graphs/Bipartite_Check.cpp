//This is the code for Bipartite Check
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//This is the modified version of DFS to check if graph is Bipartite
bool bipartiteCheckUtil(int node, bool visited[], int color[]) {
	visited[node] = true;
	//Traverse all child of the node
	for (auto itr : adjacencyList[node]) {

		if (!visited[itr]) {
			//Assign color opposite to the node
			color[itr] = color[node] ^ 1;
			if (!bipartiteCheckUtil(itr, visited, color))
				return false;
		}

		//If color of adjacent node is same return false
		else if (color[node] == color[itr])
			return false;
	}
	//Otherwise return true
	return true;
}

//THis function facilitates the Bipartite Check
void bipartiteCheck(int nodes) {

	//Color is array that contains color of the nodes
	int color[nodes] = { -1};
	bool visited[nodes] = {false};

	color[0] = 0;
	if (bipartiteCheckUtil(0, visited, color))
		cout << "It is bipartite" << endl;
	else
		cout << "It is not bipartite" << endl;
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
	bipartiteCheck(nodes);
	return 0;
}