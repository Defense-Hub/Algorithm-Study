#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 1; //등수
    int s0=scores[0][0],s1=scores[0][1]; //완호의 점수
    int hap=s0+s1; //완호의 점수 합
    vector<vector<int>>newScores;
    sort (scores.begin(),scores.end(),[](vector<int> a, vector<int>b){//정렬
        if (a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]>b[0];
    });
    int prevMax=0,nowMax=scores[0][1];
    newScores.push_back(scores[0]);
    for (int i=1; i<scores.size(); i++) //비교 후 인센티브를 받으면 newScores에 push
    {
        if (scores[i][0]<scores[i-1][0])// 근무 평가 점수가 바뀌면(앞 사람이 더 높으면)
        {                              // 동료평가 점수(prevMax값)을 nowMax로 갱신한다.
            prevMax=nowMax;
        }
        if (scores[i][1]>=prevMax)
        {
            newScores.push_back(scores[i]);
        }
        nowMax=max(nowMax,scores[i][1]); //항상 최대값으로 갱신한다
    }
    
    for (int i=0; i<newScores.size(); i++)
    {
        if (newScores[i][0]>s0 && newScores[i][1]>s1) //완호보다 두 점수가 높은 직원이 있으면 -1
        {
            return -1;
        }      
        if(hap<newScores[i][0]+newScores[i][1]) //완호보다 두 점수의 합이 높으면 등수가 밀린다.
        {
            answer+=1;
        }  
    }    
    
    return answer;
}