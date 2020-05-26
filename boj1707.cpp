#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector<int> graph[20001];
vector<int> visited;

void dfs(int node, int color) {

    for (int i = 0; i < graph[node].size(); i++) {

        //기존의 color와 다른 색으로 연결한 뒤에 깊이 탐색
        if (!visited[graph[node][i]]) {
            visited[graph[node][i]] = color * -1;
            dfs(graph[node][i], color * -1);
        }
    }
}

bool bipartite() {

    for (int i = 1; i <= V; i++) {
        int color = visited[i];

        //연결된 요소와 같은 집합(color)을 갖는지 확인
        for (int j = 0; j < graph[i].size(); j++) {
            if (color == visited[graph[i][j]])
                return false;
        }
    }
    return true;
}
int main() {

    int K;
    cin >> K;

    while (K--) {
        cin >> V >> E;

        int src, dest;
        for (int i = 0; i < E; i++) {
            scanf("%d %d", &src, &dest);
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        visited = vector<int>(V + 1, 0);

        for (int i = 1; i <= V; i++) {

            if (graph[i].size() == 0)
                continue;

            //한번도 방문한 적 없을 때 값을 1로 설정한 다음에 dfs로 연결된 요소 확인
            if (!visited[i]) {
                visited[i] = 1;
                dfs(i, 1);
            }
        }

        if (bipartite()) printf("YES\n");
        else    printf("NO\n");

        for (int i = 1; i <= V; i++)
            graph[i].clear();

    }


    return 0;
}
