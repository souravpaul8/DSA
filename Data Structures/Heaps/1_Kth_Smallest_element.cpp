//Code for kth Smallest Element
#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

//For Kth smallest we use Max Heap, so that maximum element is at
// the top, and as soon as the size of heap surpasses K, we simply
//pop the top element from the heap, so that the kth smallest element is always
//at the top. For kth Largest, we use the Min Heap
// Priority Queue
void kthSmallestElement(int k, int noOfElements, int elements[]) {
	//Declaring the priority Queue
	priority_queue<int> pq;
	for (int i = 0; i < noOfElements; i++) {
		pq.push(elements[i]);
		if (pq.size() > k)
			pq.pop();
	}

	cout << "kth Smallest Element: ";
	cout << pq.top() << endl;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int noOfElements, k;
	cin >> noOfElements >> k;
	int elements[noOfElements];
	for (int i = 0; i < noOfElements; i++) {
		cin >> elements[i];
	}
	kthSmallestElement(k, noOfElements, elements);
	return 0;
}