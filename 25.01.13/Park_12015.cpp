#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 5 50 ~
// 주요 아이디어 : res vector에 부분 수열의 단위로 숫자 박아넣기
// 10 20 30 50
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    vector<int> board(n);
    vector<int> res;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }

    
    for(int i = 0; i < n; i++){
        if(res.size() == 0 || res.back() < board[i]) res.push_back(board[i]);
        else{
            int left = 0;
            int right = res.size() - 1;
            while(left < right){
                int mid = (left + right) / 2;
                if(board[i] <= res[mid]) right = mid;
                else left = mid + 1;
            }
            res[left] = board[i];
        }
    }

    cout << res.size();
}