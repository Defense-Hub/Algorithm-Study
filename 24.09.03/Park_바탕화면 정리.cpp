#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 51;
    int minY = 51;
    int maxX = -1;
    int maxY = -1;
    for(int x = 0; x < wallpaper.size(); x++){
        for(int y = 0; y < wallpaper[0].size(); y++){
            // min, max
            if(wallpaper[x][y] == '#'){
                minX = min(minX, x);
                maxX = max(maxX, x);
                minY = min(minY, y);
                maxY = max(maxY, y);
            }
        }
    }
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX + 1);
    answer.push_back(maxY + 1);
    
    return answer;
}