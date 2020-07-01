//This is the Bellman Ford Algorithm for Single Source Shortest Path
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
vector<pair<int, pair<int, int>>> edgeList;


//The function that contains the Bellman Ford Algorithm
void BellmanFord(int nodes, int edges, int source) {

  //Distances stores the minm distance of the edge connecting the particular node
  //initialize all keys as infinite (INF)
  vector<int> distances(nodes, INF);
  //Parent stores the parent of the particular node
  vector<int> parent(nodes, -1);

  distances[source] = 0;

  //The loops runs for (Nodes - 1) times
  for (int i = 0; i < nodes; i++) {
    //We pick up each edge and relax each of the nodes
    for (int j = 0; j < edges; j++) {
      int u = edgeList[j].second.first;
      int v = edgeList[j].second.second;
      int weight = edgeList[j].first;
      //Relaxing the node
      if (distances[u] != INF && distances[v] > distances[u] + weight) {
        // Updating distance of v from INF
        distances[v] = distances[u] + weight;
        parent[v] = u;
      }
    }
  }

  //If the distance improves in node'th iteration, it denotes that cycle is present
  for (int i = 0; i < edges; i++) {
    int u = edgeList[i].second.first;
    int v = edgeList[i].second.second;
    int weight = edgeList[i].first;

    if (distances[u] != INF && distances[u] + weight < distances[v]) {
      cout << "Graph contains negative cycle" << endl;
      return;
    }
  }
  //Print the distance of each node from source
  for (int i = 0; i < nodes; i++) {
    cout << i << " -- " << distances[i] << endl;
  }

  //To print path we can use the parent vector
}



//Space Efficient, takes less than O(N X N) but Search takes O(Nodes)
void initializeEdgeList(int nodes, int edges) {
  int from, to, weight;

  for (int i = 0; i < edges; i++) {
    cin >> from >> to >> weight;
    edgeList.push_back({weight, {from, to}});
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
  initializeEdgeList(nodes, edges);
  BellmanFord(nodes, edges, source);
  return 0;
}