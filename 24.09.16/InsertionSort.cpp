#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {8,5,6,2,4};

void InsertionSort(){
    int i,j,key;
    for(i = 0; i < arr.size(); i++){
        key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

        // 현재 정렬된 배열은 i-1까지 이므로 i-1 번째부터 역순으로 조사한다.
        // j값은 음수가 아니어야하고
        // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for(j = i-1; j>=0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;

        for(auto iter : arr){
            cout << iter << " ";
        }
        cout << endl;
    }
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    InsertionSort();
}