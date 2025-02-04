#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int n, m;
    unordered_map<int,int> mp;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        mp[num]++;
    }
    cin >> m;
    // dictionary에 담아놓고 있는지 체크 O(1)
    for(int i = 0; i < m; i++){
        int target;
        cin >> target;
        if(mp[target] > 0) cout << 1 << " ";
        else cout << 0 << " ";
    }
}