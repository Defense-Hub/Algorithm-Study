#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int cnt = 0;
void find(int y, int x, int size){
    if(y == r && x == c){
        cout << cnt;
        return;
    }
    // 현재 사분면 안에 y,x 가 존재 한다면?
    if(r < y + size && r >= y && c < x + size && c >= x){
        // 1사분면
        find(y, x, size / 2);
        // 2사분면
        find(y, x + size/2, size/2);
        // 3사분면
        find(y + size/2, x, size/2);
        // 4사분면
        find(y + size/2, x + size/2, size/2);
    }
    else
        cnt += size*size;
}
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> n >> r >> c;
    find(0,0,(1 << n));
}