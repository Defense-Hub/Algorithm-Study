#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}


void dfs(int num, int depth){
    if(depth == n && isPrime(num)){
        cout << num << endl;
        return;
    }
    if(isPrime(num)){
        for(int i = 1; i < 10; i += 2){
            dfs(num * 10 + i, depth + 1);
        }
    }
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);        
    cin >> n;
    
    // dfs를 이용하여 체크
    // 2, 3, 5, 7
    dfs(2,1); dfs(3,1); dfs(5,1); dfs(7,1);
}