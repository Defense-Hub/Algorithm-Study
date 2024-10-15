#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int length, width;
    cin >> length >> width;
    vector<string> board(length);
    vector<int> minStar(width, MAX);
    vector<int> maxGround(width,0);

    for(int y = length -1; y >= 0; y--){
        cin >> board[y];
        for(int x = 0; x < width; x++){
            if(board[y][x] == 'X') minStar[x] = y;
            if(board[y][x] == '#' && maxGround[x] == 0) maxGround[x] = y;
        }
    }
    
    int minDiff = length;
    for(int x = 0; x < width; x++){
        minDiff = min(minDiff, (minStar[x] - maxGround[x]));
    }

    minDiff -= 1;
    // 각 X좌표로부터 이동가능한 최대 거리를 계산
    // 그 중 가장 작은 값 - 1만큼 아래로 이동
    for(int y = 0; y < length; y++){
        for(int x = 0; x < width; x++){
            if(board[y][x] == 'X'){
                board[y-minDiff][x] = 'X';
                board[y][x] = '.';
            } 
        }
    }
    
    for(int y = length - 1; y >= 0; y--){
        for(int x = 0; x < width; x++){
            cout << board[y][x];
        }
        cout << endl;
    }
}