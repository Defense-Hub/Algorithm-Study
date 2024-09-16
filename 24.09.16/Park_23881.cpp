#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, cnt;
    cin >> n >> cnt;
    vector<int> nums(n);
    vector<pair<int,int>> res;
    for(int k = 0; k < n; k++){
        cin >> nums[k];
    }

    for(int k = n - 1; k > 0; k--){
        int maxN = nums[k];
        int idx = k;
        bool isChange = false;
        for(int j = k-1; j >= 0; j--){
            if(nums[j] > maxN){
                isChange = true;
                maxN = nums[j];
                idx = j;
            }
        }

        if(isChange){
            nums[idx] = nums[k];
            nums[k] = maxN;
            res.push_back({nums[idx], nums[k]});
        }
    }

    if(res.size() <= cnt - 1)
        cout << -1;
    else
        cout << res[cnt - 1].first << " " << res[cnt - 1].second;
}