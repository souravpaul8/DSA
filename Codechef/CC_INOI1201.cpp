#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, temp1, temp2, temp3;
	cin >> n;

	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2 >> temp3;
		vec.push_back(make_pair(temp1, temp2 + temp3));
	}

	sort(vec.begin(), vec.end(), comparator);

	int ans = 0, prevans = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		ans = vec[i].first + vec[i].second + temp;
		ans = max(prevans, ans);
		prevans = ans;
		temp += vec[i].first;
	}

	cout << ans << endl;


	return 0;
}
