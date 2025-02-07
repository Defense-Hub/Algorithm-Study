#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,r;
vector<vector<int>> board;
vector<bool> isVisit;
vector<int> res;
int idx = 1;
void bfs(int st){
    isVisit[st] = true;
    res[st] = idx++;
    queue<int> q;
    q.push(st);

    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < board[cur].size(); i++){
            int next = board[cur][i];
            if(isVisit[next]) continue;
            isVisit[next] = true;
            res[next] = idx++;
            q.push(next);
        }
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    cin >> n >> m >> r;
    board.resize(n+1);
    isVisit.resize(n+1, false);
    res.resize(n+1, 0);
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
    for(int i = 1; i <= n; i++)
        sort(board[i].begin(), board[i].end());
    bfs(r);

    for(int i = 1; i <= n; i++){
        cout << res[i] << "\n";
    }
}