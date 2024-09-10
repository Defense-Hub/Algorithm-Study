#include <string>
#include <vector>
#include <iostream>
#include<map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> countVec;
    
    for(int i = 0; i < course.size(); i++){
        int cLength = course[i];
        map <string, int> combMap;
        
        // 요리 갯수 별 각 주문들의 조합을 구함
        for(int j = 0; j < orders.size(); j ++){
            int oLength = orders[j].length();
            if(oLength < cLength)
                continue;
            
            vector<bool> check(oLength,true);
            for(int k = 0; k < oLength - cLength; k ++){
                check[k] = false;
            } 
            
            do{
                string str = "";
                for(int k = 0; k < oLength; k++){
                    if(check[k])
                        str += orders[j][k];
                }
                
                sort(str.begin(), str.end());
                combMap[str]++;          
               
            }while(next_permutation(check.begin(), check.end()));
        }
        
        // 조합 별 최댓값 구하기
        int maxCount = 0;
        for(auto &comb : combMap ){
            if(comb.second > 1){
                maxCount = max(maxCount, comb.second);
            }
        }
        
        for(auto &comb : combMap ){
            if(comb.second == maxCount && comb.second > 1){
                answer.push_back(comb.first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
