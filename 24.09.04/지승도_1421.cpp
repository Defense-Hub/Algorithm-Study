#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/1421

using namespace std;

int n, c, w;

bool cmp(int a, int b)
{
	return a > b;
}
int main() {
	cin >> n >> c >> w;

	if (n == 0) {
		cout << 0;
		return 0 ;
	}

	vector <int> trees(n);
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end() ,cmp);

	long long maxPrice = 0;
	for (int i = 1; i <= trees[0]; i++) {
		long long totalPrice = 0;
		for (int j = 0; j < n; j++) {
			if (trees[j] < i)
				continue;

			int treeNum = trees[j] / i;

			int price;
			if (trees[j] % i == 0)
				price = (treeNum * w * i) - ((treeNum - 1) * c);
			else
				price = (treeNum * w * i) - (treeNum  * c);

			if(price > 0)
				totalPrice += price;
		}

		if (maxPrice < totalPrice)
			maxPrice = totalPrice;
	}
	
	cout << maxPrice;

	return 0;
}
