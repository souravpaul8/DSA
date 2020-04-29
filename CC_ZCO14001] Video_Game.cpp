#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, h;
	cin >> n >> h;
	int stak[n];
	for (int i = 0; i < n; i++) {
		cin >> stak[i];
	}
	int a, curr = 0, picked = 0;
	while (cin >> a && a != 0) {
		if (a == 1) {
			if (curr != 0) {
				curr -= 1;
			}

		} else if (a == 2) {
			if (curr != (n - 1)) {
				curr += 1;
			}

		} else if (a == 3) {
			if (stak[curr] != 0 && picked == 0) {
				picked = 1;
				stak[curr] -= 1;
			}

		} else {
			if (stak[curr] != h && picked == 1) {
				picked = 0;
				stak[curr] += 1;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		cout <<  stak[i] << " ";
	}

	cout  << "\n";

	return 0;
}
