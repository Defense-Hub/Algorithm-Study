#include <iostream>
#include <vector>
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n, cnt;
    cin >> n >> cnt;
    vector<int> nums(n + 1);
    
    for(int k = 0; k < n; k++){
        cin >> nums[k];
    }

    int iCnt = 0;
    for(int i = 1; i < n; i++){
        int loc;
        int newItem = nums[i];

        for(loc = i - 1; loc >= 0 && newItem < nums[loc]; loc--){
            nums[loc+1] = nums[loc];
            iCnt++;
            if(iCnt == cnt){
                cout << nums[loc + 1];
                return 0;
            }
        }

        if(loc + 1 != i){
            nums[loc + 1] = newItem;
            iCnt++;
            if(iCnt == cnt){
                cout << nums[loc + 1];
                return 0;    
            }
        }
    }

    cout << -1;
}