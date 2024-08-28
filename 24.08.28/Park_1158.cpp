#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> dq;
    vector<int> answer;
    int n,k;
    cin >> n >> k;

    for(int j = 1; j <= n; j++){
        dq.push_back(j);
    }

    int idx = 0;
    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();
        idx++;

        if(idx == k){
            answer.push_back(cur);
            idx = 0;
            continue;
        }

        dq.push_back(cur);
    }

    cout << "<";
    for(int i = 0; i < n-1; i++){
        cout << answer[i] << ", ";
    }
    cout << answer.back() <<">";
}