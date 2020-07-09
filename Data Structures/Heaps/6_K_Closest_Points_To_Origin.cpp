//Given a list of points on the 2-D plane and an integer K.
//The task is to find K closest points to the origin and print them
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

// funnction to print the k closest points to origin
void kClosestPointsToOrigin(int k, int noOfElements, pair<int, int> elements[]) {

	//priority queue 'pq' implemented as max heap
	//We take the euclidian distance as the key of the max heap
	//So greatest element is at the top, as soon as size of heap
	//surpasses k, we simply pop it from the heap
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < noOfElements ; i++) {
		int x = elements[i].first;
		int y = elements[i].second;
		int dist = (x ^ 2) + (y ^ 2);
		pq.push({dist, elements[i]});
		if (pq.size() > k) {
			pq.pop();
		}
	}

	//Printing the Results
	cout << "K closest points to origin : " << endl ;
	for (int i = 0; i < k; i++) {
		cout << pq.top().second.first << " " << pq.top().second.second << endl;
		pq.pop();
	}
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int noOfElements, k, x, y;
	cin >> noOfElements >> k;
	pair<int, int> elements[noOfElements];
	for (int i = 0; i < noOfElements; i++) {
		cin >> x >> y;
		elements[i] = {x, y};
	}
	kClosestPointsToOrigin(k, noOfElements, elements);
	return 0;
}