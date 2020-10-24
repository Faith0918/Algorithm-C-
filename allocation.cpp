#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int T, N, B;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> B;
        vector<int> h(N);
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        int sum = 0;
        int answer = 0;
        for (vector<int> ::iterator iter = h.begin(); iter != h.end(); ++iter) {
            if (sum + *iter > B) {
                break;
            }
            else {
                sum += *iter;
                answer++;
            }
        }
        cout << "Case #" << t << ": " << answer << "\n";

    }
}