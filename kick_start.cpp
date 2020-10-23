#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solve(string s) {
    vector<int> kick;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 2 && s.substr(i, 4) == "KICK") {
            kick.push_back(i);
            continue;
        }
        else if (i < s.size() - 3 && s.substr(i, 5) == "START") {
            ans += kick.size();
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
