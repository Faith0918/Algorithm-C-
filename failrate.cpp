#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> v;

    for (int i = 0; i < N; i++) {
        answer.push_back(0);
    }
    int before = stages[0];
    int cnt = 0;
    sort(stages.begin(), stages.end());
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] > before) {
            cout << "stage : " << before << "\n";
            if ((N + cnt - i) == 0) {
                v.push_back(make_pair(N, 0.0));
                cnt = 1;
                before = stages[i];
            }
            else {
                float fail = float(cnt) / float(N + cnt - i);
                cout << "fail : " << fail << "\n";
                v.push_back(make_pair(before, fail));
                cnt = 1;
                before = stages[i];
            }
            
        }
        else {
            cnt++;
        }
    }
    if (cnt > 0 && before<N+1) {
        v.push_back(make_pair(before, 1.0));
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << to_string(v[i].second) << "\n";
    }
    return answer;
}
int main() {
    int N = 5;
    vector<int> stages;
    stages.push_back(2);
    stages.push_back(1);
    stages.push_back(2);
    stages.push_back(6);
    stages.push_back(2);
    stages.push_back(4);
    stages.push_back(3);
    stages.push_back(3);
    vector<int> ans =  solution(N, stages);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]<<"\t";
    }
}