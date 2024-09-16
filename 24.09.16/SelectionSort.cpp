#include <iostream>
#include <vector>
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, cnt;
    cin >> n >> cnt;
    vector<int> nums(n);
    
    for(int k = 0; k < n; k++){
        cin >> nums[k];
    }
    cout << endl;
    for(int k = 0; k < n-1; k++){
        int minN = nums[k];
        int idx = k;
        bool isChange = false;
        for(int j = k + 1; j < n; j++){
            if(nums[j] < minN){
                isChange = true;
                minN = nums[j];
                idx = j;
            }
        }

        if(isChange){
            nums[idx] = nums[k];
            nums[k] = minN;
            
            for(auto num : nums)
                cout << num << " ";

            cout << endl;
        }
    }
}