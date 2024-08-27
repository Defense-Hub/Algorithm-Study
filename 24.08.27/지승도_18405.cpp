#include<iostream>
#include<queue>
#include<vector>

// https://www.acmicpc.net/problem/18405

using namespace std;

int map[201][1001] = { 0, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int N, K, targetX, targetY, s;

void BFS(vector <queue< pair<int, int>>> vec) {


    for (int i = 0; i < s; i++) { // S 만큼 반복 전염 시작
        for (int j = 0; j < vec.size(); j++) // 숫자가 낮은 바이러스 중에 전염 할 수 있는 바이러스 찾기
        {
            int qSize = vec[j].size();
            for (int z = 0; z < qSize; z++) { // 전염할 바이러스가 있다면 상하좌우로 BFS 한번씩
                pair<int, int> pos = vec[j].front();
                vec[j].pop();

                for (int k = 0; k < 4; k++) {
                    int moveX = pos.second + dx[k];
                    int moveY = pos.first + dy[k];

                    if (moveX <= 0 || moveY <= 0 || moveX > K || moveY > N)
                        continue;

                    if (map[moveY][moveX] == 0) {
                        map[moveY][moveX] = j;
                        vec[j].push({ moveY, moveX });
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;

    vector <queue< pair<int, int>>> vec(K + 1);

    for (int i = 1; i <= N; i++) { // 입력
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) {
                vec[map[i][j]].push({ i,j });
            }
        }
    }
    cin >> s >> targetY >> targetX; // 입력

    BFS(vec);

    cout << map[targetY][targetX] << endl;;

    return 0;
}
