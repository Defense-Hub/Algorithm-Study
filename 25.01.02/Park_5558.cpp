/*
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
// 18 00 ~ 19 00
// REF https://postbarca.tistory.com/21

int height, width, chCnt;
vector<string> board;
vector<vector<bool>> isVisit;
pair<int,int> st;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int ans = 0;

void bfs(int target){
    queue<pair<pair<int,int>,int>> q;
    q.push({st,0});
    isVisit[st.first][st.second] = true; 
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cnt = q.front().second;
        isVisit[cy][cx] = true; 
        q.pop();
        if(board[cy][cx] == (target + '0')){
            ans += cnt;
            st = {cy, cx};
            break;
        }

        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if(ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
            if(isVisit[ny][nx] || board[ny][nx] == 'X') continue;
            q.push({{ny,nx},cnt+1});
        }
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> height >> width >> chCnt;
    board.resize(height);
    
    for(int y = 0; y < height; y++){
        cin >> board[y];
        for(int x = 0; x < width; x++){
            if(board[y][x] == 'S') st = {y,x};
        }
    }
    // bfs로 탐색 한칸씩 퍼지면서 타겟 idx를 찾기 찾으면 종료
    for(int i = 1; i <= chCnt; i++){
        // isVisit 초기화
        isVisit.assign(height, vector<bool>(width, false));
        bfs(i);
    }
    cout << ans;
}
*/

#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
char map[1005][1005];
bool visit[1005][1005];
int target[12][2];
int start[2];
int r, c, n, cnt;
int ly[] = { 1,-1,0,0 };
int lx[] = { 0,0,1,-1 };
typedef struct record {
    int y, x, mov_n;
};
bool isin(int y, int x) {
    if (y >= 1 && y <= r && x >= 1 && x <= c && map[y][x] != 'X')
        return true;
    else
        return false;
}
void find(int y, int x, int n) {
    queue <record> q;
    q.push({ y,x,0 });
    visit[y][x] = true;
    while (!q.empty()) {
        record t = q.front(); q.pop();
        // 도착했는지 확인
        if (t.y == target[n][0] && t.x == target[n][1]) {
            cnt += t.mov_n;
            start[0] = t.y;
            start[1] = t.x;
            break;
        }
        // 아니면 계속 돎
        for (int i = 0; i < 4; i++) {
            int ny = t.y + ly[i];
            int nx = t.x + lx[i];
            if (isin(ny, nx) && !visit[ny][nx]) {
                q.push({ ny, nx, t.mov_n + 1 });
                visit[ny][nx] = true;
            }
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> r >> c >> n;
    //입력
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> map[i][j];
            if (map[i][j] >= '0' && map[i][j] <= '9') { //순서 지정
                target[map[i][j] - '0'][0] = i;
                target[map[i][j] - '0'][1] = j;
            }
            if (map[i][j] == 'S') { //시작지점
                start[0] = i;
                start[1] = j;
            }
        }
    }
    //찾는 과정 시작
    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));
        find(start[0], start[1], i);
    }
    cout << cnt;
}