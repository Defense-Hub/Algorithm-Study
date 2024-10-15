#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int cnt, limit;
    cin >> cnt >> limit;
    vector<int> nums(cnt);

    for(int i = 0; i < cnt; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int lpt = 0, rpt = 0;
    int minN = MAX;
    while(lpt < cnt && rpt < cnt){
        int res = nums[rpt] - nums[lpt];
        if(res < limit){
            rpt++;
        }
        else if(res > limit){
            lpt++;
            minN = min(minN, res);
        }
        else{
            minN = limit;
            break;
        }
    }

    cout << minN;
}