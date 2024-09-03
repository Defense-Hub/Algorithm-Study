#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool cmp_HighY (pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}

bool cmp_HighX (pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

bool cmp_LowX (pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector <pair<int, int>> fileVec;
    
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#')
                fileVec.push_back({i, j});
        }
    }
    
    // 드래그 시작 좌표 구하기
    sort(fileVec.begin(), fileVec.end());
    answer.push_back(fileVec[0].first);
    sort(fileVec.begin(), fileVec.end(), cmp_LowX);
    answer.push_back(fileVec[0].second);

    // 드래그 종료 좌표 구하기
    sort(fileVec.begin(), fileVec.end(),cmp_HighY);
    answer.push_back(fileVec[0].first + 1);
    sort(fileVec.begin(), fileVec.end(), cmp_HighX);
    answer.push_back(fileVec[0].second + 1);

    return answer;
}
