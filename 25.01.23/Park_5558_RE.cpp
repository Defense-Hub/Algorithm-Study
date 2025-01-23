#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 14:50 ~ 15:20
int h, w, n;
vector<string> board;
vector<pair<int,int>> node;
vector<vector<bool>> isVisit;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int bfs(int st, int dt){
    // isVisit 초기화
    isVisit.assign(h, vector<bool>(w, false));
    // {y,x}, depth
    queue<pair<pair<int,int>,int>> q; 
    q.push({node[st], 0});
    isVisit[node[st].first][node[st].second] = true;
    int ret = 0;
    while(!q.empty()){
        pair<int,int> cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(cur.first == node[dt].first && cur.second == node[dt].second){
            ret = depth;
            break;
        } 

        for(int k = 0; k < 4; k++){
            int ny = cur.first + dy[k];
            int nx = cur.second + dx[k];
            if(ny >= h || nx >= w || ny < 0 || nx < 0) continue;
            if(board[ny][nx] == 'X') continue;
            if(isVisit[ny][nx]) continue;
            isVisit[ny][nx] = true;
            q.push({{ny,nx}, depth+1});
        }
    }

    return ret;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);      
    cin >> h >> w >> n;
    board.resize(h);
    node.resize(n+1);

    // 1 - 2 - 3 -... - n 까지의 bfs로 탐색하고 발견되는 즉시 depth 저장 break;
    for(int y = 0; y < h; y++){
        cin >> board[y];
        for(int x = 0; x < w; x++){
            if(board[y][x] == 'S') node[0] = {y,x};
            else if(board[y][x] != '.' && board[y][x] != 'X'){
                node[board[y][x] - '0'] = {y,x};
            }
                
        }
    }

    int ans = 0;
    int st = 0;
    for(int i = 1; i <= n; i++){
        ans += bfs(st, i);
        st = i;
    }
    cout << ans;
}