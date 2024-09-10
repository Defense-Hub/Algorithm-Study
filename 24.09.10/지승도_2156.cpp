#include<iostream>

// https://www.acmicpc.net/problem/2156

using namespace std;

int grapes[10001] = {0};
int dp[10001] = {0};

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> grapes[i];
    }

    dp[1] = grapes[1];
    if (n > 1) {
        dp[2] = grapes[1] + grapes[2];
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i-1], dp[i-2] + grapes[i], dp[i-3] + grapes[i-1] + grapes[i]});
    }

    cout << dp[n] << endl;

    return 0;
}
