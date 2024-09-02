#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
// 0 1 / 1 0 
// 1 2 / 2 1
// 2 3 / 3 2
// 3 4 / 4 3

// 0 1
// 0 2
// 1 2
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> board(n);
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int y = 0; y < n; y++){
        cin >> board[y];        
        for(int x = 0; x < n; x++){
            if(board[y][x] == 'Y') dist[y][x] = 1;
        }
    }

    for(int adj = 0; adj < n; adj++){
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(y == x || dist[y][adj] == INF || dist[adj][x] == INF) continue;
                dist[y][x] = min(dist[y][x], dist[y][adj] + dist[adj][x]);
            }
        }
    }

    int answer = 0;
    for(int y = 0; y < n; y++){
        int cnt = 0;
        for(int x = 0; x < n; x++){
            if(dist[y][x] <= 2) cnt++;
        }

        answer = max(answer, cnt);
    }
    
    cout << answer;
}