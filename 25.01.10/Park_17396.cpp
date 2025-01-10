#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321987654321
using namespace std;

// 19 00 19 30
int n, m;
vector<int> board;
vector<long long> cost;
vector<vector<pair<int,long long>>> edge;

void dijkstra(int st){
    // cost, to
    priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    pq.push({0, st});
    cost[st] = 0;

    while(!pq.empty()){
        long long curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curCost > cost[curNode]) continue;

        for(int i = 0; i < edge[curNode].size(); i++){
            int nextNode = edge[curNode][i].first;
            long long nextCost = curCost + edge[curNode][i].second;
            if(board[nextNode] && nextNode != n-1) continue;
            if(nextCost < cost[nextNode]){
                cost[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> n >> m;
    board.resize(n);
    edge.resize(n);
    cost.resize(n, INF);
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    for(int i = 0; i < m; i++){
        long long from, to, time;
        cin >> from >> to >> time;
        edge[from].push_back({to, time});
        edge[to].push_back({from,time});
    }

    dijkstra(0);
    if(cost[n-1] == INF) cost[n-1] = -1;
    cout << cost[n-1];
}