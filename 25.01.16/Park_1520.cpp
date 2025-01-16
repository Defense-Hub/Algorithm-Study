#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height, width;
int ans = 0;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<vector<int>> board;
vector<vector<int>> dp;
int dfs(int y, int x){
    if(y == height - 1 && x == width - 1)
        return 1;
    int& ans = dp[y][x];
    if(ans != -1) return ans;
    ans = 0;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= height || nx >= width || ny < 0 || nx < 0) continue;
        if(board[ny][nx] >= board[y][x]) continue;
        ans += dfs(ny,nx);
    }
    return ans;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> height >> width;
    board.resize(height, vector<int>(width));
    dp.resize(height, vector<int>(width, -1));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            cin >> board[y][x];
        }
    }
    
    cout << dfs(0,0);
}