#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

vector<int> nums;
vector<int> visit;
void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i : visit){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i < n; i++){
        visit.push_back(nums[i]);
        dfs(i, cnt+1);
        visit.pop_back();
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    // 2 4 5
    // dfs로 하나씩 묶어서 출력?
    dfs(0, 0);
}