#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool sort_by_idx(pair<ll, int> a, pair<ll, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, ll k) {
    vector<pair<ll, int>> times;
    for (int i = 0; i < food_times.size(); i++) {
        times.push_back({ food_times[i], i + 1 });
    }
    sort(times.begin(), times.end());
    int n = times.size();
    int i = 0;
    for (; i < n; i++) {
        ll diff = (i == 0 ? times[0].first : times[i].first - times[i - 1].first);
        ll total = diff * (n - i);
        if (k - total < 0) break;
        else k -= total;
    }
    if (i == n) return -1;
    k %= (n - i);
    sort(times.begin() + i, times.end(), sort_by_idx);
    return times[i + k].second;
}
int main(void) {
    //vector<int> food_times = { 6,6,6,6,6,6,6 };
    //long long k = 40;
    vector<int> food_times = { 3, 1, 2 };
    long long k = 6;
    cout << solution(food_times, k);
    return 0;
}