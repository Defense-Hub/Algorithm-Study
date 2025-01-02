#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
// 우주 탐사선 _ 14 55 ~ 15 05, 16 00 ~ 17 50
// Ref : https://khj0426.tistory.com/153
int n, k;
vector<vector<int>> board;
vector<vector<int>> cost;
vector<bool> isVisit;
vector<int> route;
// 순열_ 시작 노드 K
int ans = INF;
void FindPath(int depth){
    // 다 채웠을 때
    if(depth == n){
        if(route[0] != k) return;
        int sum = 0;
        for(int i = 0; i < n-1; i++){
            sum += cost[route[i]][route[i+1]];
        }
        
        ans = min(ans, sum);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!isVisit[i]){
            isVisit[i] = true;
            route[depth] = i;
            FindPath(depth+1);
            isVisit[i] = false;
        }
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> n >> k;
    board.resize(n, vector<int>(n));
    cost.resize(n, vector<int>(n, INF));
    isVisit.assign(n, false);
    route.resize(n);
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> board[y][x];
        }
    }

    // 시작 위치 -> 나머지 행성으로 가는 최단거리를 모두 계산해서 합? X
    // A[s] B[5] C[6]
    // a->b 5
    // b->c 1
    // 6으로 전부 갈 수 있음

    // 아니면 모든 최단 시간을 계산하고 시작 -> 최단(B) -> 최단 (C) ?
    // 10^3 - 1,000
    for(int from = 0; from < n; from++){
        for(int to = 0; to < n; to++){
            for(int adj = 0; adj < n; adj++){
                cost[from][to] = min(cost[from][to], board[from][adj] + board[adj][to]);
            }
        }
    }
    // K가 처음일때를 기준으로 순열 계산
    FindPath(0);

    cout << ans;
}