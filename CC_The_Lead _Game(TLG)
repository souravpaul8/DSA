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

	int rounds, a, b, maxPlayer, cumS1 = 0, cumS2 = 0, maxLead = 0;
	cin >> rounds;
	for (int i = 0; i < rounds; i++) {
		cin >> a >> b;
		cumS1 += a; cumS2 += b;
		if ( maxLead < abs(cumS1 - cumS2)) {
			if (cumS1 > cumS2)
				maxPlayer = 1;
			else
				maxPlayer = 2;
			maxLead = abs(cumS1 - cumS2);
		}
	}
	cout << maxPlayer << " " << maxLead << endl;
	return 0;
}
