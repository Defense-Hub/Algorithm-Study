#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

// https://www.acmicpc.net/problem/2583
using namespace std;

int M, N, K;
int map[101][101] = { 0, };
bool visited[101][101] = { false, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<int> answer;

void BFS(pair<int,int> startPos) {
	queue<pair<int, int>> q;

	q.push(startPos);
	visited[startPos.first][startPos.second] = true;

	int count = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int moveX = x + dx[i];
			int moveY = y + dy[i];

			if (moveX < 0 || moveY < 0 || moveX >= N || moveY >= M)
				continue;

			if (!visited[moveY][moveX] && map[moveY][moveX] == 0) {
				visited[moveY][moveX] = true;
				q.push({ moveY, moveX });
				count++;
			}
		}
	}

	answer.push_back(count);
}

int main() {
	cin >> M >> N >> K;

	int bx, by, ux, uy;
	for (int i = 0; i < K; i++) {
		cin >> bx >> by >> ux >> uy;

		for (int j = by; j < uy; j++) {
			for (int k = bx; k < ux; k++) {
				map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && map[i][j] == 0) {
				BFS({ i,j });
			}
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}
