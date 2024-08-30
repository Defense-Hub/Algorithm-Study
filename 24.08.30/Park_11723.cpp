#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    unordered_map<string, int> oper;
    bool S[21] = {false,};
    int cnt;
    cin >> cnt;

    oper["add"] = 0;
    oper["remove"] = 1;
    oper["check"] = 2;
    oper["toggle"] = 3;
    oper["all"] = 4;
    oper["empty"] = 5;

    for(int k = 0; k < cnt; k++){
        string op;
        int num = -1;
        cin >> op;
        if(oper[op] < 4){
            cin >> num;
        }
        
        switch (oper[op])
        {
            case 0:
                S[num] = true;
                break;
            case 1:
                S[num] = false;
                break;
            case 2 :
                if(S[num]) cout << 1 << "\n";
                else cout << 0 << "\n";
                break;
            case 3 : 
                S[num] = !S[num];
                break;
            case 4 :
                for(int k = 1; k <= 20; k++){
                    S[k] = true;
                }
                break;
            case 5 :
                for(int k = 1; k <= 20; k++){
                    S[k] = false;
                }
                break;
        }
    }
}