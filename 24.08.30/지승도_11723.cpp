#include<iostream>
#include<map>
#include<string>

// https://www.acmicpc.net/problem/11723

using namespace std;

map <int, bool> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, sel;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "all" || str == "empty") {

			if (str == "all") {
				for (int j = 1; j <= 20; j++) {
					s[j] = true;
				}
			}
			else if (str == "empty") {
				for (int j = 1; j <= 20; j++) {
					s[j] = false;
				}
			}
		}
		else {
			cin >> sel;

			if (str == "add") {
				s[sel] = true;
			}
			else if (str == "remove") {
				s[sel] = false;
			}
			else if (str == "check") {
				int check = s[sel] == true ? 1 : 0;
				cout << check << "\n";
			}
			else if (str == "toggle") {
				s[sel] = s[sel] == true ? false : true;
			}
		}

	}

	return 0;
}
