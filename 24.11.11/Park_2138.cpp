#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;
//[REF] 16:15 ~ 
//ref : https://astrid-dm.tistory.com/429

string origin, target, tmp;
int n, cnt;
int answer = MAX;

void SwitchOn(int idx){
    if(idx > 0) tmp[idx - 1] == '0' ? tmp[idx - 1] = '1' : tmp[idx - 1] = '0';
    tmp[idx] == '0' ? tmp[idx] = '1' : tmp[idx] = '0';
    if(idx < n-1) tmp[idx + 1] == '0' ? tmp[idx + 1] = '1' : tmp[idx + 1] = '0';
}

void test(bool isFirstOn){
    tmp = origin;
    cnt = 0;
    if(isFirstOn){
        tmp[0] == '0' ? tmp[0] = '1' : tmp[0] = '0';
        tmp[1] == '0' ? tmp[1] = '1' : tmp[1] = '0';
        cnt++;
    }

    for(int i = 1; i < n; i++){
        if(tmp[i - 1] != target[i - 1]){
            SwitchOn(i);
            cnt++;
        }
    }
    if(tmp == target) answer = min(answer, cnt);
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> origin >> target;

    
    /*
    [010]
    2진수?
    000 -> 0
    [0 On]
    110
    001


    [0 Off]
    */

    // 처음 스위치를 켜는 경우
    test(true);
    // 처음 스위치를 켜지 않는 경우
    test(false);
    if(answer != MAX) cout << answer;
    else cout << -1;
}