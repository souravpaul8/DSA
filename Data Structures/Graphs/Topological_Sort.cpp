//This is the code for Topological Sort
//Code is written after watching Tushar Roy's concept
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//This is the modified version of DFS
void topologicalSortUtil(int node, bool visited[], stack<int> &Stack) {
	visited[node] = true;

    //Traverse all child of the node
	for (auto itr : adjacencyList[node]) {
		if (!visited[itr])
			topologicalSortUtil(itr, visited, Stack);
	}

    //After we have traversed all child, we push the node to the stack
	Stack.push(node);
}

//THis function facilitates the topological sort
void topologicalSort(int nodes) {

    //Stack to store the order of nodes in the Topological Sort 
	stack<int> Stack;
	bool visited[nodes] = {false};

    //This is for traversal of all the nodes even if the graph is not connected
	for (int i = 0; i < nodes; i++) {
		if (!visited[i])
			topologicalSortUtil(i, visited, Stack);
	}

    //We print the stack i.e the topological sorted order of nodes
	while (!Stack.empty()) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
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
	topologicalSort(nodes);
	return 0;
}