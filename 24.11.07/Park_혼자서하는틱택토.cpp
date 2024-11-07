#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    // O -> X -> O
    // OOO || XXX 1개 이상 -> 반대 완성본이 없어야함, 
    
    int cntO = 0;
    int cntX = 0;
    // O의 갯수 == X의 갯수 || X 갯수 + 1
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(board[y][x] == 'O') cntO++;
            else if(board[y][x] == 'X') cntX++;
        }
    }
    if(!(cntO == cntX || cntO == cntX + 1)) return 0;
    if(cntO > 5 || cntX > 4) return 0;
    
    int LineO = 0;
    int LineX = 0;
    
    // 가로 체크
    for(int y = 0; y < 3; y++){
        if(board[y].compare("OOO") == 0) LineO++;
        else if(board[y].compare("XXX") == 0) LineX++;
    }
    // 세로
    for(int x = 0; x < 3; x++){
        if(board[0][x] == 'O' && board[1][x] == 'O' && board[2][x] == 'O') LineO++;
        else if(board[0][x] == 'X' && board[1][x] == 'X' && board[2][x] == 'X') LineX++;
    }
    // 대각선
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') LineO++;
    else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') LineX++;
    
    if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') LineO++;
    else if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') LineX++;
    

    
    if(LineO > 0 && LineX > 0) return 0;
    if(LineO > 2 || LineX > 1) return 0;
    if(LineO > 0 && cntO != cntX + 1) return 0;
    if(LineX > 0 && cntO != cntX) return 0;
    
    return answer;
}