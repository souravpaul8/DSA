#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

std::vector<string> v;

void generateSubsequences(char *in, char *out, int i, int j) {

	if (in[i] == '\0') {
		out[j] = '\0';
		v.push_back(out);
		return;
	}
	//Rec Case
	//1.Include the current char
	out[j] = in[i];
	generateSubsequences(in, out, i + 1, j + 1);

	//2.Exclude current char
	generateSubsequences(in, out, i + 1, j);

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char in[100];
	char out[100];
	cin >> in;
	generateSubsequences(in, out, 0, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
