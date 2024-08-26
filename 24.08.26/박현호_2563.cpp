#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<bool>> board(100, vector<bool>(100, false));
	int answer = 0;
	int cnt;
	cin >> cnt;
	for (int k = 0; k < cnt; k++) {
		int x, y;
		cin >> x >> y;

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				board[i][j] = true;
			}
		}
	}

	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			if (board[x][y] == true) answer++;
		}
	}

	cout << answer;
}