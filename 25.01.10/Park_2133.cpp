#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 17 15 ~ 17 35
// REF https://yabmoons.tistory.com/536
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;

    if(n%2 != 0){
        cout << 0;
        return 0;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    // f[n] = f[n-2]*f[2] + f[n-4] * 2 + f[n-6] * 2 + f[n-8] * 2
    for(int i = 4; i <= n; i+= 2){
        dp[i] = dp[i-2] * dp[2];
        for(int j = i - 4; j >= 0; j -= 2){
            dp[i] += (dp[j] * 2);
        }
    }

    cout << dp[n];
}