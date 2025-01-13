#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(true){
        if((bill[0] <= wallet[0] && bill[1] <= wallet[1]) || (bill[1] <= wallet[0] && bill[0] <= wallet[1])) break;
        
        if(bill[0] > bill[1]){
            bill[0] /= 2;
            answer++;
        }
        
        else{
            bill[1] /=2;
            answer++;
        }
    }
    
    return answer;
}