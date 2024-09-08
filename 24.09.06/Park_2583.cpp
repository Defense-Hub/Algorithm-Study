#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> board;
int height, width, cnt;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct blank{
    int y;
    int x;
};

int bfs(int y, int x){
    board[y][x] = false;
    queue<blank> q;
    q.push({y,x});

    int res = 1;
    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();
        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if(ny >= height || nx >= width || ny < 0 || nx < 0) continue;
            if(!board[ny][nx]) continue;
            board[ny][nx] = false;
            q.push({ny,nx});
            res++;
        }
    }

    return res;
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> height >> width >> cnt;
    
    board.resize(height, vector<bool>(width, true));

    for(int k = 0; k < cnt; k++){
        int stx, sty, dtx, dty;
        cin >> stx >> sty >> dtx >> dty;

        // board 채워넣기
        for(int y = sty; y < dty; y++){
            for(int x = stx; x < dtx; x++){
                board[y][x] = false;
            }
        }
    }

    vector<int> answer;
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(board[y][x]){
                int res = bfs(y,x);
                answer.push_back(res);
            }
        }
    }

    cout << answer.size() << "\n";
    sort(answer.begin(), answer.end());
    for(int a : answer){
        cout << a << " ";
    }
}