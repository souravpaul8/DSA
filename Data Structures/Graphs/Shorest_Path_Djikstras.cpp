//This is the Djikstra's Algorithm for Strongly Connected Component
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
# define INF 0x3f3f3f3f

//Vector of pairs to store the node as well as distance of edge to the node
vector<pair<int, int>> adjacencyList[100];


//The function that contains the Djikstra's Algorithm
void Djikstra(int nodes, int source) {

  //Min Heap is implemented using priority queue in STL
  //The third argument is a functor to make the heap max(default) to min
  priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  //Distances stores the minm distance of the edge connecting the particular node
  //initialize all keys as infinite (INF)
  vector<int> distances(nodes, INF);
  //Parent stores the parent of the particular node
  vector<int> parent(nodes, -1);

  //We push the src to the Min Heap with distance 0 (Since the start vertex has no edge now) and the source
  pq.push(make_pair(0, source));
  //distance is 0 to reach source
  distances[source] = 0;

  //The loops runs until the Heap is empty
  while (!pq.empty()) {

    // The first vertex in pair is the minimum distance
    // vertex, extract it from priority queue.(Greedy approach)
    // vertex label is stored in second of pair (it
    // has to be done this way to keep the vertices
    // sorted key (key must be first item
    // in pair)
    int node = pq.top().second;
    pq.pop();

    // 'itr' is used to get all adjacent vertices of a vertex
    for (auto itr : adjacencyList[node]) {
      // Get vertex label and distance of current adjacent
      // of u.
      int v = itr.first;
      int distance = itr.second;

      //  If distance of v is greater then dist(u) + distance
      // than we replace distance of v
      if (distances[v] > distances[node] + distance) {
        // Updating distance of v from INF
        distances[v] = distances[node] + distance;
        parent[v] = node;
        pq.push(make_pair(distances[v], v));
      }
    }
  }
  // Print distance of nodes from source
  for (int i = 0; i < nodes; i++) {
    cout << i << " - " << distances[i] << endl;
  }
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

  int nodes, edges, source;
  cin >> nodes >> edges >> source;
  initializeAdjacencyList(nodes, edges);
  Djikstra(nodes, source);
  return 0;
}