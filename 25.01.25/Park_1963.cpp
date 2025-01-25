#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;
// REF : https://yabmoons.tistory.com/65
vector<bool> Era(MAX, true);
vector<bool> isVisit(MAX, false);
void InitEra(){
    for(int i = 2; i < MAX; i++){
        for(int j = 2; i*j < MAX; j++){
            Era[i*j] = false;
        }
    }
}

void bfs(int from, int to){
    isVisit.assign(MAX, false);
    // 숫자, depth
    queue<pair<int,int>> q;
    q.push({from, 0});
    isVisit[from] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == to){
            cout << cnt << "\n";
            return;
        }

        // 자릿수
        for(int k = 0; k < 4; k++){
            for(int j = 0; j < 10; j++){
                string s = to_string(cur);
                s[k] = j + '0';
                int next = stoi(s);
                if(!Era[next]) continue;
                if(isVisit[next]) continue;
                if(next >= 10000 || next < 1000) continue;
                isVisit[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }
    cout << "Impossible\n";
}


int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);     
    int tc;
    cin >> tc;
    InitEra();
    for(int i = 0; i < tc; i++){
        int from, to;
        cin >> from >> to;
        // 숫자, depth
        bfs(from, to);
    }
}