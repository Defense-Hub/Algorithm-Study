#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    // y좌표 먼저 이동 -> x좌표 이동
    // 루트별 초단위 좌표를 저장 둘다 같은 경우가 발생하는 경우 answer++
    // [route][초] = {좌표}
    vector<vector<pair<int,int>>> routesPoint;
    int current, target;
    int maxTime = 0;
    pair<int,int> cur, tar;
    vector<pair<int,int>> routePos;
    
    for(vector<int> route : routes){ // O(100)
        routePos.clear();
        current = route[0];
        cur = {points[current-1][0], points[current-1][1]};
        routePos.push_back(cur);
        for(int i = 1; i < route.size(); i++){ // O(100)
            target = route[i];
            tar = {points[target-1][0], points[target-1][1]};
            while(true){
                if(cur.first == tar.first && cur.second == tar.second){
                    current = target;
                    cur = tar;
                    break;
                }
                if(cur.first != tar.first){
                    if(cur.first > tar.first)
                        cur.first--;
                    else
                        cur.first++;
                }
                else if(cur.second != tar.second){
                    if(cur.second > tar.second)
                        cur.second--;
                    else
                        cur.second++;
                }
                routePos.push_back(cur);
            }
        }
        maxTime = max(maxTime, (int)routePos.size());
        routesPoint.push_back(routePos);
    }
    
    vector<vector<int>> visitCnt;
    
    for(int t = 0; t < maxTime; t++){
        // 초기화
        visitCnt.assign(101, vector<int>(101,0));
        // 루트 전체 비교
        for(int i = 0; i < routesPoint.size(); i++){
            if(routesPoint[i].size() <= t) continue;
            // 각 루트 별 지나가는 동선 체크
            int y = routesPoint[i][t].first;
            int x = routesPoint[i][t].second;
            visitCnt[y][x]++;
        }
        
        for(int y = 0; y < 101; y++){
            for(int x = 0; x < 101; x++){
                if(visitCnt[y][x] > 1) answer++;
            }
        }
    }
    
    return answer;
}