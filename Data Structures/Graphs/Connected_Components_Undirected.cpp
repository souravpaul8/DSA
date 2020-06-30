#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

//Print the single component and traverse all connected nodes
// Variation of DFS
void printComponent(int node, bool visited[]) {


  visited[node] = true;
  cout << node << " ";


  for (auto itr : adjacencyList[node]) {
    if (!visited[itr])
      printComponent(itr, visited);
  }
}

//This function prints all the components of the disconnected graph
void printConnectedComponents(int nodes) {
  //Array to look if the node is visited or not
  bool visited[nodes] = {false};
  int componentCount = 0;
  //Iterate through all the nodes, if node is visited
  // means it is another component
  for (int node = 0; node < nodes; node++) {
    if (!visited[node]) {
      printComponent(node, visited);
      componentCount++;
      cout << endl;
    }
  }
  cout <<  "No of connected components: " << componentCount << endl;
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
void printAdjacencyList(int nodes, int edges) {
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
  printConnectedComponents(nodes);
  return 0;
}