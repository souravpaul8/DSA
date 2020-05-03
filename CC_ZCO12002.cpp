#include <bits/stdc++.h>

using namespace std;




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x, y;
	cin >> n >> x >> y;
	int a[n];
	int b[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	vector<int> s, e;
	int temp;

	for (int i = 0; i < x; i++) {
		cin >> temp;
		s.push_back(temp);
	}

	for (int i = 0; i < y; i++) {
		cin >> temp;
		e.push_back(temp);
	}

	sort(s.begin(), s.end());
	sort(e.begin(), e.end());

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		auto it1 = lower_bound(s.begin(), s.end(), a[i]);
		auto it2 = lower_bound(e.begin(), e.end(), b[i]);
		
		if (*it1 != a[i]) {
			if (it1 == s.begin())
			{
				vec.push_back(INT_MAX);
			} else {
				if (it2 == e.end()) {
					vec.push_back(INT_MAX);
				} else {
					vec.push_back(*it2 - * (it1 - 1) + 1);
				}
			}
		} else {
			if (it2 == e.end()) {
				vec.push_back(INT_MAX);
			} else {
				vec.push_back(*it2 - a[i] + 1);
			}
		}
	}


	cout << *min_element(vec.begin(), vec.end()) << endl;

	return 0;
}
