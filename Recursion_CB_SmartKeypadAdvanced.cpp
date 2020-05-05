#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18
unordered_set <string> stringSet;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
string table[10]
    = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void letterCombination(string s, string make, int size, int j) {
	if (make.length() == size) {
		for(int i=0;i<11;i++){
            if (searchIn[i].find(make) != std::string::npos){
                stringSet.insert(searchIn[i]);
            }
        }
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
	string s;
	cin >> s;
	letterCombination(s, "", s.length(), 0);
    for(auto i=stringSet.begin();i!=stringSet.end();i++)
        cout << *i << endl;
	return 0;
}
