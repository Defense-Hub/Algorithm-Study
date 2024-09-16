#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {8,5,6,2,4};

void Swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void BubbleSort(){
    // 맨 앞에서 부터 두개 숫자끼리 비교하면서 가장 큰 값을 맨 뒤로 보낸다.
    for(int k = arr.size()-1; k >= 0; k--){
        for(int j = 0; j < k; j++){
            if(arr[j] > arr[j+1]){
                Swap(j, j+1);
            }
        }
        for(auto i : arr){
            cout << i << " ";
        }
        cout << endl;
    }
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    BubbleSort();
}