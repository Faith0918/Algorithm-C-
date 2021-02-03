#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, float> &a, pair<int,float> &b) {
    if (a.second > b.second) {
        return true;
    }
    else if(a.second == b.second){
        return a.first < b.first;
    }
    else {
        return false;
    }
}



vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> v;
    
    sort(stages.begin(), stages.end());
    int before = stages[0];
    int cnt = 0;
    for (int i = 0; i < stages.size(); i++) {
        cout<<stages[i]<<"\t";
    }
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] > before) {
            cout << "stage : " << before << "\n";
            if ((stages.size() + cnt - i) == 0) {//끝
                v.push_back(make_pair(N, 0.0));
                cnt = 1;
                before = stages[i];
            }
            else {
                float fail = float(cnt) / float(stages.size() + cnt - i);
                cout << "cnt : " << cnt << "\n";
                cout << "개수 : " << stages.size() + cnt - i<<"\n";
                cout << "fail : " << fail << "\n";
                v.push_back(make_pair(before, fail));
                cnt = 1;
                before = stages[i];
            }
            
        }
        else {
            cout << "what? : " << stages[i]<<"\n";
            cout << "before : " << before << "\n";
            cout << "cnt : "<<cnt<< "\n";
            cnt++;
        }
    }
    if (cnt > 0 && before<N+1) {
        v.push_back(make_pair(before, 1.0));
    }
    vector<bool> check(N + 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << to_string(v[i].second) << "\n";
    }
    for (int i = 1; i < N+1; i++) {
        if (find_if(v.begin(), v.end(), [&i](const pair<int, float>& p) {return p.first == i; }) == v.end()) {
            v.push_back(make_pair(i, 0.0));
        }
        
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].first);
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\t";
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
    cout << "\n\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
}