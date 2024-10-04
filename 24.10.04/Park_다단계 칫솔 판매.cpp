#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parentData;
unordered_map<string,int> profit;

void Update(string name, int money){
    if(name == "none") return;
    
    int forParent = money * 0.1;
    profit[name] += (money - forParent);
    if(forParent < 1) return;
    Update(parentData[name], forParent);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;        
    for(int k = 0; k < enroll.size(); k++){
        if(referral[k] == "-") parentData[enroll[k]] = "none";
        // 이름이 나올 경우 
        // k 번째에 있는 enroll의 부모는 referral의 k번째에 있는 사람임을 뜻한다.
        // 즉, edward(enroll) -> mary(referral)가 되어야함
        
        parentData[enroll[k]] = referral[k];
    }
    
    for(int k = 0; k < seller.size(); k++){
        Update(seller[k], amount[k] * 100);        
    }
    
    for(int k = 0; k < enroll.size(); k++){
        answer.push_back(profit[enroll[k]]);
    }
    
    return answer;
}