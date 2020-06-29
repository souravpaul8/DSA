#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void printAllPathsUtil(int source, int destination, bool visited[], int path[], int path_index) {

  // Mark the current node and store it in path[]
  visited[source] = true;
  path[path_index] = source;
  path_index++;

  if (source == destination) {
    for (int i = 0; i < path_index; i++) {
      cout << path[i] << " ";
    }
    cout << endl;
  } else {
    // DFS Recur for all the vertices adjacent to current vertex
    for (auto i : adjacencyList[source]) {
      if (!visited[i]) {
        printAllPathsUtil(i, destination, visited, path, path_index);
      }
    }
  }
  // Remove current vertex from path[] and mark it as unvisited
  path_index--;
  visited[source] = false;
}

//Function to print all paths from source to destination
void printAllPaths(int nodes, int source, int destination) {
  // Mark all the vertices as not visited
  bool visited[nodes] = {false};
  // Create an array to store paths
  int path[nodes];
  int path_index = 0;// Initialize path[] as empty

  // Call the recursive helper function to print all paths
  printAllPathsUtil(source, destination, visited, path, path_index);
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

  int nodes, edges, source, destination;
  cin >> nodes >> edges >> source >> destination;
  initializeAdjacencyList(nodes, edges);
  printAllPaths(nodes, source, destination);
  return 0;
}