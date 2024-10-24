#include <iostream>
#include <vector>
#include <queue>
// 14:10 ~ 14:40
using namespace std;

int main() {
    int buildCnt;
    cin >> buildCnt;
    vector<int> bTime(buildCnt+1);
    vector<int> inDegree(buildCnt + 1, 0);
    vector<vector<int>> adj(buildCnt + 1);
    vector<int> res(buildCnt + 1, 0);

    int input;
    for(int i = 1; i <= buildCnt; i++){
        cin >> bTime[i];
        while(true){
            cin >> input;
            if(input == -1) break;
            inDegree[i]++;
            adj[input].push_back(i);
        } 
    }

    queue<int> q;
    for(int i = 1; i <= buildCnt; i++){
        if(inDegree[i] == 0){
            q.push(i);
            res[i] = bTime[i];
        }           
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nBuild : adj[cur]){
            res[nBuild] = max(res[nBuild], res[cur] + bTime[nBuild]);
            inDegree[nBuild]--;
            if(inDegree[nBuild] == 0)
                q.push(nBuild);
        }
    }

    for(int i = 1; i <= buildCnt; i++){
        cout << res[i] << "\n";
    }
}