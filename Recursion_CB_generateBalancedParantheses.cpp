#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

void generateParantheses(string s, int open, int close, int pos, int n) {

	//If the no of parantheses hits 2*n
	if (pos == 2 * n) {
		//If balanced then we print
		if (open == close) {
			cout << s << endl;
		} else {
			return;
		}
	}

	// ")" is lexicoographically smaller so, consider those sequences first
	if (open > close) {
		generateParantheses(s + ")", open, close + 1, pos + 1, n);
	}
	// "(" is lexicographically greater so consider then later
	if (open < n) {
		generateParantheses(s + "(", open + 1, close, pos + 1, n);
	}

	return;
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
	generateParantheses("(", 1, 0, 1, n);
	return 0;
}
