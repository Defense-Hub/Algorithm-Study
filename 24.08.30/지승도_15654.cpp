#include<iostream>
#include <vector>
#include <algorithm>

// https://www.acmicpc.net/problem/15654

using namespace std;

int main() {
	int n, m, sel;

	cin >> n >> m;

	vector <int> vec (n);
	vector <bool> combination (n, true);
	vector<vector<int>> answer;

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < n - m; i++) {
		combination[i] = false;
	}

	do {
		vector <int> combinationValues;
		for (int i = 0; i < n; i++) {
			if (combination[i]) {
				combinationValues.push_back(vec[i]);
			}
		}

		sort(combinationValues.begin(), combinationValues.end());

		do {
			vector <int> result (m);
			for (int i = 0; i < m; i++) {
				result[i] = combinationValues[i];
			}
			answer.push_back(result);
		} while (next_permutation(combinationValues.begin(), combinationValues.end()));

	} while (next_permutation(combination.begin(), combination.end()));

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
