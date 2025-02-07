#include <iostream>
#include <vector>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    // n : 일수, x : window
    int n, x;
    cin >> n >> x;
    // 1. 누적합 계산 
    // 2. window 크기만큼 돌리면서 처음부터 끝까지 순회 presum[x] - presum[0]
    vector<int> presum(n);
    cin >> presum[0];
    for(int i = 1; i < n; i++){
        int cur;
        cin >> cur;
        presum[i] = presum[i-1] + cur;
    }
    int cnt = 1;
    int maxR = presum[x-1];

    for(int i = x; i < n; i++){
        int tmp = presum[i] - presum[i-x];
        if(tmp > maxR){
            cnt = 1;
            maxR = tmp;
        }
        else if(tmp == maxR)
            cnt++;
    }
    if(maxR == 0) cout << "SAD";
    else
        cout << maxR << "\n" << cnt;
}