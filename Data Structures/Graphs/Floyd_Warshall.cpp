//This is the code for Floyd Warshall
#include <iostream>
#include <vector>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int nodes, vector<vector<int>> costMatrix) {

	/* cost[][] will be the output matrix
	that will finally have the shortest
	distances between every pair of vertices */
	int cost[nodes][nodes];

	/* Initialize the solution matrix same
	as input graph matrix. Or we can say
	the initial values of shortest distances
	are based on shortest paths considering
	no intermediate vertex. */
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			cost[i][j] = costMatrix[i][j];
		}
	}

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, .. k} */
	for (int k = 0; k < nodes; k++) {
		// Pick all vertices as source one by one
		for (int i = 0; i < nodes; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (int j = 0; j < nodes; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	cout << "The following matrix shows the shortest distances"
	     " between every pair of vertices \n";
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
		{
			if (cost[i][j] == INF)
				cout << "INF" << "   ";
			else
				cout << cost[i][j] << "     ";
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
	int nodes;
	cin >> nodes;
	vector<vector<int>> costMatrix = { {0, 5, INF, 10},
		{INF, 0, 2, INF},
		{INF, INF, 0, 1},
		{INF, INF, INF, 0}
	};
	floydWarshall(nodes, costMatrix);
	return 0;
}