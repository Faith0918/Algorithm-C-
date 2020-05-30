/*
1) 간선 가중치가 작은 순서대로 정렬
2) 간선 가중치가 작은 간선부터 차례대로 선택하려는 시도를 해본다.
 2-1)시작점과 끝점이 같은 그룹에 속한다면, 그냥 넘어간다.
  2-2)그게 아니라면, 이 간선을 선택한다이 간선의 가중치를 더한다.
      시작점과 끝점을 같은 그룹으로 만들어 준다
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge {
    int p;
    int q;
    int cost;
};

bool compare(edge e1, edge e2) {
    return e1.cost < e2.cost;
}
const int MAX = 100;
int n, m,result;
vector<edge> edgeList;
int parent[MAX];//parent[x] : x의 부모노드의 번호

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

bool Union(int a, int b) {
    //a, b가 같은 그룹인지 판단.
    //만약 같은 그룹이라면, false를 반환
    //그게 아니라면, a,b를 같은 그룹으로 만들고 true를 반환.
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return false;
    else {
        parent[rootA] = rootB;
        return true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        edge e;
        cin >> e.p >> e.q >> e.cost;
        edgeList.push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    sort(edgeList.begin(), edgeList.end(), compare);
    for (int i = 0; i < m; i++) {
    //edgelist의 간선을 선택하려고 시도할거임
        if (Union(edgeList[i].p,edgeList[i].q )){
            result += edgeList[i].cost;
        }
    }
    cout << result;
}