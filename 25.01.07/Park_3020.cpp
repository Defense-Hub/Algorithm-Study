#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001
#define INF 1e13+7
using namespace std;
// 20:20 ~ 21 : 00
// REF : https://hyeo-noo.tistory.com/310

int top[MAX];
int bottom[MAX];

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, H;
    cin >> n >> H;
    // 짝수는 아래서, 홀수는 위에서
    for(int i = 0; i < n; i++){ // 최대 20만, 바로 장애물 구간별 data에 넣어야함.
        int h;
        cin >> h;
        if(i%2 == 0) bottom[h]++;
        else top[H-h+1]++;
    }
    // 끝 구간 기준으로 계산
    for(int i = 1; i <= H; i++){
        top[i] += top[i-1];
        bottom[H-i] += bottom[H-i+1];
    }
    
    long long ans = INF;
    int cnt = 0;
    for(int i = 1; i <= H; i++){
        if(top[i] + bottom[i] < ans){
            cnt = 1;
            ans = top[i] + bottom[i];
        }
        else if(top[i] + bottom[i] == ans)
            cnt++;
    }

    cout << ans << " " << cnt;
}