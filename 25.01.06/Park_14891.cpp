#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// 15:50
// 오른쪽 idx = 2, 왼쪽 idx = -2
// Deque로 해결? 
// 정방향 : 뒤에서 하나 빼서 앞으로 넣기, 
// 역방향 : 앞에서 하나 빼서 뒤로 넣기
vector<string> datas(5);
deque<int> dq[5];

void forward(int idx){
    int back = dq[idx].back();
    dq[idx].pop_back();
    dq[idx].push_front(back);
}

void reward(int idx){
    int front = dq[idx].front();
    dq[idx].pop_front();
    dq[idx].push_back(front);
} 

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for(int y = 1; y <= 4; y++){
        cin >> datas[y];
        for(int x = 0; x < 8; x++){
            dq[y].push_back(datas[y][x] - '0');
        }
    }

    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        int oriIdx, dir, idx;
        cin >> oriIdx >> dir;

        idx = oriIdx;
        vector<int> dirs(5, 0);
        dirs[oriIdx] = dir;
        while(idx + 1 <= 4){
            // 극이 다르면 반대방향으로 회전
            if(dq[idx][2] != dq[idx + 1][6])
                dirs[idx + 1] = -dirs[idx];
            else break;
            idx++;
        }

        idx = oriIdx;
        while(idx - 1 >= 1){
            if(dq[idx][6] != dq[idx - 1][2])
                dirs[idx - 1] = -dirs[idx];
            else break;
            idx--;
        }

        for(int k = 1; k <= 4; k++){
            if(dirs[k] == 1) forward(k);
            else if(dirs[k] == -1) reward(k);
        }
    }

    int ans = 0;
    if(dq[1][0]) ans += 1;
    if(dq[2][0]) ans += 2;
    if(dq[3][0]) ans += 4;
    if(dq[4][0]) ans += 8;

    cout << ans;
    // 마지막에 dq를 돌면서 dq.front가 1이면 1,2,4,8점 추가
}