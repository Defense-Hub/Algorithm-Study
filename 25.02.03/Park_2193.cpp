#include <iostream>
#include <vector>
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int n;
    cin >> n;
    vector<vector<long long>> dp(91,vector<long long>(2));
    // dp[1][0] = 0, dp[1][1] = 1 
    // dp[2][0] = 1, dp[2][1] = 0
    // dp[3][0] = 1(100), dp[3][1] = 1(101)
    // dp[4][0] = (dp[3][0] + dp[3][1]), dp[4][1] = (dp[3][0])_1000,1010 / 1001
    // dp[n][0] = (dp[n-1][0] + dp[n-1][1])_10000 10100 10010, dp[n][1] = dp[n-1][0] 10001 10101

    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;

    for(int i = 3; i <= n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0] + dp[n][1];

}