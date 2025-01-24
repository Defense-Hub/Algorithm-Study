#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    // 왼쪽 기준으로 정렬 / 오른쪽 기준 가장 큰 오름차순
    // 1 8
    // 2 2
    // 3 9
    // 4 1
    // 6 4
    // 7 6
    // 9 7
    // 10 10

    // ans = n - 가장 길게 증가 하는 수
    vector<int> dp(n, 1);
    int cnt = -1;
    // 지금 체크하려는 idx
    for(int i = 0; i < n; i++){
        // 이전까지의 idx들 점검 추가로 연결할 수 있는 부분 +
        for(int j = 0; j < i; j++){
            if(v[i].second > v[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cnt = max(cnt, dp[i]);
    }

    cout << n - cnt;
}