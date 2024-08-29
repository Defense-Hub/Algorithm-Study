#include<iostream>
#include<vector>

// https://www.acmicpc.net/problem/1158

using namespace std;

int main() {
	int N, K, sel = 0;
	cin >> N >> K;

	K--;

	vector <int> vec;

	for (int i = 1; i <= N; i++)
		vec.push_back(i);

	cout << "<";
	while (true) {
		sel = (sel + K) % vec.size();
		cout << vec[sel];
		vec.erase(vec.begin() + sel);

		if (vec.empty())
			break;
		else
			cout << ", ";
	}
	cout << ">";
	

	return 0;
}
