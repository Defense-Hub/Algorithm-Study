#include <iostream>
#include <unordered_map>
using namespace std;
long long n,p,q;
unordered_map<long long, long long> mp;
//REF : https://allmymight.tistory.com/161
long long solve(long long num){
    long long ans;
    if(mp.find(num) != mp.end())
        return mp[num];
    ans = solve(num/p) + solve(num/q);
    mp[num] = ans;
    return ans;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    cin >> n >> p >> q;
    
    // 1,000,000,000,000
    // dp[n] = dp[n/p] + dp[n/q]
    // dp[n] = dp[n/p^2] + dp[n/q^2] + 2dp[n/(p*q)]
    // dp[7] = dp[3] + dp[2]
    // dp[7] = dp[1] + dp[1] + dp[1] + dp[0]
    // dp[7] = (dp[0] * 4) + (dp[0] * 3)
    mp[0] = 1;
    if(n == 0) cout << 1;
    else cout << solve(n/p) + solve(n/q);
}