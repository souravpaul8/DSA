//This is the Kruskal's Algorithm for MST
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536

//Vector of pairs to store the list of edges along with their weight
vector<pair<int, pair<int, int>>> edgeList;
int ranks[100];
int parent[100];

//Initialize a disjoint set( Basically 2 arrays rank and parent)
void initializeDisjointSet(int nodes) {
  //Each node will be set of its own
  for (int i = 0; i < nodes; i++) {
    ranks[i] = 0;
    parent[i] = i;
  }
}

// Find the parent of a node
// Path Compression
int find(int node) {

  /* Make the parent of the nodes in the path
  from u--> parent[u] point to parent[u] */
  if (node != parent[node])
    parent[node] = find(parent[node]);
  return parent[node];
}

// Union by rank
void unionByRank(int node1, int node2) {
  int parent1 = find(node1);
  int parent2 = find(node2);

  /* Make tree with smaller height
  a subtree of the other tree  */
  if (ranks[parent1] > ranks[parent2]) {
    parent[parent2] = parent1;
  }
  else { // If rnk[x] <= rnk[y]
    parent[parent1] = parent2;
  }

  if (ranks[parent1] == ranks[parent2]) {
    ranks[parent2]++;
  }

}

//Functions that actually implements the Krusal's Algorithm
void kruskalMST(int nodes) {

  int totalWeight = 0;

  sort(edgeList.begin(), edgeList.end());

  initializeDisjointSet(nodes);

  // Iterate through all sorted edges
  for (auto itr : edgeList) {
    int from = itr.second.first;
    int to = itr.second.second;

    int parentFrom = find(from);
    int parentTo = find(to);

    // Check if the selected edge is creating
    // a cycle or not (Cycle is created if u
    // and v belong to same set)
    if (parentTo != parentFrom) {
      // Current edge will be in the MST
      // so print it
      cout << from << " - " << to << endl;
      // Update MST weight
      totalWeight += itr.first;
      // Union of the two disjoint sets
      unionByRank(parentFrom, parentTo);
    }
  }

  cout << "Total Weight --> " << totalWeight << endl;
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

  int nodes, edges;
  cin >> nodes >> edges;
  initializeEdgeList(nodes, edges);
  kruskalMST(nodes);
  return 0;
}