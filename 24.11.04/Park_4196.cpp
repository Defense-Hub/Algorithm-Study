#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 13:45 ~ 18:00
// REF : https://sfer7.tistory.com/21
int domCnt, relCnt;
vector<vector<int>> dom;
vector<int> inDegree;
vector<int> sccNum;
vector<int> rev;
vector<bool> isVisit;
void dfs(int cur, bool opt, int num){
    if(!opt) sccNum[cur] = num;
    isVisit[cur] = true;
    for(int next : dom[cur]){
        if(!isVisit[next]) dfs(next, opt, num);
        else if(!opt && sccNum[cur] != sccNum[next]) inDegree[sccNum[next]]++;
    }

    if(opt) rev.push_back(cur);
}

int main() {
    int testCase;
    int from, to, answer, cnt;
    cin >> testCase;
    for(int i = 0; i < testCase; i++){
        cin >> domCnt >> relCnt;

        // 초기화
        answer = 0;
        cnt = 0;
        sccNum.assign(domCnt + 1, -1);
        isVisit.assign(domCnt + 1, false);
        inDegree.assign(domCnt + 1, 0);
        dom.clear();
        dom.resize(domCnt + 1);
        rev.clear();

        for(int j = 0; j < relCnt; j++){
            cin >> from >> to;
            dom[from].push_back(to);
        }

        for(int j = 1; j <= domCnt; j++){
            if(!isVisit[j])
                dfs(j, true, -1);
        }

        isVisit.assign(domCnt + 1, false);
        for(int j = 0; j < domCnt; j++){
            if(!isVisit[rev[j]]){
                dfs(rev[j], false, cnt++);
            }
        }

        for(int i = 0; i < cnt; i++){
            if(inDegree[i] == 0) answer++;
        }

        cout << answer << endl;
    }
}