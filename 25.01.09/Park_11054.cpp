#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 15:40 ~

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    vector<int> nums(n);
    // 가장 긴 증가하는 수열 + 가장 긴 감소하는 수열
    // index 전체에 기반하는 것이 아닌 단계별로 계산하고 그 합이 가장 큰 것을 도출
    vector<int> dp(n, 1);
    vector<int> r_dp(n, 1);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // 증가하는 수열부터 체크
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            // 들어온 숫자가 증가하는 숫자라면 안먹고 그대로 가느냐, 
            // 현재 들어온 숫자에 기존 숫자를 합쳐 증가시키느냐
            // 둘 중 큰 것을 저장
            if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    
    // 감소하는 수열
    for(int i = n-1; i >= 0; i--){
        r_dp[i] = 1;
        for(int j = n-1; j > i; j--){
            // 들어온 숫자가 감소하는 숫자라면 안먹고 그대로 가느냐, 
            // 현재 들어온 숫자에 기존 숫자를 합쳐 증가시키느냐
            // 둘 중 큰 것을 저장
            if(nums[j] < nums[i]) r_dp[i] = max(r_dp[i], r_dp[j] + 1);
        }
    }

    int maxV = -1;
    for(int i = 0; i < n; i++){
        maxV = max(maxV, dp[i] + r_dp[i]);
    }

    cout << maxV - 1;
}