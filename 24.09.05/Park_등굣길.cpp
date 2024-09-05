#include <string>
#include <vector>
#include <iostream>
#define DIV 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> board(n, vector<int> (m));
    
    for(int i = 0; i < puddles.size(); i++){
        int x = puddles[i][0] - 1;
        int y = puddles[i][1] - 1;
        board[y][x] = -1;
    }
    
    board[0][0] = 1;
    
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(y == 0 && x == 0) continue;
            if(board[y][x] == -1) continue;
            
            if(y >= 1){
                if(board[y-1][x] != -1)
                    board[y][x] += board[y-1][x]%DIV;    
            }
            
            if(x >= 1){
                if(board[y][x-1] != -1)
                    board[y][x] += board[y][x-1]%DIV;    
            }
            
            board[y][x] %= DIV;
        }
    }
    answer = board[n-1][m-1];
    return answer;
}