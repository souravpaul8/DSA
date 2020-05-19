#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18


string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string problem2048(int x) {
	string number = "";
	if (x == 0)
		return number;
	number = problem2048(x / 10) + " " + arr[x % 10];

	return number;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x;
	cin >> x;
	cout << problem2048(x) << endl;

	return 0;

}
