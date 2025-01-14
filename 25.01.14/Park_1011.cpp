#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 처음엔 무조건 1
// 0 1 2
// 1 2 3

// 0 3
// 1
// 1
// 1

// 1 5
// 1
// 2
// 1

// 45 50
// 1
// 2
// 1
// 1
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        long long from, to;
        long long moveCnt, maxN = 0;
        cin >> from >> to;
        while(maxN * maxN <= to - from)
            maxN++;
        maxN--;
        moveCnt = 2*maxN - 1;

        long long remain = to - from - maxN * maxN;
        remain = (long long)ceil((double)remain / (double) maxN);
        moveCnt += remain;

        cout << moveCnt << endl;
    }
}