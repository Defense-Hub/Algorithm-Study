#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int cnt;
	cin >> cnt;
	vector<int> answer(cnt, 0);
	for (int k = 1; k <= cnt; k++) {
		int posCnt;
		cin >> posCnt;
		
		int idxCnt = 0;
		for (int j = 0; j < cnt; j++) {
			if (answer[j] == 0) 
			{
				if (idxCnt == posCnt)
				{
					answer[j] = k;
					break;
				}
				else {
					idxCnt++;
				}
			}
		}
	}

	for (auto iter : answer) {
		cout << iter << " ";
	}
}