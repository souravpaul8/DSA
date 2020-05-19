#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

void towerOfHanoi(int n, char src, char dest, char helper) {
	if (n == 0)
		return;

	towerOfHanoi(n - 1, src, helper, dest);
	cout << "Move " << n << " disk from " << src << " to " << dest << endl;
	towerOfHanoi(n - 1, helper, dest, src);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	towerOfHanoi(n, 'A', 'B', 'C');
	return 0;
}
