#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define inf 1e18

int configCount = 0;

//Function to check if the board position is safe or not
bool isSafe(int board[][10], int i, int j, int n) {

	//Check Column
	for (int row = 0; row < i; row++) {
		if (board[row][j] == 1) {
			return false;
		}
	}

	//Check Left diagonal
	int x = i;
	int y = j;
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	//Check Right diagonal
	x = i;
	y = j;
	while (x >= 0 && y < n) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	//No Queens exist in either the same colunm,left or right diagonals
	return true;

}

//To count and print all configuration of nQueen problem
bool nQueen(int board[][10], int i, int n) {
	//Base Case
	//This condition is when we have reached a successful configuration on the board upto last row
	if (i == n) {
		//Print Configuration
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] == 1)
					cout << "(" << x << "," << y << ")" << " ";
			}
		}
		cout << endl;
		configCount++;
		//To print only 1 configuration just change below bool to true. By writing false we simply print all
		//Possible configurations
		return false;
	}
	//Recursive Configuration. Check all row position which is safe
	for (int j = 0; j < n; j++) {
		//Check if the position is safe
		if (isSafe(board, i, j, n)) {
			//Assuming that this is a appropriate position on the board in one of the configuration
			board[i][j] = 1;
			bool res = nQueen(board, i + 1, n);
			if (res)
				return true;
			//Backtracking since the position is not appropriate after inspective consecutive rows
			board[i][j] = 0;
		}
	}

	//No configuration possible
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//Assuming maximum value of n is 10
	int board[10][10] = {0};
	//Accepting n or the board size
	int n;
	cin >> n;
	nQueen(board, 0, n);
	cout << configCount << endl;
	return 0;
}
