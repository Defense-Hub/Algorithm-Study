// 모든 정렬 함수로 생성해서 저장#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> arr = {21,10,12,20,25,13,15,22};

void Swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

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

void SelectionSort(){
    for(int k = 0; k < arr.size() - 1; k++){
        int minN = arr[k];
        int idx = k;
        bool isChange = false;
        for(int j = k + 1; j < arr.size(); j++){
            if(arr[j] < minN){
                isChange = true;
                minN = arr[j];
                idx = j;
            }
        }

        if(isChange){
            arr[idx] = arr[k];
            arr[k] = minN;
            
            for(auto num : arr)
                cout << num << " ";

            cout << endl;
        }
    }
}

void Merge(int left, int mid, int right){
    int lIdx, rIdx, t;
    vector<int> tmp(right - left + 1);
    lIdx = left;
    rIdx = mid + 1;
    t = 0;

    // divide된 친구들 비교 및 tmp에 정렬 배치
    while(lIdx <= mid && rIdx <= right){
        if(arr[lIdx] <= arr[rIdx])
            tmp[t++] = arr[lIdx++];
        else
            tmp[t++] = arr[rIdx++];
    }

    // 남은 값들 붙혀주기
    while(lIdx <= mid){
        tmp[t++] = arr[lIdx++];
    }
    while(rIdx <= right){
        tmp[t++] = arr[rIdx++];
    }

    t = 0;
    for(int k = left; k <= right; k++){
        arr[k] = tmp[t++];
        cout << arr[k] << " ";
    }
    cout << endl;

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void MergeSort(int left, int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    MergeSort(left, mid);
    MergeSort(mid+1, right);
    Merge(left, mid, right);
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    MergeSort(0, arr.size() - 1);
}