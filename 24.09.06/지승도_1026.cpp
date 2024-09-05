#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/1026
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;

	return 0;
}
