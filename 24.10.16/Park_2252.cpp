#include <iostream>
#include <vector>
#include <queue>
// 13 : 13 ~ 13 : 45 hint 참고
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // 인접 리스트
    vector<int> indegree(N + 1, 0); // 각 학생의 진입 차수

    // 키 비교 정보를 입력받는다.
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }

    // 위상 정렬을 위한 큐
    queue<int> q;
    
    // 진입 차수가 0인 학생들을 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    // 위상 정렬 수행
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next : adj[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++)
        cout << result[i] << " ";
    
}