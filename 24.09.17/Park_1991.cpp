#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char,pair<char,char>> mp;

void preorder(char cur){
    // mid
    cout << cur;
    if(mp[cur].first == '.' && mp[cur].second == '.') return;
    // left
    if(mp[cur].first != '.')
        preorder(mp[cur].first);
    // right
    if(mp[cur].second != '.')
        preorder(mp[cur].second);
}

void inorder(char cur){
    // left
    if(mp[cur].first != '.')
        inorder(mp[cur].first);
    // mid
    cout << cur;
    if(mp[cur].first == '.' && mp[cur].second == '.') return;
    
    // right
    if(mp[cur].second != '.')
        inorder(mp[cur].second);
}

void postorder(char cur){
    // left
    if(mp[cur].first != '.')
        postorder(mp[cur].first);
    // right
    if(mp[cur].second != '.')
        postorder(mp[cur].second);
    // mid
    cout << cur;
    if(mp[cur].first == '.' && mp[cur].second == '.') return;
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int nCnt;
    cin >> nCnt;
    // 전위 순회 root -> left -> right
    // 중위 순회 left -> root -> right
    // 후위 순회 left -> right -> root
    for(int i = 0; i < nCnt; i++){
        char root, left, right;
        cin >> root >> left >> right;
        mp[root] = {left, right};
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A');
}