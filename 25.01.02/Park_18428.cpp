#include <iostream>
#include <vector>
using namespace std;
// 감시피하기 _ 13 55 ~ 14 48

int n;
vector<vector<char>> board;
bool CanFind(){
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            // 선생님이 아닌 경우 제외
            if(board[y][x] != 'T') continue;
            // 오른쪽
            for(int i = x; i < n; i++){
                if(board[y][i] == 'O') break;
                if(board[y][i] == 'S') return true;
            }
            // 왼쪽
            for(int i = x; i >= 0; i--){
                if(board[y][i] == 'O') break;
                if(board[y][i] == 'S') return true;
            }
            // 위
            for(int i = y; y < n; i++){
                if(i >= n) break;
                if(board[i][x] == 'O') break;
                if(board[i][x] == 'S') return true;
            }
            // 아래
            for(int i = y; y >= 0; i--){
                if(i < 0) break;
                if(board[i][x] == 'O') break;
                if(board[i][x] == 'S') return true;
            }
        }
    }

    return false;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> n;
    board.resize(n, vector<char>(n));
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cin >> board[y][x];
        }
    }

    // 장애물 설치 3개 for문 3중첩 최대 36^3 = 216^2 = 46,656 
    // 안될 경우 dfs/bfs고려 필요
    bool isNotFind;
    for(int a = 0; a < n*n; a++){
        for(int b = 0; b < n*n; b++){
            for(int c = 0; c < n*n; c++){
                isNotFind = false;
                // 겹치는 경우 제외
                if(a == b || b == c || a == c) continue;
                
                int ay = a/n; int ax = a%n;
                int by = b/n; int bx = b%n;
                int cy = c/n; int cx = c%n;

                // 빈자리가 아닌 경우 제외
                if(board[ay][ax] != 'X') continue;
                if(board[by][bx] != 'X') continue;
                if(board[cy][cx] != 'X') continue;

                board[ay][ax] = 'O';
                board[by][bx] = 'O';
                board[cy][cx] = 'O';
                if(!CanFind()){
                    isNotFind = true;
                    break;
                }
                board[ay][ax] = 'X';
                board[by][bx] = 'X';
                board[cy][cx] = 'X';
            }
            if(isNotFind) break;
        }
        if(isNotFind) break;
    }
    // 탐지 가능? -> 상하 좌우
    // 모든 경우에서 하나라도 yes면 break
    // 다 돌아도 yes가 없으면 no
    if(isNotFind) cout << "YES";
    else cout << "NO";
}