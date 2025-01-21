#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> board;
void PrintStar(int y, int x){
    board[y][x] = '*';
    board[y+1][x-1] = '*';
    board[y+1][x+1] = '*';
    for(int i = 0; i < 5; i++)
        board[y+2][x-2+i] = '*';
}

void triangle(int len, int y, int x){
    if(len == 3){
        PrintStar(y,x);
        return;
    }
    // 위
    triangle(len/2, y, x);
    // 왼쪽
    triangle(len/2, y + len/2, x - len/2);
    // 오른쪽
    triangle(len/2, y + len/2, x + len/2);
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    board.resize(n, vector<char>(2*n-1, ' '));

    triangle(n,0,n-1);

    for(int y = 0; y < n; y++){
        for(int x = 0; x < 2*n-1; x++){
            cout << board[y][x];
        }
        cout << "\n";
    }
}