#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 6 15 ~
struct Person{
    int a;
    int b;
    int idx;
};

bool cmp1(Person A, Person B){
    if(A.a == B.a){
        return A.b < B.b;
    }
    return A.a > B.a;
}

bool cmp2(Person A, Person B){
    return A.a + A.b > B.a + B.b;
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<Person> scoreData;
    for(int i = 0; i < scores.size(); i++)
        scoreData.push_back({scores[i][0], scores[i][1], i});
    
    sort(scoreData.begin(), scoreData.end(),cmp1);
    
    int aMax = scoreData[0].a;
    int bMax = scoreData[0].b;
    
    for(int i = 1; i < scoreData.size(); i++){
        // 인센을 받지 못하는 경우
        if(scoreData[i].a < aMax && scoreData[i].b < bMax){
            scoreData[i].a = -1; scoreData[i].b = -1;
        } 
        else{
            // 갱신
            aMax = scoreData[i].a;
            bMax = scoreData[i].b;    
        }
        
    }
    
    sort(scoreData.begin(), scoreData.end(), cmp2);
    /*
    for(auto data : scoreData){
        cout << data.a << " " << data.b << " " << data.idx << endl;
    }
    */
    if(scoreData[0].idx == 0 && scoreData[0].a != -1) return 1;
    
    int total = scoreData[0].a + scoreData[0].b;
    int cnt = 1;        
    for(int i = 1; i < scoreData.size(); i++){
        if(scoreData[i].a + scoreData[i].b == total){
            cnt++;
        }
        else {
            total = scoreData[i].a + scoreData[i].b;
            answer += cnt;
            cnt = 1;
        }
        
        if(scoreData[i].idx == 0){
            if(scoreData[i].a != -1) return answer;
            else return -1;
        } 
    }
    
    //return answer;
}