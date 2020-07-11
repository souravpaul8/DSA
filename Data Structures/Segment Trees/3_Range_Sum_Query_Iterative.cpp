#include <iostream>

using namespace std;

#define mod 1000000007
#define inf 1e18
#define ll long long
#define PI 3.1415926536
#define INF 99999

const int N = 1e5;
int n;
int segmentTree[2 * N];

//Function to build Segment Tree. Time taken - O(N)
//Before doing any queries we need to build the tree, which is quite straightforward
//and takes O(n) time. Since parent always has index less than its children, we just
//process all the internal nodes in decreasing order.
void buildSegmentTree() {
	for (int i = n - 1; i > 0; --i) {
		segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
	}
}

//Function to update the value
//Modifying an element is also quite straightforward and takes time proportional to the height of the tree,
// which is O(log(n)). We only need to update values in the parents of given node. So we just go up the tree
// knowing that parent of node p is p / 2 or p>>1, which means the same. p^1 turns 2 * i into 2 * i + 1 and 
//vice versa, so it represents the second child of p's parent.
//Time taken is O(logN)
void updateSegmentTree(int updateIndex, int updateValue) {
	for (segmentTree[updateIndex = updateIndex + n] = updateValue; updateIndex > 1; updateIndex = updateIndex / 2) {
		segmentTree[updateIndex / 2] = segmentTree[updateIndex] + segmentTree[updateIndex ^ 1];
	}
}

//Function for querying the sum in the range
// If l, the left interval border, is odd (which is equivalent to l&1) 
//then l is the right child of its parent. Then our interval includes node l
// but doesn't include it's parent. So we add t[l] and move to the right of l's
// parent by setting l = (l + 1) / 2. If l is even, it is the left child, and the
// interval includes its parent as well (unless the right border interferes), so we 
//just move to it by setting l = l / 2. Similar argumentation is applied to the right border. We stop once borders meet.
//Time Complexity - O(logN)
int rangeSumQuery(int left, int right) {
	int ans = 0;
	for (left += n, right += n; left < right; left = left / 2, right = right / 2) {
		if (left & 1)
			ans += segmentTree[left++];
		if (right & 1)
			ans += segmentTree[--right];
	}
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
	cin >> n;
	//Input array
	for (int i = 0; i < n; i++) {
		cin >> segmentTree[n + i];
	}
	buildSegmentTree();
	int updateIndex, updateValue;
	cin >> updateIndex >> updateValue;
	//Update a value in the array
	updateSegmentTree(updateIndex, updateValue);
	for (int i = 1; i < 4 * n; i++)
		cout << segmentTree[i] << endl;
	//Range Query
	int left, right;
	cin >> left >> right;
	cout << "Minimum between the range is: " << rangeSumQuery(left, right) << endl;
	return 0;
}