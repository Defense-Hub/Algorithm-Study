#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int k = 0; k < n; k++){
        cin >> a[k];
    }

    vector<int> b(n);
    for(int k = 0; k < n; k++){
        cin >> b[k];
    }

    // a 내림차순 정렬
    // b 오름차순 정렬

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int answer = 0;
    for(int k = 0; k < n; k++){
        answer += a[k] * b[k];
    }

    cout << answer;
}