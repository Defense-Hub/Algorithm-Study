#include <iostream>
#include <deque>

using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string op, arr;
        int num;
        deque<int> dq;
        bool isReverse = false;
        bool isError = false;
        // R x : D-> pop front, Res : pop front
        // R o : D-> pop back, Res : pop back
        cin >> op >> num >> arr;
        string StrNum = "";
        for(int j = 0; j < arr.length(); j++){
            if(arr[j] == '[' || arr[j] == ']') continue;
            if(arr[j] == ',') {
                dq.push_back(stoi(StrNum));
                StrNum = "";    
            }
            else StrNum += arr[j];
        }
        if(StrNum.length() > 0)
            dq.push_back(stoi(StrNum));
        for(int j = 0; j < op.length(); j++){
            if(op[j] == 'R') isReverse = !isReverse;
            else{
                if(dq.empty()){
                    isError = true;
                    break;
                }

                if(isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if(isError){
            cout << "error\n";
            continue;
        }

        cout << "[";
        while(!dq.empty()){
            if(isReverse){
                int cur = dq.back();
                dq.pop_back();
                if(dq.empty()) cout << cur;
                else cout << cur << ",";
            }
            else{
                int cur = dq.front();
                dq.pop_front();
                if(dq.empty()) cout << cur;
                else cout << cur << ",";
            }
        }
        cout << "]\n";
    }
}