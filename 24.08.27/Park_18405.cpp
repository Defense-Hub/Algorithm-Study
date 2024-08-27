#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> point;
typedef pair<int,point> ppt;

int N, K, S, X, Y;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mat[1001][1001];
struct cmp{
    bool operator()(ppt a, ppt b){
        if (a.first != b.first)
            return a.first > b.first;
        else
            return mat[a.second.first][a.second.second] > mat[b.second.first][b.second.second];
    }
};
priority_queue <ppt,vector<ppt>,cmp> pq;
void bfs(){
    while(!pq.empty()){
        int curx = pq.top().second.first;
        int cury = pq.top().second.second;
        int curt = pq.top().first;
        pq.pop();
        if(curt == S + 1)
            break;
        for(int k = 0 ; k < 4 ;k++){
            if(curx + dx[k] >=1 && curx + dx[k] <= N && cury + dy[k] >= 1 && cury + dy[k] <= N){
                if(!mat[curx + dx[k]][cury + dy[k]]){
                    mat[curx + dx[k]][cury + dy[k]] = mat[curx][cury];
                    pq.push(make_pair(curt + 1,make_pair(curx + dx[k],cury+dy[k])));
                }
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i = 1 ; i <= N ;i++){
        for(int j = 1 ; j <= N ;j++){
            cin >> mat[i][j];
            if(mat[i][j]){
                pq.push(make_pair(1,make_pair(i,j)));
            }
        }
    }
    cin >> S >> X >> Y;
    bfs();    
    cout << mat[X][Y];
}