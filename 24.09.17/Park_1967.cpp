#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> tree;
vector<bool> isVisit;
int edNode = 0;
int maxD, nCnt;

void dfs(int curNode, int dst){
    isVisit[curNode] = true;
    if(dst > maxD){
        edNode = curNode;
        maxD = dst;
    }
    for(int k = 0; k < tree[curNode].size(); k++){
        if(isVisit[tree[curNode][k].first]) continue;
        dfs(tree[curNode][k].first, dst + tree[curNode][k].second);
    }
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    // 루트에서 가장 먼 node를 먼저 구하고
    // 해당 node로부터 가장 먼 node를 구한다. = 지름

    cin >> nCnt;
    tree.resize(nCnt + 1);
    
    for(int k = 0; k < nCnt - 1; k++){
        int st, dt, dst;
        cin >> st >> dt >> dst;

        tree[st].push_back({dt, dst});
        tree[dt].push_back({st, dst});
    }

    isVisit.assign(nCnt + 1, false);
    maxD = -1;
    dfs(1,0);

    isVisit.assign(nCnt + 1, false);
    maxD = -1;
    dfs(edNode, 0);
    cout << maxD;
}
// resize, assign의 차이
// resize의 경우 크기가 더 커질 경우 기존 원소의 값은 그대로 두고, 추가되는 원소들을 초기화
// assign은 기존 원소를 덮어쓰면서 초기화.