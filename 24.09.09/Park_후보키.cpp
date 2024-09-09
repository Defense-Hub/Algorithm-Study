#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    유일성 체크 
    1. attribute 모두 뽑기 8! = 1 2 3 4 5 6 7 8 /40320
    2. 해당 인덱스로 중복이 되는지 안되는지 체크, map 활용?
    3. 
    최소성 체크 // a b 로 유일성이 체크 되면 거기서 return
*/
int answer = 0;
int row, col;
vector<int> idxs;
vector<vector<string>> rel;
vector<vector<int>> candidate;

bool CheckUnique(){
    map<string,int> mp;
    for(int y = 0; y < row; y++){
        string chk = "";
        
        for(int i : idxs){
            chk += rel[y][i];
        }
        if(!mp[chk]) mp[chk] = 1;
        else return false;
    }
    return true;
}

bool CheckMin(){
    if(idxs.size() == 1) return true;
    
    for(int k = 0; k < candidate.size(); k++){
        bool flag = false;
        
        for(int i = 0; i < candidate[k].size(); i++){
            int key = candidate[k][i];
            if(find(idxs.begin(), idxs.end(), key) == idxs.end()){
                flag = true;
                break;
            }
        }
        if(!flag) return false;
    }
    return true;
}

bool Check(){
    if(CheckUnique() && CheckMin()) 
    {
        candidate.push_back(idxs);
        return true;
    }
    return false;
}

void dfs(int i, int cnt, int targetCnt){
    // 유일성 체크
    if(cnt == targetCnt){
        if(Check()) answer++;
        return;
    }
    
    
    for(int k = i; k < col; k++){
        idxs.push_back(k);
        dfs(k, cnt+1, targetCnt);
        idxs.pop_back();
    }
}

int solution(vector<vector<string>> relation) {    
    row = relation.size();
    col = relation[0].size();
    rel = relation;
    for(int k = 1; k <= col; k++){
        dfs(0,0,k);
    }
    
    return answer;
}