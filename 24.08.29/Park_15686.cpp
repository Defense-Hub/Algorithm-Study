#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<int>> board;
vector<bool> isVisit;

vector<pair<int,int>> chicken;
vector<pair<int,int>> home;

int answer = INF;
int sz, chCnt;

void Check(){
    int disSum = 0;
    for(int i = 0; i < home.size(); i++){ // O(100 * 13)
        int minDis = INF;
        for(int k = 0; k < chicken.size(); k++){
            if(!isVisit[k]) continue;
            int dis = abs(chicken[k].first - home[i].first) + abs(chicken[k].second - home[i].second);
            minDis = min(minDis, dis);
            
        }
        if(minDis == INF) continue;
        disSum += minDis;
    }
    if(disSum != 0)
        answer = min(answer, disSum);
}


void Batch(int idx, int cnt){
    if(cnt > chCnt) return;
    
    for(int k = idx; k < chicken.size(); k++){ // 13 C 2 = 13 * 6 = 78
        Check();

        if(isVisit[k]) continue;
        isVisit[k] = true;
        Batch(k, cnt + 1);
        isVisit[k] = false;
    }
}

int main (){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    // 치킨집 배치
    
    cin >> sz >> chCnt;

    board.resize(sz, vector<int> (sz));
    // 입력 O(2500)
    for(int y = 0; y < sz; y++){
        for(int x = 0; x < sz; x++){
            cin >> board[y][x];
            if(board[y][x] == 1) home.push_back({y,x});
            if(board[y][x] == 2) chicken.push_back({y,x});
        }
    }

    isVisit.resize(chicken.size());
    // 치킨집 배치
    Batch(0, 0);


    cout << answer;
    return 0;
}