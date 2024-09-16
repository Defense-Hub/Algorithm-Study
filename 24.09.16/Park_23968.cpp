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
    int count = 0;
    for(int k = n - 1; k > 0; k--){
        for(int j = 0; j < k; j++){
            if(nums[j] > nums[j+1]){
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                count++;
            }

            if(count == cnt){
                cout << nums[j] << " " << nums[j+1] << endl;
                return 0;
            }
        }
    }

    cout << -1;
}