#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

string table[10]
    = {"", "", "abc", "def", "ghi", "jkl",
       "mno", "pqrs", "tuv", "wxyz"
      };
void letterCombination(string s, string make, int size, int j) {
	if (make.length() == size) {
		cout << make << endl;
		return;
	}

	for (int i = 0; i <  table[s[j] - 48].length() ; i++) {
		char a = table[s[j] - 48][i];
		letterCombination(s, make + a, size, j + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	letterCombination(s, "", s.length(), 0);
	return 0;
}
