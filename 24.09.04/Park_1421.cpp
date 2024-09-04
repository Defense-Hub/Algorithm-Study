#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int treeCnt, cutCost, price;
    cin >> treeCnt >> cutCost >> price;
    vector<int> trees(treeCnt);
    int maxNum = 0;
    for(int k = 0; k < treeCnt; k++){ // 50
        cin >> trees[k];
        maxNum = max(maxNum, trees[k]);
    }

    long long answer = -1;
    for(int length = 1; length <= maxNum; length++){ // 10000
        long long res = 0;
        // tree 자르기
        for(int k = 0; k < treeCnt; k++){
            if(length == trees[k])
                res += length * price;
            else if(length < trees[k]){
                int cnt = trees[k] % length == 0 ? -1 : 0;
                if(((trees[k] / length) + cnt) * cutCost < ((length * price) * (trees[k]/length))){
                    res -= ((trees[k] / length) + cnt) * cutCost;
                    res += (length * price) * (trees[k]/length);
                }
            }
        }
        answer = max(answer, res);
    }

    cout << answer;
}