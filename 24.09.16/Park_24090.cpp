#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, cnt;
int count = 0;
void swap(int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;

    count++;
    if(count == cnt) cout << arr[a] << " " << arr[b];
}

int partition(int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int k = l; k < r; k++){
        if(arr[k] <= pivot)
            swap(++i, k);
    }

    if(i+1 != r) swap(i+1, r);

    return i+1;
}

void QuickSort(int left, int right){
    if(left >= right) return;

    int pIdx = partition(left, right);
    QuickSort(left, pIdx - 1);
    QuickSort(pIdx + 1, right);
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> cnt;
    arr.resize(n);
    for(int k = 0; k < n; k++){
        cin >> arr[k];
    }

    QuickSort(0, n-1);
    if(count < cnt) cout << -1;
}