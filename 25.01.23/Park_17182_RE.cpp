#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
// 15:30 ~ 15:50

vector<bool> isVisit;
vector<vector<int>> dist;
int n, st;
int ans = INF;

void Search(int from, int dis, int depth){
    if(depth == n){
        ans = min(ans, dis);
        return;
    }

    for(int i = 0; i < n; i++){
        if(i == from) continue;
        if(isVisit[i]) continue;
        isVisit[i] = true;
        Search(i, dis + dist[from][i], depth + 1);
        isVisit[i] = false;
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);      
    cin >> n >> st;
    dist.resize(n, vector<int>(n));
    isVisit.resize(n, false);
    // 이동 거리에 대한 정보를 모두 저장하고 벨만 포드로 각 노드간 최단 거리 계산
    // 순열로 0 -> 1 -> 2 / 0 -> 2 -> 1 이런식으로 방문하면서 최단 시간 계싼
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> dist[y][x];
        }
    }

    for(int from = 0; from < n; from++){
        for(int to = 0; to < n; to++){
            for(int adj = 0; adj < n; adj++){
                dist[from][to] = min(dist[from][to], dist[from][adj] + dist[adj][to]);
            }
        }
    }

    isVisit[st] = true;
    Search(st, 0, 1);

    cout << ans;
}