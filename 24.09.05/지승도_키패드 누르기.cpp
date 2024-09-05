#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

int dial [12][2] = {{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3} ,{4,1} ,{4,3}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left= 10 , right = 11;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = numbers[i];
        }   
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = numbers[i];
        }
        else{
            int targetY = dial[numbers[i]][0];
            int targetX = dial[numbers[i]][1];
          int curLeft = abs(targetY - dial[left][0]) + abs(targetX - dial[left][1]);
            int curRight = abs(targetY - dial[right][0]) + abs(targetX - dial[right][1]);

            if(curRight == curLeft){
                if(hand == "right"){
                    answer += "R";
                    right = numbers[i];
                }
                else{
                    answer += "L";
                    left = numbers[i];
                } 
            }
            else if(curRight < curLeft){
                    answer += "R";
                    right = numbers[i];
            }
            else
            {
                    answer += "L";
                    left = numbers[i];
            }
        }
    }
    
    return answer;
}
