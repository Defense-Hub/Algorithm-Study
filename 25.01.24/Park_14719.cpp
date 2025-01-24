#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// REF : https://hwan-shell.tistory.com/276
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    // 한칸 한칸 기준으로
    // 왼쪽 가장 큰 값, 오른쪽 가장 큰 값 체크
    int h, w;
    cin >> h >> w;

    vector<int> board(w);
    for(int i = 0; i < w; i++){
        cin >> board[i];
    }
    int ans = 0;
    // 현재 기준 왼쪽 최대값, 오른쪽 최대값
    for(int i = 1; i < w; i++){
        // 왼쪽
        int leftMax = -1;
        int rightMax = -1;
        for(int l = 0; l < i; l++) leftMax = max(leftMax, board[l]);
        for(int r = w-1; r > i; r--) rightMax = max(rightMax, board[r]);
        ans += max(0, min(leftMax, rightMax) - board[i]);
    }

    cout << ans;
}