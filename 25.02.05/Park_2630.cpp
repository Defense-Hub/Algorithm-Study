#include <iostream>
#include <vector>
using namespace std;
int n;
int wCnt = 0;
int bCnt = 0;
vector<vector<int>> board;


// 맨 왼쪽 좌표
void fold(int sy, int sx, int n){
    // 4분면 체크
    // 1사분면 
    bool cut = false;
    int colorIdx = board[sy][sx];

    for(int y = sy; y < sy + n; y++){
        for(int x = sx; x < sx + n; x++){
            if(board[y][x] != colorIdx){
                cut = true;
                break;
            }
        }
        if(cut) break;
    }

    if(cut){
        // 1사분면
        fold(sy, sx, n/2);
        // 2사분면
        fold(sy, sx + n/2, n/2);
        // 3사분면
        fold(sy + n/2, sx, n/2);
        // 4사분면
        fold(sy + n/2, sx + n/2, n/2);
    }
    else{
        if(colorIdx == 1) bCnt++;
        else wCnt++;
    }

}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    cin >> n;
    board.resize(n,vector<int>(n));
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> board[y][x];
        }
    }

    // 재귀를 돌릴것
    // 4분면을 나눠서 돌림
    // 1사분면 y[0, n/2), x[0, n/2)
    // 2사분면 y[0, n/2), x[n/2,n)
    // 3사분면 y[n/2, n), x[0, n/2)
    // 4사분면 y[n/2, n), x[n/2,n)
    fold(0,0,n);

    cout << wCnt << "\n" << bCnt;
}