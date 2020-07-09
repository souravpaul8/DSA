//Given an array of n elements, where each element is at most k
//away from its target position, devise an algorithm that sorts
//in O(n log k) time
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

//Since the element in the array is within the range of k, so we always
//need to sort only k elements in the array and not k, as we do in sorting
//So, for this we take the Min heap, so that minimum element is at the Top.
//As soon as the heap size surpasses k, we pop the top element, which is eventually
// the smallest element in the range of k elements.This way we do it for the element
//to get a sorted array
void sortKSortedArray(int k, int noOfElements, int elements[]) {
	//Declaring the priority Queue
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> sortedArray;
	for (int i = 0; i < noOfElements; i++) {
		pq.push(elements[i]);
		if (pq.size() > k) {
			sortedArray.push_back(pq.top());
			pq.pop();
		}
	}
	while (!pq.empty()) {
		sortedArray.push_back(pq.top());
		pq.pop();
	}
	cout << "Sorted Array : ";
	for (int i = 0; i < noOfElements; i++) {
		cout << sortedArray[i] << " ";
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
	int noOfElements, k;
	cin >> noOfElements >> k;
	int elements[noOfElements];
	for (int i = 0; i < noOfElements; i++) {
		cin >> elements[i];
	}
	sortKSortedArray(k, noOfElements, elements);
	return 0;
}