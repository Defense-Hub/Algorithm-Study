#include<iostream>
#include<vector>

// https://www.acmicpc.net/problem/15988

using namespace std;

long long nums[1000001];
int main() {
	int n, input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		
		cin >> input;

		nums[1] = 1;
		nums[2] = 2;
		nums[3] = 4;
		for (int j = 4; j <= input; j++) {
			nums[j] = (nums[j - 1] + nums[j - 2] + nums[j - 3]) % 1000000009;
		}

		cout << nums[input] % 1000000009 << endl;
	}

	return 0;
}
