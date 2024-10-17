#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<char,char>> tree;

void preorder(char cur){
    if(cur == '.') return;
    cout << cur;
    preorder(tree[cur].first);
    preorder(tree[cur].second);
}

void inorder(char cur){
    if(cur == '.') return;
    inorder(tree[cur].first);
    cout << cur;
    inorder(tree[cur].second);
}

void postorder(char cur){
    if(cur == '.') return;
    postorder(tree[cur].first);
    postorder(tree[cur].second);
    cout << cur;
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    // 전위 순회 (나 -> 왼쪽 -> 오른쪽)
    // 중위 순회 (왼쪽 -> 나 -> 오른쪽)
    // 후위 순회 (왼쪽 -> 오른쪽 -> 나)
    int nodeCnt;
    cin >> nodeCnt;
    
    for(int i = 0; i < nodeCnt; i++){
        char me, left, right;
        cin >> me >> left >> right;
        tree[me] = {left,right};
    }

    preorder('A'); cout << "\n";
    inorder('A'); cout << "\n";
    postorder('A'); cout << "\n";
}