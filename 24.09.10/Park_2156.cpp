#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 6 10 13 9 8 1
// dp[1] = arr[1]
// dp[2] = arr[1] + arr[2]
// dp[3] = arr[1] + arr[2] / arr[1] + arr[3] / arr[2] + arr[3]
// dp[4] = arr[1] + arr[2] + arr[4] / arr[2] + arr[3] / arr[1] + arr[3] + arr[4]
int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> dp(n + 1);

    for(int k = 1; k <= n; k++){
        cin >> arr[k];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    for(int k = 3; k <= n; k++){
        dp[k] = max({dp[k-1], dp[k-2] + arr[k], dp[k-3] + arr[k-1] + arr[k]});
    }

    cout << dp[n];
}