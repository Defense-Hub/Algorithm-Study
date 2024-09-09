#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[51]; // 인접 리스트: (연결된 마을 번호, 거리)

vector<int> dijkstra(int N, int start) {
    vector<int> dist(N + 1, 1e9); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    
    dist[start] = 0;
    pq.push({0, start}); // 시작점 (거리 0, 1번 마을)

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // 이미 처리된 노드라면 건너뛴다
        if (current_dist > dist[current_node]) continue;

        // 현재 노드와 연결된 다른 노드들 확인
        for (auto next : adj[current_node]) {
            int next_node = next.first;
            int next_dist = current_dist + next.second;

            // 더 짧은 경로를 발견하면 갱신하고 우선순위 큐에 추가
            if (next_dist < dist[next_node]) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }

    return dist;
}

int solution(int N, vector<vector<int>> road, int K) {

    for (auto r : road) {
        int a = r[0], b = r[1], c = r[2];
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> shortest_distances = dijkstra(N, 1);

    // K시간 이내에 배달 가능한 마을의 수 계산
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (shortest_distances[i] <= K) {
            answer++;
        }
    }

    return answer;
}
