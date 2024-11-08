#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 16:00 ~ 16:40
int main() {
    int comCnt, lineCnt, from, to, cost;
    int answer = 0;
    cin >> comCnt >> lineCnt;

    vector<bool> isVisit(comCnt + 1, false);
    vector<vector<pair<int,int>>> graph(comCnt + 1);
    // cost, node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // cost, from, to
    for(int i = 0; i < lineCnt; i++){
        cin >> from >> to >> cost;
        graph[from].push_back({cost, to});
        graph[to].push_back({cost, from});
    }

    int curCost, curNode, nextNode;
    pq.push({0,1});
    while(!pq.empty()){
        curCost = pq.top().first;
        curNode = pq.top().second;
        pq.pop();
        if(isVisit[curNode]) continue;
        isVisit[curNode] = true;
        answer += curCost;
        for(auto next : graph[curNode]){
            nextNode = next.second;
            if(!isVisit[nextNode])
                pq.push(next);
        }
    }
    
    cout << answer;
}