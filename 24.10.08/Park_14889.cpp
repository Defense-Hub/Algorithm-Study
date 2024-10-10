#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;
int sz;
int res = MAX;
vector<vector<int>> board;
vector<bool> sel;
void calc(){
    int sumA = 0;
    int sumB = 0;

    for(int a = 1; a <= sz; a++){
        for(int b = 1; b <=sz; b++){
            if(sel[a] && sel[b]) sumA += board[a][b];
            else if(!sel[a] && !sel[b]) sumB += board[a][b];
        }
    }

    int diff = sumA - sumB;
    if(diff < 0) diff *= -1;
    res = min(res, diff);
}

void combination(int idx, int depth){
    if(depth == sz/2){
        calc();    
        return;
    }
    for(int i = idx+1; i <= sz; i++){
        sel[i] = true;
        combination(i, depth+1);
        sel[i] = false;
    }
}


int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> sz;
    board.assign(sz+1, vector<int>(sz+1 , 0));
    sel.assign(sz+1, false);
    for(int y = 1; y <= sz; y++){
        for(int x = 1; x <= sz; x++){
            cin >> board[y][x];
        }
    }
    // 6명 1, 2, 3 / 4, 5, 6 => 3P2 => S12 + S23 + S13 + S21 + S32 + S31
    // 최대 10P2 = 10*9 = 90
    // 20 C 10 = 184,756
    // 팀원 뽑기
    combination(0, 0);
    
    cout << res;
}