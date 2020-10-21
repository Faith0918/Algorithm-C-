#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solve(string s) {
    vector<int> kick;
    vector<int> start;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << "\n";
        if (i < s.size() - 2 && s.substr(i, 4) == "KICK") {
            cout << s.substr(i, 4) << "\n";
            kick.push_back(i);
            i += 3;
            continue;
        }
        else if (i < s.size() - 3 && s.substr(i, 5) == "START") {
            cout << s.substr(i, 5) << "\n";
            start.push_back(i);
            ans += kick.size();
            i += 4;
            continue;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string s;
        cin >> s;
        int ans = solve(s);
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
