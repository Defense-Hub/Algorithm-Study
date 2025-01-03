#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool canSwitch = false;

void FindWord(string cur, string tar){
    if(cur.length() > tar.length()) return;
    if(cur.compare(tar) == 0){
        canSwitch = true;
        return;
    }
    // 문자열 맨 뒤가 A
    // 문자열 맨 앞이 B 
    // 두가지 경우 모두 재귀
    if(tar.back() == 'A' && tar[0] == 'B'){
        string a = tar;
        a.pop_back();
        FindWord(cur, a);    
        
        string b = tar;
        b.erase(0,1);
        reverse(b.begin(), b.end());
        FindWord(cur, b);
    }
    else if(tar.back() == 'A' && tar[0] != 'B'){
        string a = tar;
        a.pop_back();
        FindWord(cur, a);    
    }
    else if(tar[0] == 'B' && tar.back() != 'A'){
        string b = tar;
        b.erase(0,1);
        reverse(b.begin(), b.end());
        FindWord(cur, b);
    }
    // 문자열 맨뒤가 A, 문자열 맨 앞이 B X => 1번 항목만 재귀
    // 문자열 맨앞이 B, 문자열 맨 뒤가 A X => 2번 항목만 재귀
    // 문자열 뒤에 A를 추가한다.

    // 문자열 뒤에 B를 추가하고 문자열을 뒤집는다.
    // AABB B -> B BBAA
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S, T;
    cin >> S >> T;

    FindWord(S,T);
    if(canSwitch) cout << 1;
    else cout << 0;
    
    // S를 기반으로 DFS를 돌린다. 
    // T보다 길어지면 return, T랑 같아지면 return true;
}