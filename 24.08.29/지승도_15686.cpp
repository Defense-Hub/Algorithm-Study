#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/15686

using namespace std;

vector <pair<int, int>> chicken, house;

int main() {
	int n, m, result = 0;

	cin >> n >> m;

	int sel;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> sel;
			if (sel == 1)
				house.push_back({ i,j });
			else if (sel == 2)
				chicken.push_back({ i,j });
		}
	}

	vector <bool> combination(chicken.size(), true);
	for (int i = 0; i < chicken.size() - m; i++) {
		combination[i] = false;
	}

	// permutation을 이용한 조합 사용
	do {
		vector <int> vec(house.size(), 0);

		for (int i = 0; i < combination.size(); i++) {
			if (combination[i]) {
				for (int j = 0; j < house.size(); j++) {
					int distanceY = abs(house[j].first - chicken[i].first);
					int distanceX = abs(house[j].second - chicken[i].second);

					if (vec[j] == 0 || vec[j] > distanceY + distanceX) {
						vec[j] = distanceY + distanceX;
					}
				}

			}
		}
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			sum += vec[i];
		}

		if (result == 0 || result > sum) {
			result = sum;
		}

	} while (next_permutation(combination.begin(), combination.end()));

	cout << result;

	return 0;
}
