#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

void permute(char *in, int i) {
	//Base Case
	if (in[i] == '\0') {
		cout << in << endl;
		return;
	}
	////Recursive Case
	for (int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i + 1);
		//Backtracking
		swap(in[i], in[j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char in[100];
	cin >> in;
	permute(in, 0);
	return 0;
}
