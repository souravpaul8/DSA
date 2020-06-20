#include <bits/stdc++.h>

using namespace std;

int adjacencyMatrix[100][100];
vector<int> adjacencyList[100];

//Time Efficient, takes space O(Nodes X Nodes) but Search takes O(1)
void initializeAdjacencyMatrix(int nodes, int edges) {
  int from, to;
  adjacencyMatrix[nodes][nodes] = {0};

  for (int i = 0; i < edges; i++) {
    cin >> from >> to;
    adjacencyMatrix[from][to] = 1;
    //If undirected Graph
    // adjacencyMatrix[to][from] = 1;
  }

//To check if 2 nodes are connected
  if (adjacencyMatrix[3][4] == true)
    cout << "There is an edge between 3 and 4" << endl;
}

//Space Efficient, takes less than O(N X N) but Search takes O(Nodes)
void initializeAdjacencyList(int nodes, int edges) {
  int from, to;

  for (int i = 0; i < edges; i++) {
    cin >> from >> to;
    adjacencyList[from].push_back(to);
    //If undirected Graph
    //adjacencyList[to].push_back(from)
  }

  //To check if 2 nodes are connected
  //If 3 and 4 are connected
  for (auto itr = adjacencyList[3].begin(); itr <  adjacencyList[3].end(); itr++) {
    if ((*itr) == 4)
      cout << "There is an edge between 3 and 4" << endl;
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
  initializeAdjacencyMatrix(nodes, edges);
  initializeAdjacencyList(nodes, edges);
  return 0;
}