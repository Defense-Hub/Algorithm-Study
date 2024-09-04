#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/1253
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end() );


	int count = 0;
	for (int i = n - 1; i >= 0; i--) { 
		int left = 0, right = n - 1, target = vec[i];

		while (left < right) {
			if (i == right) {
				right--;
			}
			else if (i == left)
			{
				left++;
			}
			else {
				int num = vec[left] + vec[right];

				if (num == target) {
					count++;
					break;
				}
				else if (num > target) {
					right--;
				}
				else {
					left++;
				}
			}
		}
	}

	cout << count;
	return 0;
}
