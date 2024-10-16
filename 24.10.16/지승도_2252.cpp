#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int degree[32001];
vector <int> vec[32001];

void Topological_Sort() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();

		for (int i = 0; i < vec[front].size(); i++) {
			degree[vec[front][i]]--;

			if (degree[vec[front][i]] == 0) {
				q.push(vec[front][i]);
			}
		}
	}
}
int main() {
	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		degree[y]++;

		vec[x].push_back(y);
	}

	Topological_Sort();

	return 0;
}
