#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; 
// 13:20

string first, second, target;
vector<vector<bool>> isVisit;

bool CanMakeWords(int fIdx, int sIdx){
    int tIdx = fIdx + sIdx;
    if(tIdx == target.length()) return true;
    if(isVisit[fIdx][sIdx]) return false;
    isVisit[fIdx][sIdx] = true;
    // 둘 다 같은경우
    if(target[tIdx] == first[fIdx] && target[tIdx] == second[sIdx]){
        return CanMakeWords(fIdx+1, sIdx) || CanMakeWords(fIdx, sIdx+1);
    }
    // 둘 다 같은건 아니면서 A만 같은 경우
    else if(target[tIdx] == first[fIdx]){
        return CanMakeWords(fIdx+1, sIdx);
    }
    // 둘 다 같은건 아니면서 B만 같은 경우
    else if(target[tIdx] == second[sIdx]){
        return CanMakeWords(fIdx, sIdx+1);
    }
    else{
        return false;
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> first >> second >> target;
        // target을 하나씩 순회하면서 idx에 맞는 단어가 있는 경우, 
        // 그 단어를 픽하는 경우 안하는 경우로 나눠 idx를 조절한다.
        // 마지막 idx에 대해서 
        // cttaree . cat tree
        // c / t -> out -> CanMakeWords = false
        // catrtee
        // cat / t // 같은 경우에만 분기점을 나눠서 A가 선택한경우, B가 선택한 경우로 ㄱㄱ
        isVisit.assign(201, vector<bool>(201, false));
        first.push_back('.');
        second.push_back('.');
        if(CanMakeWords(0,0)) cout << "Data set " << i << ": yes" << endl;
        else cout << "Data set " << i << ": no" << endl;
    }
}