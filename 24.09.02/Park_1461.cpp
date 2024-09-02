#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N : 책의 갯수
// M : 한번에 들 수 있는 책의 개수
// -1 3 (4 5) (6 11) 
/*
-1   // 1 + 1
3 // 3 + 3
4 5 // 5 + 5
6 11 // 11
10 2 6 11 =? 29

12 8 2 11
------------
// (-39 -37) (-29 -28) -6 (2 11)
// (-45 -26 -18) (-9 -4) (22 40 50)
// (-1) (3)(4 5)(6 11)

*/

bool cmp(int a, int b){
    return abs(a) > abs(b);
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int bookCnt, limit;
    cin >> bookCnt >> limit;

    vector<int> minusBookPos;
    vector<int> plusBookPos;
    vector<int> res;

    for(int k = 0; k < bookCnt; k++){
        int pos;
        cin >> pos;
        if(pos > 0) plusBookPos.push_back(pos);
        else minusBookPos.push_back(pos);
    }
    sort(plusBookPos.rbegin(), plusBookPos.rend());
    sort(minusBookPos.begin(), minusBookPos.end());

    int idx = 0;
    while(idx < plusBookPos.size()){
        res.push_back(plusBookPos[idx]);
        idx += limit;
    }

    idx = 0;
    while(idx < minusBookPos.size()){
        res.push_back(minusBookPos[idx]);
        idx += limit;
    }

    sort(res.begin(), res.end(), cmp);

    int answer = abs(res[0]);
    for(int k = 1; k < res.size(); k++){
        answer += abs(res[k])*2;
    }

    cout << answer;
}