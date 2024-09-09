#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

// 유일성과 최소성을 체크하는 함수
bool isUniqueAndMinimal(vector<int> &comb, vector<vector<string>> &relation, vector<vector<int>> &candidateKeys) {
    // 1. 유일성 체크
    set<string> uniqueSet;
    for (int i = 0; i < relation.size(); i++) {
        string key = "";
        for (int index : comb) {
            key += relation[i][index];
        }
        uniqueSet.insert(key);
    }

    // 유일성 체크 실패 시
    if (uniqueSet.size() != relation.size()) {
        return false;
    }

    // 2. 최소성 체크 (기존 후보키 중 부분집합이 있는지 확인)
    for (vector<int> &key : candidateKeys) {
        bool isSubset = true;
        for (int elem : key) {
            if (find(comb.begin(), comb.end(), elem) == comb.end()) {
                isSubset = false;
                break;
            }
        }
        if (isSubset) {
            return false;
        }
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int tupleSize = relation[0].size();
    vector<vector<int>> candidateKeys;
    
    // 1부터 tupleSize 크기까지의 조합을 모두 시도
    for (int r = 1; r <= tupleSize; r++) {
        vector<int> comb(tupleSize, 0);
        fill(comb.end() - r, comb.end(), 1);  // 조합을 위해 뒷부분을 1로 설정

        do {
            vector<int> currentComb;
            for (int i = 0; i < comb.size(); i++) {
                if (comb[i] == 1) {
                    currentComb.push_back(i);
                }
            }

            if (isUniqueAndMinimal(currentComb, relation, candidateKeys)) {
                candidateKeys.push_back(currentComb);  // 유일성과 최소성을 만족하면 후보키로 저장
            }

        } while (next_permutation(comb.begin(), comb.end()));
    }

    return candidateKeys.size();
}
