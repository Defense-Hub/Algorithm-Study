#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

// 1번 마을부터 각 마을로 가는 최단 거리를 싹 계산하고
// vector<int> cost 순회하면서 K보다 작거나 같은 cost를 가지는 수를 계산

struct edge{
    int dt;
    int dist;
};

struct compare{
    bool operator()(const edge& e1, const edge& e2){
        return e1.dist < e2.dist;
    }
};

vector<int> dist;

// [st] = {dt, dist};
vector<vector<edge>> roadData;

void Dijkstra(int st){
    priority_queue<edge, vector<edge>, compare> pq;
    pq.push({1,0});
    dist[1] = 0;
    
    while(!pq.empty()){
        int curNode = pq.top().dt;
        int curDist = pq.top().dist;
        pq.pop();
        
        for(int k = 0; k < roadData[curNode].size(); k++){
            int nextNode = roadData[curNode][k].dt;
            int nextDist = curDist + roadData[curNode][k].dist;
            if(nextDist < dist[nextNode]){
                dist[nextNode] = nextDist;
                pq.push({nextNode, nextDist});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    dist.resize(N + 1, INF);
    roadData.resize(N + 1);
    for(int k = 0; k < road.size(); k++){
        int st = road[k][0];
        int dt = road[k][1];
        int dst = road[k][2];
        roadData[st].push_back({dt, dst});
        roadData[dt].push_back({st, dst});
    }
    
    Dijkstra(1);
    
    for(int k = 1; k <= N; k++){
        if(dist[k] <= K) answer++;
    }
    
    return answer;
}