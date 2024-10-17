#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
int root;

void curVertex(int idx){
    if(tree[idx].size() > 1) cout << "yes\n";
    else{
        cout << "no\n";
    }
}

void bridge(int idx){
    cout << "yes\n";
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int nodeCnt;
    cin >> nodeCnt;
    tree.resize(nodeCnt + 1);


    for(int i = 0; i < nodeCnt - 1; i++){
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }

    int qCnt;
    cin >> qCnt;
    for(int i = 0; i < qCnt; i++){
        int qType, idx;
        cin >> qType >> idx;

        switch (qType)
        {
            case 1:
            curVertex(idx);
            break;
        
            case 2:
            bridge(idx);
            break;
        }
    }
}