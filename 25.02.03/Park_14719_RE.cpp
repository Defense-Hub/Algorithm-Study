#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w;
    cin >> h >> w;

    vector<int> board(w);
    for(int i = 0; i < w; i++){
        cin >> board[i];
    }

    // 현재 위치를 기준으로 (왼쪽 max, 오른쪽 max 계산 둘 중 작은 값 - 현재 값) 을 +
    int ans = 0;
    for(int i = 0; i < w; i ++){
        int leftMax = -1;
        int rightMax = -1;
        for(int l = 0; l < i; l++) leftMax = max(leftMax, board[l]);
        for(int r = w-1; r > i; r--) rightMax = max(rightMax, board[r]);

        ans += max(0, min(leftMax, rightMax) - board[i]);
    }

    cout << ans;
}