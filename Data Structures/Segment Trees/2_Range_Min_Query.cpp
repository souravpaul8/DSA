#include <iostream>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999
//Function to build Segment Tree. Time taken - O(N)
//For an index i, it stores the sum of index 2*i and (2*i + 1)
//Segment Tree at index 1 contains sm of all elements, at 2 sum of first half and at 3 sum of last half and so on,
void buildSegmentTree(int* arr, int* segmentTree, int start, int end, int treeNode) {
	//Base Case where we reach a leaf node
	if (start == end) {
		segmentTree[treeNode] = arr[start];
		return;
	}
	//Calculating Mid
	int mid = (start + end) / 2;

	//We build the the two halfs recursively
	buildSegmentTree(arr, segmentTree, start, mid, 2 * treeNode);
	buildSegmentTree(arr, segmentTree, mid + 1, end, 2 * treeNode + 1);

	//After building the 2 halfs, we calculate the sum of the 2 halfs
	segmentTree[treeNode] = min(segmentTree[2 * treeNode], segmentTree[2 * treeNode + 1]);
}

//Function to update the value
//We move along the height of the tree
//Time taken is O(logN)
void updateSegmentTree(int* arr, int* segmentTree, int start, int end, int treeNode, int updateIndex, int updateValue) {
	//Base case when we reach the index where value is to be updated
	if (start == end) {
		arr[updateIndex] = updateValue;
		segmentTree[treeNode] = updateValue;
		return;
	}

	int mid = (start + end) / 2;
	//Moving down the tree till we reach the index to update the value
	if (updateIndex > mid) {
		updateSegmentTree(arr, segmentTree, mid + 1, end, 2 * treeNode + 1, updateIndex, updateValue);
	} else {
		updateSegmentTree(arr, segmentTree, start, mid, 2 * treeNode, updateIndex, updateValue);
	}
	//After updating, propagating the value to the top
	segmentTree[treeNode] = min(segmentTree[2 * treeNode], segmentTree[2 * treeNode + 1]);
}

//Function for querying the sum in the range
//We move along the height for this
//Time Complexity - O(logN)
int rangeMinQuery(int* segmentTree, int start, int end, int treeNode, int left, int right) {

	//Completely Outside Range
	if (start > right || end < left) {
		return INF;
	}

	//Completely Inside Range
	if (start >= left && end <= right) {
		return segmentTree[treeNode];
	}

	//Partially inside and partially outside
	int mid = (start + end) / 2;
	int ansLeft = rangeMinQuery(segmentTree, start, mid, 2 * treeNode, left, right);
	int ansRight = rangeMinQuery(segmentTree, mid + 1, end, 2 * treeNode + 1, left, right);
	int ans = min(ansLeft, ansRight);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//Size of array
	int n;
	cin >> n;
	//Input array
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//Segment Tree in this array
	//Total size of this array is 2*N - 1,since there are N leaves, representing each element
	//And N-1 internal nodes. Since we are using 1-based indexing, we have a size of 2*N
	int* segmentTree = new int[4 * n];
	buildSegmentTree(arr, segmentTree, 0, n - 1, 1);
	int updateIndex, updateValue;
	cin >> updateIndex >> updateValue;
	//Update a value in the array
	updateSegmentTree(arr, segmentTree, 0, n - 1, 1, updateIndex, updateValue);
	for (int i = 1; i < 4 * n; i++)
		cout << segmentTree[i] << endl;
	//Range Query
	int left, right;
	cin >> left >> right;
	cout << "Minimum between the range is: " << rangeMinQuery(segmentTree, 0, n - 1, 1, left, right) << endl;
	return 0;
}