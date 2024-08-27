#include <iostream>
#include <string>
#include <queue>
#define INF 987654321
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dx[6] = {1,-1,0,0,0,0};

using namespace std;

vector<vector<string>> board(30, vector<string>(30));
//vector<vector<vector<int>>> cost(30, vector<vector<int>>(30, vector<int>(30)));
vector<vector<vector<bool>>> isVisit(30, vector<vector<bool>>(30, vector<bool>(30)));
int floor, length, width;
int stX, stY, stZ, tarX, tarY, tarZ;

struct pt{
    int cost;
    int z;
    int y;
    int x;
};
/*
struct compare{
    bool operator()(pt& p1, pt& p2){
        return p1.cost < p2.cost;
    }
};

void Bfs(int sz, int sy, int sx){
    priority_queue<pt, vector<pt>, compare> pq;
    pq.push({0, sz, sy, sx});
    cost[sz][sy][sx] = 0;

    while(!pq.empty()){
        int curCost = pq.top().cost;
        int cz = pq.top().z;
        int cy = pq.top().y;
        int cx = pq.top().x;
        pq.pop();
        if(cz == tarZ && cy == tarY && cx == tarX) break;
        for(int k = 0; k < 6; k++){
            int nCost = curCost + 1;
            int nz = cz + dz[k];
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= width || ny >= length || nz >= floor) continue;
            if(board[nz][ny][nx] == '#') continue;
            if(nCost < cost[nz][ny][nx]){
                cost[nz][ny][nx] = nCost;
                pq.push({nCost, nz, ny, nx});
            }
        }
    }
}
*/

int Bfs(int sz, int sy, int sx){
    queue<pt> q;
    q.push({0, sz, sy, sx});
    isVisit[sz][sy][sx] = true;

    while(!q.empty()){
        int curCost = q.front().cost;
        int cz = q.front().z;
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        if(cz == tarZ && cy == tarY && cx == tarX){
            return curCost;
        }

        for(int k = 0; k < 6; k++){
            int nz = cz + dz[k];
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= width || ny >= length || nz >= floor) continue;
            if(board[nz][ny][nx] == '#') continue;
            if(isVisit[nz][ny][nx]) continue;
            isVisit[nz][ny][nx] = true;
            q.push({curCost+1, nz, ny, nx});
        }
    }

    return -1;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    while(true){
        cin >> floor >> length >> width;
        if(floor == 0 && length == 0 && width == 0) break;
        
        //init
        for(int z = 0; z < floor; z++){
            for(int y = 0; y < length; y++){
                for(int x = 0; x < width; x++){
                    //cost[z][y][x] = INF;
                    isVisit[z][y][x] = false;
                }
            }
        }

        // 값 채워넣기
        for(int z = 0; z < floor; z++){
            for(int y = 0; y < length; y++){
                cin >> board[z][y];
            }
        }

        // bfs 시작 지점 찾기
        for(int z = 0; z < floor; z++){
            for(int y = 0; y < length; y++){
                for(int x = 0; x < width; x++){
                    if(board[z][y][x] == 'S'){
                        stZ = z;
                        stY = y;
                        stX = x;
                    }

                    if(board[z][y][x] == 'E'){
                        tarZ = z;
                        tarY = y;
                        tarX = x;
                    }

                }
            }
        }

        int res = Bfs(stZ, stY, stX);

        if(res == -1) cout << "Trapped!";
        else{
            cout << "Escaped in " << res << " minute(s).";
        }
        cout << "\n";
    }
    
}