#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, cnt;
int count = 0;
void merge(int left, int mid, int right){
    vector<int> tmp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int t = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }

    while(i <= mid){ // 왼쪽 부분이 남은 경우
        tmp[t++] = arr[i++];
    }

    while(j <= right){// 오른쪽 부분이 남은 경우
        tmp[t++] = arr[j++];
    }

    i = left;
    t = 0;
    while(i <= right){
        count++;
        arr[i++] = tmp[t];
        if(count == cnt) cout << tmp[t];
        t++;
    }
}

void mergeSort(int left, int right){
    if(left >= right) return;
    
    int mid = (left + right) / 2;
    mergeSort(left, mid); // 왼쪽 쪼개고
    mergeSort(mid+1, right); // 오른쪽 쪼개고
    merge(left, mid, right); // 합치고
}

int main (){ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin >> n >> cnt;
    arr.resize(n);

    for(int k = 0; k < n; k++){
        cin >> arr[k];
    }

    mergeSort(0, n-1);
    if(count < cnt) cout << -1;
}