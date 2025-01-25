#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
#define DIV 1000000009
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);     
    int tc;
    cin >> tc;

    vector<vector<long long>> dp(MAX + 1, vector<long long>(4,0));
    //dp[n][k] n까지 가는데 이번에 k을 써서 갈거야
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    // 1, 2, 3 
    // 이전에 1 사용, 2 사용, 3 사용
    // 2,3 사용해서 찾아오기
    // dp[n][1] = dp[n-1][2] + dp[n-1][3] 
    // dp[3] 1 + 2, 2 + 1, 3

    for(int n = 4; n <= MAX; n++){
        dp[n][1] = (dp[n-1][2] % DIV + dp[n-1][3] % DIV) % DIV;
        dp[n][2] = (dp[n-2][1] % DIV + dp[n-2][3] % DIV) % DIV;
        dp[n][3] = (dp[n-3][1] % DIV + dp[n-3][2] % DIV) % DIV;
    }
    for(int i = 0; i < tc; i++){
        int target;
        cin >> target;
        cout << (dp[target][1] % DIV + dp[target][2] % DIV + dp[target][3] % DIV) % DIV << "\n";
    }
}