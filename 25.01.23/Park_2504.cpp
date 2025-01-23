#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//1330 ~ 1430
// REF : https://mjmjmj98.tistory.com/70
int main() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    string input;
    cin >> input;
    stack<char> st;
    int ans = 0;
    int tmp = 1;
    for(int i = 0; i < input.length(); i++){
        // stack을 활용해서 문제 풀이?
        // 오픈시 stack에 넣기
        // close시 매칭이 되고 stack이 남아있다면 stack top이 (이면 X2, [이면 X3
        
        // open인 경우

        if(input[i] == '('){
            tmp *= 2;
            st.push(input[i]);
        }
        else if(input[i] == '['){
            tmp *= 3;
            st.push(input[i]);
        }
        // close의 경우
        else{
            if(st.empty()){
                ans = 0;
                break;
            }

            if(input[i] == ')'){
                if(st.top() != '('){
                    ans = 0;
                    break;
                }
                if(input[i-1] =='('){
                    ans += tmp;
                    tmp /= 2;
                    st.pop();
                }
                else{
                    tmp /= 2;
                    st.pop();
                }
            }

            if(input[i] == ']'){
                if(st.top() != '['){
                    ans = 0;
                    break;
                }
                if(input[i-1] =='['){
                    ans += tmp;
                    tmp /= 3;
                    st.pop();
                }
                else{
                    tmp /= 3;
                    st.pop();
                }
            }
        }
    }

    if(!st.empty()) ans = 0;
    cout << ans;
}