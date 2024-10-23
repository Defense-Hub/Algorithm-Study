#include <string>
#include <vector>
#include <iostream>
// 16:38 시작 ~ 17:18 1차 완료 1,3,4,10,11 ~ 완료 17:51
using namespace std;

bool IsPrime(long long num){
    if(num == 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    
    for(long long i = 3; i * i <= num; i+=2){
        if(num % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    // n의 진수 변환 10 -> k
    // 0을 기준으로 잘라내기
    // 변환된 값이 소수라면 answer++
    string num = "";
    vector<long long> numData;
    while(n > 0){
        int tmp = n%k;
        n /= k;
        num += to_string(tmp);
    }
    string tmpNum = "";
    for(int i = num.length()-1; i >= 0; i--){
        if(num[i] == '0'){
            if(tmpNum.length() == 0) continue;
            else{
                long long tmp = stol(tmpNum);
                if(tmp > 1)
                    numData.push_back(tmp);
                tmpNum = "";
            }
        }
        else
            tmpNum += num[i];
    }
    
    if(tmpNum.length() != 0)
        numData.push_back(stol(tmpNum));
    
    
    for(auto iter : numData){
        if(IsPrime(iter)) answer++;
    }
    
    return answer;
}