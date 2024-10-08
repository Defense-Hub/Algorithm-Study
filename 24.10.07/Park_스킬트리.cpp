#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char,int> mp;
    // skill을 map(char, idx)에 박아놓고
    // skillTree를 순회하면서 dictionary에 해당 문자가 있는지 체크
    // 있다면 idx 비교 idx가 같다면 idx++ 하고 다음 문자로 패스
    // skillTree의 문자열 끝까지 돈다면 answer++;
    for(int i = 0; i < skill.length(); i++){
        mp[skill[i]] = i + 1;
    }
    
    for(string sk : skill_trees){
        bool isAvailable = true;
        int idx = 1;
        for(int i = 0; i < sk.length(); i++){
            if(mp[sk[i]] == 0) continue;
            
            if(mp[sk[i]] == idx){
                idx++;
            }
            else{
                isAvailable = false;
                break;
            }
        }
        if(isAvailable) answer++;
    }
    
    return answer;
}