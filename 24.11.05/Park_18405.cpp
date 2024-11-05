#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//16:05 ~ 16:45
int n, k, num;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<vector<int>> board;
vector<queue<pair<int,int>>> qArr;
void spread(int limit){
    // bfs를 바이러스별로 돌린다.
    int t = 0;
    queue<pair<int,int>> tmpQ;
    while(t < limit){
        for(int i = 1; i <= k; i++){
            while(!qArr[i].empty()){
                int curY = qArr[i].front().first;
                int curX = qArr[i].front().second;
                qArr[i].pop();
                for(int k = 0; k < 4; k++){
                    int nextY = curY + dy[k];
                    int nextX = curX + dx[k];
                    if(nextY <= 0 || nextX <= 0 || nextY > n || nextX > n) continue;
                    if(board[nextY][nextX] != 0) continue;
                    board[nextY][nextX] = i;
                    tmpQ.push({nextY,nextX});
                }
            }

            while(!tmpQ.empty()){
                qArr[i].push(tmpQ.front());
                tmpQ.pop();
            }
        }

        /*
        for(int y = 1; y <= n; y++){
            for(int x = 1; x <= n; x++){
                cout << board[y][x] <<  " ";
            }
            cout << endl;
        }
        */

        t++;
    }
}

int main() {
    
    cin >> n >> k;

    board.assign(n + 1, vector<int>(n + 1, 0));
    qArr.resize(k+1);
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            cin >> num;
            board[y][x] = num;
            if(num != 0)
                qArr[num].push({y,x});
        }
    }

    int time, inX, inY;
    cin >> time >> inX >> inY;
    spread(time);

    cout << board[inX][inY];
}