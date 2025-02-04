#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 2147483647
using namespace std;
// RES : https://blogshine.tistory.com/334
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    // 투포인터
    // 이동 조건
    // 왼쪽을 옮겼을 때, 오른쪽을 옮겼을 때
    // |특성값|이 작은쪽으로 옮기기
    int left = 0;
    int right = n-1;
    int resL, resR;
    int minDiff = INF;
    while(left < right){
        // diff값이 양수라면 right - 1
        // diff값이 음수라면 left + 1
        int curDiff = v[left] + v[right];
        if(abs(curDiff) < minDiff){
            minDiff = abs(curDiff);
            resL = v[left];
            resR = v[right];
        }

        if(curDiff < 0) left++;
        else right--;
    }

    cout << resL << " " << resR;
}