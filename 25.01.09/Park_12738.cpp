#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 16 15 ~ 16 33
// REF : https://yabmoons.tistory.com/560

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    //이분 탐색?
    vector<int> V;
    for(int i = 0; i < n; i++){ // n
        if(V.size() == 0 || V[V.size() -1] < nums[i]) V.push_back(nums[i]);
        else{
            int left = 0;
            int right = V.size() - 1;

            while(left < right){
                int mid = (left + right) / 2;
                if(nums[i] <= V[mid]) right = mid;
                else left = mid + 1;
            }
            V[left] = nums[i];
        }
    }

    cout << V.size() << endl;
}