#include <string>
#include <vector>
#include <iostream>
using namespace std;
//11:25 시작 ~ 12:00 종료
int maxDiff = -1;
vector<int> answer;
vector<int> apInfo;
void dfs(int n, int idx, vector<int> vec){
    if(idx == 11){
        // 점수 계산
        if(n > 0) vec[10] += n;
        int apScore = 0, ryScore = 0;
        for(int i = 0; i < 11; i++){
            if(vec[i] > apInfo[i])
                ryScore += (10 - i);
            else if(apInfo[i] > 0)
                apScore += (10 - i);
        }
        int curDiff = ryScore - apScore;
        if(curDiff < 0) return;
        if(curDiff > maxDiff){
            maxDiff = curDiff;
            answer = vec;
        }
        else if(curDiff == maxDiff){
            for(int i = 10; i >= 0; i--){
                //아래 점수 부터 올라온다
                // 새로 들어오는 값에서 먼저 더 큰 값이 들어올 경우 교체
                if(vec[i] > answer[i]){
                    answer = vec;
                    break;
                }
                // 기존 값에서 먼저 더 큰 값이 들어올 경우 pass
                else if(answer[i] > vec[i]){
                    break;
                }
            }
        }
        return;
    }
    if(n > apInfo[idx]){
        vec[idx] = apInfo[idx] + 1;
        dfs(n - vec[idx], idx+1, vec);
        vec[idx] = 0;
    }
    dfs(n, idx+1, vec);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> tmp(11,0);
    apInfo = info;
    dfs(n, 0, tmp);
    if(maxDiff <= 0) return {-1};
    return answer;
}