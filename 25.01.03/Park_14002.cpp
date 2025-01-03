#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010
using namespace std;
// 14002
// 18:05 ~ 18:35
// REF : https://yabmoons.tistory.com/578

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> dp(n);
    vector<int> list[MAX];
    vector<int> ans;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        list[i].push_back(nums[i]);
        for(int k = 0; k < i; k++){
            if(nums[i] > nums[k]){
                if(dp[i] < dp[k] + 1){
                    list[i].clear();
                    list[i] = list[k];
                    list[i].push_back(nums[i]);
                    dp[i] = dp[k] + 1;
                }
            }
        }

        if(ans.size() < list[i].size())
            ans = list[i];
    }

    cout << ans.size() << endl;
    for(int n : ans){
        cout << n << " ";
    }
}