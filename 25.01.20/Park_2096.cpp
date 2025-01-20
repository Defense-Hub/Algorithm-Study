#include <iostream>
#include <vector>
#include <algorithm>
// REF : https://yhwan.tistory.com/14
using namespace std;
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    vector<int> maxDP(3);
    vector<int> minDP(3);
    int input0, input1, input2;
    cin >> input0 >> input1 >> input2;
    maxDP[0] = input0; maxDP[1] = input1; maxDP[2] = input2;
    minDP[0] = input0; minDP[1] = input1; minDP[2] = input2;
    int tmp0, tmp2;
    for(int y = 1; y < n; y++){
        cin >> input0 >> input1 >> input2;
        tmp0 = maxDP[0]; tmp2 = maxDP[2];
        maxDP[0] = max(maxDP[0], maxDP[1]) + input0;
        maxDP[2] = max(maxDP[1], maxDP[2]) + input2;
        maxDP[1] = max({tmp0, maxDP[1], tmp2}) + input1;

        tmp0 = minDP[0]; tmp2 = minDP[2];
        minDP[0] = min(minDP[0], minDP[1]) + input0;
        minDP[2] = min(minDP[1], minDP[2]) + input2;
        minDP[1] = min({tmp0, minDP[1], tmp2}) + input1;
    }
    
    cout << max({maxDP[0], maxDP[1], maxDP[2]}) << " " << min({minDP[0], minDP[1], minDP[2]});
}