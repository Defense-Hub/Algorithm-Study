#include <iostream>
#include <vector>
using namespace std;
// 16 40 ~ 17 00
int n, m;
vector<int> parent;
int findParent(int x){
    if(parent[x] == x) return x;
    else return findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool matchParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return true;
    else return false;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> n >> m;
    parent.resize(n+1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    // board로 연결 여부 체크
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            int connect;
            cin >> connect;
            if(connect == 1)
                unionParent(y,x);
        }
    }

    int st;
    cin >> st;
    for(int a = 1; a < m; a++){
        int cmp;
        cin >> cmp;
        if(!matchParent(st, cmp)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}