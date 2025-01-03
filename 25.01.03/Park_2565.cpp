#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1745 ~ 1803
// Ref : https://yabmoons.tistory.com/572

/*
1 8
2 2
3 9
4 1
6 4
7 6
9 7
10 10
*/
int n;
vector<pair<int,int>> lines;
vector<int> dp;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    lines.resize(n);
    dp.resize(n);
    for(int k = 0; k < n; k++){
        cin >> lines[k].first >> lines[k].second;
    }
    sort(lines.begin(), lines.end());
    // 왼쪽 기준으로 정렬 이후 우측에서 가장 긴 증가하는 수열을 N에서 뺀다.
    int cnt = 0;
    for(int k = 0; k < n; k++){
        dp[k] = 1;
        for(int j = 0; j < k; j++){
            if(lines[k].second > lines[j].second)
                dp[k] = max(dp[k], dp[j] + 1);
        }
        cnt = max(cnt, dp[k]);
    }

    cout << n - cnt; 
}