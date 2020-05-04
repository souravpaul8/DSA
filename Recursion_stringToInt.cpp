#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

long long stringToInt(string a, int size) {
	if (size == 1) {
		return (int)(a[size - 1] - 48);
	}

	return (int)(a[size - 1] - 48) + 10 * stringToInt(a, size - 1);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a;
	cin >> a;
	cout << stringToInt(a, a.length()) << endl;
	return 0;
}
