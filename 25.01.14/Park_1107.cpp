#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 1000000
using namespace std;

vector<bool> remote(10, true); 
bool CanGo(int ch){
    string strCh = to_string(ch);
    for(int i = 0; i < strCh.length(); i++){
        if(!remote[strCh[i] - '0']) return false;
    }
    return true;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int target, wCnt;
    cin >> target >> wCnt;
    
    for(int i = 0; i < wCnt; i++){
        int n;
        cin >> n;
        remote[n] = false;
    }
    // 그냥 +- 를 통해 업데이트 하는 경우
    int cnt = abs(target - 100);
    
    // 고장나지 않은 버튼을 활용해 가장 근사한 채널로 이동
    for(int i = 0; i <= MAX; i++){
        if(CanGo(i)){
            int tcnt = abs(target - i) + to_string(i).length();
            cnt = min(cnt, tcnt);
        }
    }

    cout << cnt;
}