#include<iostream>
#include<queue>
#include<vector>

// https://www.acmicpc.net/problem/6593

using namespace std;


int dx[4] = { 0 , 0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int L, R, C;

int map[31][31][31];

pair<int, pair<int, int>> startPos;
pair<int, pair<int, int>> escapePos;
void BFS() {
	queue <pair<int, pair<int, int>>> q;

	q.push(startPos);
	map[startPos.first][startPos.second.first][startPos.second.second] = 0;

	while (!q.empty()) {
		pair<int, pair<int, int>> front = q.front();
		int curPosX = front.second.second;
		int curPosY = front.second.first;
		int curFloor = front.first;
		q.pop();

		for (int i = 0; i < 4; i++) { // 같은 층 동서남북 이동
			int moveY = curPosY + dy[i];
			int moveX = curPosX + dx[i];

			if (moveY < 0 || moveX < 0 || moveY >= R || moveX >= C)
				continue;

			if (map[curFloor][moveY][moveX] == -2 || map[curFloor][moveY][moveX] > map[curFloor][curPosY][curPosX] + 1) {
				map[curFloor][moveY][moveX] = map[curFloor][curPosY][curPosX] + 1;
				pair<int, pair<int, int>> pos = { curFloor, { moveY,moveX } };
				q.push(pos);
			}
		}

		for (int i = 0; i < 2; i++) { // 층 간(상하) 이동
			int moveF = curFloor + dy[i];

			if (moveF < 0 || moveF >= L)
				continue;

			if (map[moveF][curPosY][curPosX] == -2 || map[moveF][curPosY][curPosX] > map[curFloor][curPosY][curPosX] + 1) {
				map[moveF][curPosY][curPosX] = map[curFloor][curPosY][curPosX] + 1;
				pair<int, pair<int, int>> pos = { moveF, { curPosY,curPosX } };
				q.push(pos);
			}
		}
	}
}

int main() {

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) {
			break;
		}

		char sel;
		for (int i = 0; i < L; i++) { // 입력 
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> sel;
					if (sel == '#') {
						map[i][j][k] = -1;
					}
					else {
						map[i][j][k] = -2;
						if (sel == 'S') {
							startPos = { i, { j,k } };
						}
						else if (sel == 'E') {
							escapePos = { i, { j,k } };
						}
					}
					
				}
			}
		}

		BFS();

		if (map[escapePos.first][escapePos.second.first][escapePos.second.second] == -2) {
			cout << "Trapped!" << endl;
		}
		else {
			int count = map[escapePos.first][escapePos.second.first][escapePos.second.second];
			cout << "Escaped in " << count <<" minute(s)." << endl;
		}
	}

	return 0;
}
