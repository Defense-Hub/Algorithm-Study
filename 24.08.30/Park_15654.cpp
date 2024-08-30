#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> nums;
vector<int> isVisit;
vector<int> res;
int n, m;

void dfs(int idx, vector<int> res){
    if(res.size() == m){
        for(int i : res){
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int k = 0; k < n; k++){
        if(k == idx) continue;
        if(isVisit[k]) continue;
        isVisit[k] = true;
        res.push_back(k);
        dfs(k,res);
        res.pop_back();
        isVisit[k]= false;
    }
}

int main (){
    cin >> n >> m;
    nums.resize(n);
    isVisit.resize(n);

    for(int k = 0; k < n; k++){
        cin >> nums[k];
    }

    sort(nums.begin(), nums.end());

    for(int k = 0; k < n; k++){
        isVisit[k] = true;
        res.push_back(k);
        dfs(k,res);
        res.pop_back();
        isVisit[k] = false;
    }
}