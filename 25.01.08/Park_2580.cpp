#include <iostream>
#include <vector>
using namespace std;
// 

vector<vector<int>> board(9,vector<int>(9));
vector<pair<int,int>> zeroPos;
int zeroCnt = 0;

bool isFind = false;

bool check(int& low, int& col) {
    for (int i = 0; i < 9; i++) {
        // 가로줄에서 일치하는 것이 있는지 판별
        if (i != col && board[low][i] == board[low][col]) {
            return false;
        }
        // 세로줄에서 일치하는 것이 있는지 판별
        if (i != low && board[i][col] == board[low][col]) {
            return false;
        }
    }

    // 3x3 영역에서 일치하는 것이 있는지 판별
    int tmp_1 = 3 * (int)(low / 3);
    int tmp_2 = 3 * (int)(col / 3);

    for (int i = tmp_1; i < tmp_1 + 3; i++) {
        for (int j = tmp_2; j < tmp_2 + 3; j++) {
            if (i != low && j != col) {
                if (board[i][j] == board[low][col]) {
                    return false;
                }
            }
        }
    }

    return true;
}

void sudoku(int idx){
    if(idx == zeroCnt){
        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                cout << board[y][x] << " ";
            }
            cout << endl;
        }
        isFind = true;
        return;
    }
    
    if(isFind) return;
    
    int y = zeroPos[idx].first;
    int x = zeroPos[idx].second;

    for(int i = 1; i <= 9; i++){
        board[y][x] = i;
        if(check(y,x))
            sudoku(idx+1);
        board[y][x] = 0;
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    for(int y = 0; y < 9; y++){
        for(int x = 0; x < 9; x++){
            cin >> board[y][x];
            if(board[y][x] == 0) {
                zeroPos.push_back({y,x});
                zeroCnt++;
            }
        }
    }
    
    // 숫자를 임의로 하나씩 넣고
    // 가로, 세로, 네모칸 체크 만족하면 재귀 추가 진입, 아니면 out
    sudoku(0);
}