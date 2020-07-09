//Given an unsorted array and two numbers x and k,
//find k closest values to x.
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

//We simply create a max heap and take the absolute difference of X and the number
// as key of the heap according to which max is selected. When the size of heap exceeds k
// we simply remove it from the heap, so k minimum values are present whose second value 
// gives us our answer.
void kClosestNumbers(int k, int x, int noOfElements, int elements[]) {
	//Declaring the priority Queue
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < noOfElements; i++) {
		pq.push({abs(x - elements[i]), elements[i]});
		if (pq.size() > k) {
			pq.pop();
		}
	}

	cout << "K closest elements : ";
	for (int i = 0; i < k; i++) {
		cout << pq.top().second << " ";
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
	int noOfElements, k, x;
	cin >> noOfElements >> k >> x;
	int elements[noOfElements];
	for (int i = 0; i < noOfElements; i++) {
		cin >> elements[i];
	}
	kClosestNumbers(k, x, noOfElements, elements);
	return 0;
}