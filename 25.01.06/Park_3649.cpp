#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 19:30 ~
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int target;
    int numCnt;
    while(cin >> target >> numCnt){
        vector<int> nums(numCnt);
        for(int i = 0; i < numCnt; i++){
            cin >> nums[i];
        }
        target *= 10000000;
        sort(nums.begin(), nums.end());
        // 1 2 9999998 9999999
        int left = 0;
        int right = numCnt - 1;
        bool isFind = false;
        while(left <= right){
            if(nums[left] + nums[right] > target) right--;
            else if(nums[left] + nums[right] < target) left++;
            else{
                cout << "yes " << nums[left] << " " << nums[right] << endl;
                isFind = true;
                break;
            }
        }
        if(!isFind) cout << "danger" << endl;
    }
}