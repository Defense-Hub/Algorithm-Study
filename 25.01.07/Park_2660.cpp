#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
// 17:30 ~

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> fw(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <=n; i++){
        fw[i][i] = 0;
    }

    while(true){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        fw[a][b] = 1;
        fw[b][a] = 1;
    }
    

    for(int from = 1; from <= n; from++){
        for(int to = 1; to <= n; to++){
            for(int adj = 1; adj <= n; adj++){
                fw[from][to] = min(fw[from][to], fw[from][adj] + fw[adj][to]);
            }
        }
    }
    vector<int> score(n+1);
    int member = -1;
    for(int i = 1; i <= n; i++){
        int m = 0;
        for(int j = 1; j <= n; j++){
            m = max(m, fw[i][j]);
        }
        score[i] = m;
        if(member > m || member == -1) member = m;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(score[i] == member) cnt++;
    }
    cout << member << " " << cnt << endl;
    for(int i = 1; i <= n; i++){
        if(score[i] == member) cout << i << " ";
    }
}