#include <iostream>
#include <vector>
using namespace std;
// 16 15 ~ 16 30
int n, m; 
vector<int> parent;
int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 작은 숫자를 부모로 up, 부모의 조건이 추가될 경우 if 에 넣어주면 될 것 같다.
void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) cout << "YES\n";
    else cout << "NO\n";
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int type, a, b;
    cin >> n >> m;
    parent.resize(n + 1);
    for(int k = 1; k <= n; k++){
        parent[k] = k;
    }

    for(int k = 0; k < m; k++){
        cin >> type >> a >> b;
        if(type == 0){
            // a, b 를 묶어주기
            unionParent(a,b);
        }
        else{
            // a, b가 같은 집합에 있는지 확인
            findParent(a,b);
        }
    }
}