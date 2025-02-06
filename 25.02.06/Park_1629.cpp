#include <iostream>
#include <vector>
using namespace std;
long long a,b,c,k;
//REF : https://velog.io/@junttang/BOJ-1629-%EA%B3%B1%EC%85%88-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C
long long power(long long b){
    if(b == 0) return 1;
    if(b == 1) return a%c;
    k = power(b/2)%c;
    
    // a^b = a^(b/2) * a^(b/2) - b가 짝수
    if(b%2 == 0) return k * k % c;
    else return k * k % c * a % c;
}

int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    cin >> a >> b >> c;
    //a를 b번 곱하고 c로 나눈 나머지
    // (a * a * a * a) % c
    // 16 % 6 = 4
    
    // a^b = a^(b/2) * a^(b/2 + 1) - b가 홀수
    cout << power(b);

}