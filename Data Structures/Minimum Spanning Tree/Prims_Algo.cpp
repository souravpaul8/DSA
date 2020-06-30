//This is the Prim's Algorithm for Strongly Connected Component
//Implemented after watching Tushar Roy's video
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
# define INF 0x3f3f3f3f

//Vector of pairs to store the node as well as weight of edge to the node
vector<pair<int, int>> adjacencyList[100];

//The function that contains the Prim's Algorithm
void primMST(int nodes) {

  //Min Heap is implemented using priority queue in STL
  //The third argument is a functor to make the heap max(default) to min
  priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  //We consider the node 0 as the source of the MST
  int src = 0;

  //Weights stores the minm weight of the edge connecting the particular node
  //initialize all keys as infinite (INF)
  vector<int> weights(nodes, INF);
  //Parent stores the parent of the particular node
  vector<int> parent(nodes, -1);
  //This vector stores whether the node has been included in the MST
  vector<bool> inMST(nodes, false);

  //We push the src to the Min Heap with weight 0 (Since the start vertex has no edge now) and the source
  pq.push(make_pair(0, src));
  //Weight is 0 to reach source
  weights[src] = 0;

  //The loops runs until the Heap is empty
  while (!pq.empty()) {

    // The first vertex in pair is the minimum weight
    // vertex, extract it from priority queue.(Greedy approach)
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted key (key must be first item
    // in pair)
    int node = pq.top().second;
    pq.pop();

    // Include vertex in MST
    inMST[node] = true;

    // 'itr' is used to get all adjacent vertices of a vertex
    for (auto itr : adjacencyList[node]) {
      // Get vertex label and weight of current adjacent
      // of u.
      int v = itr.first;
      int weight = itr.second;

      //  If v is not in MST and weight of (u,v) is smaller
      // than current key of v
      if (inMST[v] == false && weights[v] > weight) {
        // Updating weight of v from INF
        weights[v] = weight;
        parent[v] = node;
        pq.push(make_pair(weights[v], v));
      }
    }
  }
  int totalWeight = 0;
  // Print edges of MST using parent array
  for (int i = 1; i < nodes; i++) {
    cout << parent[i] << " - " << i << endl;
    totalWeight += weights[i];
  }
  cout << totalWeight << endl;
}



//Space Efficient, takes less than O(N X N) but Search takes O(Nodes)
void initializeAdjacencyList(int nodes, int edges) {
  int from, to, weight;

  for (int i = 0; i < edges; i++) {
    cin >> from >> to >> weight;
    adjacencyList[from].push_back(make_pair(to, weight));
    //If undirected Graph
    adjacencyList[to].push_back(make_pair(from, weight));
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
  primMST(nodes);
  return 0;
}