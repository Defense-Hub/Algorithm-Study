#include <iostream>
#include <vector>
#define MAX 1000001
#define DIV 1000000009
using namespace std;

/*
dp[1] = 1
dp[2] = 1+1, 2
dp[3] = 1+1+1, 2+1 dp[2] // 1+2 dp[1] // 3
dp[4] = 1+1+1+1, 2+1+1, 1+2+1, 3+1 dp[3] // 1+1+2, 2+2 dp[2] // 1+3 dp[1]
*/

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<long long> dp(MAX);

    int tc;
    cin >> tc;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int k = 0; k < tc; k++){
        int n;
        cin >> n;
        for(int j = 4; j <= n; j++){
            dp[j] = (dp[j-1]%DIV + dp[j-2]%DIV + dp[j-3]%DIV)%DIV;
        }

        cout << dp[n] << "\n";
    }
}