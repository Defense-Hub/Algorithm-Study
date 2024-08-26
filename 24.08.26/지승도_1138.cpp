#include <iostream>

// https://www.acmicpc.net/problem/1138

using namespace std;

int main() {
    int n, p;
    int arr[11] = { 0, };

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p;

        int count = p;
        for (int j = 0; j < n; j++) {
            if (count == 0 && arr[j] == 0) {
                arr[j] = i + 1;
                break;
            }
            
            if (arr[j] == 0) {
                count--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
