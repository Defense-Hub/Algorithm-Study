#include <iostream>
#include <vector>
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> dp(n,1);
    vector<int> list[n];
    vector<int> ans;
    
    for(int i = 0; i < n; i++){
        list[i].push_back(v[i]);
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                // 갱신되는 경우
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    list[i].clear();
                    list[i] = list[j];
                    list[i].push_back(v[i]);
                }
            }
        }
        // 최대 길이 갱신 시
        if(list[i].size() > ans.size())
            ans = list[i];
    }

    cout << ans.size() << "\n";
    for(int num : ans){
        cout << num << " ";
    }
}