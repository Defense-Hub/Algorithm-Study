#include<iostream>
#include<vector>
#include<queue>

// https://acmicpc.net/problem/1238

#define MAX 1e9

using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1001]; // 인접 리스트 (도시, 거리)

// 다익스트라 함수: 시작점을 인자로 받아 각 도시까지의 최단 거리를 계산
vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, MAX); // 최단 거리 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

    dist[start] = 0;
    pq.push({ 0, start }); // 시작점에서의 거리 0

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 이미 처리된 노드라면 스킵
        if (cur_dist > dist[cur_node]) continue;

        // 현재 노드와 연결된 다른 노드들에 대해 최단 거리 갱신
        for (int i = 0; i < adj[cur_node].size(); i++) {
            int next_node = adj[cur_node][i].first;
            int next_dist = cur_dist + adj[cur_node][i].second;

            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }

    return dist;
}

int main() {
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        adj[s1].push_back({ s2, s3 });
    }

    vector<int> to_party = dijkstra(x);

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue; 
        vector<int> from_party = dijkstra(i);
        max_time = max(max_time, from_party[x] + to_party[i]);
    }

    cout << max_time << endl;

    return 0;
}
