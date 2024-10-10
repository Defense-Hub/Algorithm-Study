#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer = 0;
bool isFind = false;
string target;
string alpha = "AEIOU";
void dfs(string cur){
    if(cur.length() > 5 || isFind) return;
    if(!isFind) answer++;
    if(cur.compare(target) == 0) isFind = true;
    for(int i = 0; i < 5; i++){
        dfs(cur + alpha[i]);
    }
}
    
    
int solution(string word) {
    target = word;
    for(int i = 0; i < 5; i++){
        string cur = "";
        cur += alpha[i];
        dfs(cur);
    }
    return answer;
}