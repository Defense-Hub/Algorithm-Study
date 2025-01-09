#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// 16:40 ~ 17 00 
// Trie로 추가 풀이 필요

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int n;
        cin >> n;
        vector<string> nums(n);
        for(int j = 0; j < n; j++){
            cin >> nums[j];            
        }
        sort(nums.begin(), nums.end());
        unordered_set<string> hash;
        bool isPossible = true;
        // 10000C2 10000*9999/2 = 50000 * 50 * 10 =25000000
        // 모든 경우의 수 비교 가능할 것 같다.
        for(int a = 0; a < n; a++){
            string cmp = "";
            for(int b = 0; b < nums[a].length() - 1; b++){
                cmp += nums[a][b];
                if(hash.find(cmp) != hash.end()){
                    isPossible = false;
                    break;
                }
            }

            if(!isPossible) break;
            hash.insert(nums[a]);
        }

        if(isPossible) cout << "YES\n";
        else cout << "NO\n";
    }
}