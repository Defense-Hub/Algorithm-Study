#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
1. 전부 조합, 메뉴 갯수 단위로 
20개의 주문 10개 메뉴 course 2~10
10C2 + 10C3 + 10C4 + ~~~ 10C10 = 45 + 120 + 210 120 45 1

조합을 구하면서 course별로 가장 많이 주문된 요리 -> answer에 추가
*/
vector<string> orderData;
vector<int> courseData;
unordered_map<string,int> mp;

void dfs(int idx, vector<char> tmp, int targetCnt, int orderIdx){
    if(tmp.size() == targetCnt){
        // map에 갯수 데이터 저장
        string res = "";
        for(char a : tmp)
            res += a;
        // 결과값 정렬
        sort(res.begin(), res.end());
        mp[res]++;
        return;
    }
    
    for(int i = idx + 1; i < orderData[orderIdx].size(); i++){
        tmp.push_back(orderData[orderIdx][i]);
        dfs(i, tmp, targetCnt, orderIdx);
        tmp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    orderData = orders;
    courseData = course;
    
    // 손님별 메뉴 주문 경우의 수 계산
    for(int k = 0; k < orders.size(); k++){
        // 뽑을 메뉴의 수
        for(int j = 0; j < course.size(); j++){
            vector<char> tmp;
            // 조합 생성
            for(int i = 0; i < orders[k].size(); i++){
                tmp.push_back(orders[k][i]);
                dfs(i, tmp, course[j], k);
                tmp.pop_back();
            }
        }
    }
    vector<vector<pair<int,string>>> res(11);
    for(auto iter : mp){
        if(iter.second < 2) continue;
        res[iter.first.length()].push_back({iter.second, iter.first});
    }
    
    for(int idx = 0; idx < course.size(); idx++){
        int cIdx = course[idx];
        sort(res[cIdx].rbegin(), res[cIdx].rend());
        
        int maxN = res[cIdx][0].first;
        for(auto iter : res[course[idx]]){
            if(iter.first == maxN) answer.push_back(iter.second);
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}