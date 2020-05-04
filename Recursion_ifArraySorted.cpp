#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

bool isArraySorted(int arr[], int size) {
	if (size == 1)
		return true;

	if (arr[size - 1] > arr[size - 2] && isArraySorted(arr, size - 1) == true) {
		return true;
	} else {
		return false;
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << isArraySorted(arr, size) << endl;
	return 0;
}
