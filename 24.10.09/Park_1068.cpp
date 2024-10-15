#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
int leafCnt = 0;
int deleteNode;
void dfs(int st){
    if(board[st].size() == 0){
        leafCnt++;
        return;
    }
    for(int k = 0; k < board[st].size(); k++){
        if(board[st].size() == 1 && board[st][k] == deleteNode) leafCnt++;
        if(board[st][k] == deleteNode) continue;
        dfs(board[st][k]);
    }
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int cnt; 
    cin >> cnt;
    board.resize(cnt);

    int st;
    for(int i = 0; i < cnt; i++){
        int from;
        cin >> from;

        if(from == -1){
            st = i;
        }
        else{
            board[from].push_back(i);
        }
    }
    cin >> deleteNode;
    if(st == deleteNode) leafCnt = 0;
    else
        dfs(st);
    cout << leafCnt;
}