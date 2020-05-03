#include <bits/stdc++.h>

using namespace std;

long long ZCO15002(int arr[], int n, long long k) {
	long long varCount = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] - arr[i] >= k) {
				varCount += (n - j);
				break;
			}
		}
	}

	return varCount;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	long long k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cout << ZCO15002(arr, n, k) << endl;
	return 0;
}
