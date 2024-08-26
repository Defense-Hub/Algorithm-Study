#include<iostream>

using namespace std;

int main() {
	int n, x, y, count = 0;
	int arr[101][101] = {0,};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;

		for (int i = x; i < 10 + x; i++) {
			for (int j = y; j < 10 + y; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					count++;
				}
			}
		}
	}

	cout <<  count << endl;
	return 0;
}
