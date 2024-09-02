#include<iostream>
#include<vector>
#include<algorithm>

// https://www.acmicpc.net/problem/1461

using namespace std;


vector <int> plusVec;
vector <int> minusVec;
int n, m;

bool cmp(int a, int b) {
	return a > b;
}

int Search(vector<int> vec, bool isTopValue) {
	 int idx = 0, sum = 0;

	 if (vec.size() == 0)
		 return 0;

	if (isTopValue) { // 가장 큰 값이 있을 때,
	
		sum += vec[idx];
		idx += m;

		if (vec.size() <= idx)
			return sum;
	}

	while (true) { // 왕복 값 구하기
		sum += vec[idx] * 2;
		idx += m;

		if(vec.size() <= idx)
			return sum;
	}
}

int main() {

	cin >> n >> m;

	int input, maxValue = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input > 0)
			plusVec.push_back(input);
		else
			minusVec.push_back(input * -1);

		if (abs(maxValue) < abs(input))
			maxValue = input;
	}
	

	// 내림차순 정렬
	sort(plusVec.begin(), plusVec.end(), cmp);
	sort(minusVec.begin(), minusVec.end(), cmp);

	bool isPlusHigh = maxValue > 0;
	cout << Search(plusVec, isPlusHigh) + Search(minusVec, !isPlusHigh);

	return 0;
}
