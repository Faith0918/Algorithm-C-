#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, N, K, P;
vector<int> c;
vector<vector<int>> plates;
int answer;

int getPoints(vector<int> combi) {
    int total = 0;
    for (int i = 1; i <= N; i++) {
        int a = combi[i];
        for (int j = 1; j <= a; j++) {
            total += plates[i][j];
        }
    }
    return total;
}
vector<int> countCombi() {
    vector<int> v(N+1);
    for (int i = 1; i <= P; i++) {
        v[c[i]]++;
    }
    return v;
}

//Combination with repitition
//n H p : getting combination of p in a set of n with repitition
void dfs(int index, int cnt) {
    //if "cnt" exceeds "p", count number of the repeated 
    if (cnt == P+1) {
        vector<int> combi = countCombi();
        for (int i = 1; i <= N; i++) {
            if (combi[i] > K) {
                return;
            }
        }
        int candi = getPoints(combi);
        if (candi > answer) {
            answer = candi;
        }
        return;
    }
    //else, pick every possible elements.
    else {
        for (int i = index; i <= N; i++) {
            c[cnt] = i;
            dfs(i, cnt + 1);
        }
    }
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> K>>P;
        answer = 0;
        vector<vector<int>> plate(N+1);
        for (int i = 1; i <= N; i++) {
            vector<int> v(K+1);
            for (int j = 1; j <= K; j++) {
                cin >> v[j];
            }
            plate[i] = v;
        }
        plates = plate;
        vector<int> v(P + 1);
        c = v;
        dfs(1, 1);

        cout << "Case #" << t << ": " << answer << "\n";

    }
}