//This is the Kosaraju's Algorithm for Strongly Connected Component
//Implemented after watching Tushar Roy's video
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

vector<int> adjacencyList[100];
vector<int> transposeAdjancencyList[100];

//Transposing the graph means reversing the direction of path
// between 2 vertex
void transposeGraph(int nodes) {

  for (int i = 0; i < nodes; i++) {

    for (auto itr : adjacencyList[i]) {
      transposeAdjancencyList[itr].push_back(i);
    }
  }
}

//This function is a variation of DFS
void DFSUtil(int vertex, bool visited[]) {
  visited[vertex] = true;
  cout << vertex << " ";

  for (auto itr : transposeAdjancencyList[vertex]) {
    if (!visited[itr]) {
      DFSUtil(itr, visited);
    }
  }
}

//Function to store the order of the end of Exploration for a vertex
void fillOrderStack(int node, stack<int> &Stack, bool visited[]) {

  visited[node] = true;

  //Explore all the child of the vertex
  for (auto itr : adjacencyList[node]) {
    if (!visited[itr])
      fillOrderStack(itr, Stack, visited);
  }
  //After exploring all the child of a vertex we push it to the stack
  Stack.push(node);
}

//Function to print the Strongly Connected Component of the Graph
//using Kosaraju's Algorithm
void printSCC(int nodes) {

  //Store the order in which we hit dead end of the exploration
  //of all child of a vertex
  stack<int> Stack;
  bool visited[nodes] = {false};

  //Explore all components and store the order using fillOrderStack function
  for (int node = 0; node < nodes; node++) {
    if (!visited[node]) {
      fillOrderStack(node, Stack, visited);
    }
  }

  //Reverse the directions in the directed graph
  transposeGraph(nodes);

  for (int i = 0; i < nodes; i++)
    visited[i] = false;
  //Explore all nodes in the stack
  while (!Stack.empty()) {

    int vertex = Stack.top();
    Stack.pop();
    if (!visited[vertex]) {
      //We run the DFSUtil function one time for every component
      DFSUtil(vertex, visited);
      cout << endl;
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
    //adjacencyList[to].push_back(from);
  }
}

//Utility function to print Adjacency List
void printAdjacencyList(int nodes, int edges) {
  for (int i = 0; i < nodes; i++) {
    cout << i << "-->";
    for (auto j = adjacencyList[i].begin(); j != adjacencyList[i].end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }
}

void printTransposeAdjacencyList(int nodes, int edges) {
  for (int i = 0; i < nodes; i++) {
    cout << i << "-->";
    for (auto j = transposeAdjancencyList[i].begin(); j != transposeAdjancencyList[i].end(); j++) {
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
  printSCC(nodes);
  return 0;
}