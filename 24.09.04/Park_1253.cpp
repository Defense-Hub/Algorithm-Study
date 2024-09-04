// RE

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){ // 2000 2000 = 4 000 000
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int answer = 0;
    for(int k = 0; k < n; k++){
        int st = 0, ed = n-1;
        while(st < ed){
            if(st == k){
                st++; 
                continue;
            }

            if(ed == k){
                ed--;
                continue;
            }

            int sum = nums[st] + nums[ed];
            if(nums[k] > sum) st++;
            else if(nums[k] == sum){
                answer++;
                break;
            }
            else ed--;
        }
    }

    cout << answer;
}