#include <string>
#include <vector>
#include <iostream>
#define INF 987654321
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftTh = 10;
    int rightTh = 12;
    for(int k = 0; k < numbers.size(); k++){
        if(numbers[k] == 1 || numbers[k] == 4 || numbers[k] == 7){
            answer += "L";
            leftTh = numbers[k];
        }
        else if(numbers[k] == 3 || numbers[k] == 6 || numbers[k] == 9){
            answer += "R";
            rightTh = numbers[k];
        }
        else{
            if(numbers[k] == 0) numbers[k] = 11;
            // 좌우로 한칸 + (현재 Y 좌표 = lN / 3)
            int lDist, rDist;
            if(leftTh % 3 == 1)
                lDist = 1 + abs((leftTh / 3) - (numbers[k] / 3));
            else
                lDist = abs((leftTh / 3) - (numbers[k] / 3));
            
            if(rightTh % 3 == 0)
                rDist = 1 + abs(((rightTh / 3) - 1) - (numbers[k] / 3));
            else 
                rDist = abs((rightTh / 3) - (numbers[k] / 3));
            
            
            if(lDist < rDist){
                answer += "L";
                leftTh = numbers[k];
            }
            else if(lDist > rDist){
                answer += "R";
                rightTh = numbers[k];
            }
            else{
                if(hand.compare("right") == 0){
                    answer += "R";
                    rightTh = numbers[k];
                }
                else{
                    answer += "L";
                    leftTh = numbers[k];
                }
            }   
        }
    }
    return answer;
}