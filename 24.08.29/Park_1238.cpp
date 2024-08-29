#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

struct Route{
    int dt;
    int cost;
};

vector<vector<Route>> roadData;
vector<vector<Route>> reRoadData;
int nodeCnt, edgeCnt, targetPos;

struct cmp{
    bool operator()(Route r1, Route r2){
        return r1.cost < r2.cost;
    }
};

vector<int> Dijkstra(int st){
    // cost, nextPos
    priority_queue<Route, vector<Route>, cmp> pq;
    vector<int> dist(nodeCnt+1, INF);
    for(int k = 0; k < roadData[st].size(); k++){
        pq.push(roadData[st][k]);
        dist[roadData[st][k].dt] = roadData[st][k].cost;
    }

    while(!pq.empty()){
        int curPt = pq.top().dt;
        int curCost = pq.top().cost;
        pq.pop();
        
        if(curCost > dist[curPt]) continue;

        for(int k = 0; k < roadData[curPt].size(); k++){
            int nextPt = roadData[curPt][k].dt;
            int nextCost = curCost + roadData[curPt][k].cost;

            if(nextCost < dist[nextPt]){
                dist[nextPt] = nextCost;
                pq.push({nextPt, nextCost});
            }
        }
    }

    return dist;
}

vector<int> reDijkstra(int st){
    // cost, nextPos
    priority_queue<Route, vector<Route>, cmp> pq;
    vector<int> dist(nodeCnt+1, INF);
    for(int k = 0; k < reRoadData[st].size(); k++){
        pq.push(reRoadData[st][k]);
        dist[reRoadData[st][k].dt] = reRoadData[st][k].cost;
    }

    while(!pq.empty()){
        int curPt = pq.top().dt;
        int curCost = pq.top().cost;
        pq.pop();
        
        if(curCost > dist[curPt]) continue;

        for(int k = 0; k < reRoadData[curPt].size(); k++){
            int nextPt = reRoadData[curPt][k].dt;
            int nextCost = curCost + reRoadData[curPt][k].cost;

            if(nextCost < dist[nextPt]){
                dist[nextPt] = nextCost;
                pq.push({nextPt, nextCost});
            }
        }
    }

    return dist;
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> nodeCnt >> edgeCnt >> targetPos;
    roadData.resize(nodeCnt + 1);
    reRoadData.resize(nodeCnt + 1);

    for(int k = 0; k < edgeCnt; k++){
        int st, dt, cost;
        cin >> st >> dt >> cost;
        roadData[st].push_back({dt, cost});
        reRoadData[dt].push_back({st,cost});
    }

    int answer = 0;
    vector<int> to = reDijkstra(targetPos);
    vector<int> from = Dijkstra(targetPos);
    to[targetPos] = 0;
    from[targetPos] = 0;
    for(int k = 1; k <= nodeCnt; k++){ // O(1000)
        answer = max(answer, to[k] + from[k]);
    }

    cout << answer;
}