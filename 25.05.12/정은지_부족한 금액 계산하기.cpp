# include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long cost = (long long)price * count * (count+1) / 2;
    cost -= money;
    if (cost <= 0){
        cost = 0;
    }
    return cost;
}

int main(){
    cout << solution(3,20,4); // result = 10
    return 0;
}