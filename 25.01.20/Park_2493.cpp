#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// REF : https://bunnnybin.tistory.com/entry/%EB%B0%B1%EC%A4%80-2493-%ED%83%91-C
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    stack<pair<int,int>> st;
    for(int i = 1; i <= n; i++){
        int height;
        cin >> height;
        while(!st.empty()){
            if(height < st.top().second){
                cout << st.top().first << " ";
                break;
            }
            // 나보다 작은 애들은 어차피 내 선에 막혀서 필요없음
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
        }
        st.push({i,height});
    }

    // 왼쪽으로 레이저 발사
    // 나보다 큰 가장 가까운 값 찾기
    // 단순 계산은 O(n^2) 시간 초과 발생
    // stack filo
    // 6 9 5 7 4
    // 
}