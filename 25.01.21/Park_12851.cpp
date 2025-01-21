#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 5 -> 4 -> 8 -> 16 -> 17
// 5 -> 10 -> 9 -> 18 -> 17
// 17 -> 16 -> 8 -> 4 -> 5
// 17 -> 18 -> 9 -> 10 -> 5
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int from, to;
    cin >> from >> to;
    // cur node, depth
    queue<pair<int,int>> q;
    vector<bool> isVisit(1000001, false);
    q.push({from, 0});
    int minVal = 0;
    int minCnt = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        isVisit[cur] = true;
        isVisit[to] = false;

        if(minVal == 0 && cur == to){
            minVal = depth;
            minCnt++;
            continue;;
        }

        if(minVal == depth && cur == to){
            minCnt++;
            continue;
        }

        if(cur - 1 >= 0 && !isVisit[cur-1])
            q.push({cur-1, depth+1});
        if(cur + 1 <= to && !isVisit[cur + 1])
            q.push({cur+1, depth+1});
        if(cur * 2 <= to + 1 && !isVisit[cur * 2])
            q.push({cur*2, depth+1});
    }   
    cout << minVal << "\n" << minCnt;
}