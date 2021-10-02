

// Solution
// rule1. ÀÌÀü ÀÎµ¦½º °ª < ÀÌÈÄ ÀÎµ¦½º °ª - »¬¼À
// rule2. ÀÌÀü ÀÎµ¦½º °ª >= ÀÌÈÄ ÀÎµ¦½º °ª - µ¡¼À

#include <bits/stdc++.h>
#include <iostream>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;      // MinGW gcc ÄÄÆÄÀÏ·¯
class Solution {
public:
    int romanToInt(string s) {
        hash_map<char, int> map;
        int ans = 0;
        int base[7] = { 1000,500,100,50,10,5,1 };
        map.insert(make_pair('M', 1000));
        map.insert(make_pair('D', 500));
        map.insert(make_pair('C', 100));
        map.insert(make_pair('L', 50));
        map.insert(make_pair('X', 10));
        map.insert(make_pair('V', 5));
        map.insert(make_pair('I', 1));
        ans += map[s[0]];
        for (int i = 0; i < s.length(); i++) {
            int cur = map[s[i]];
            int pre = map[s[i - 1]];
            if (pre < cur) ans -= pre * 2;
            ans += cur;
        }


        cout << ans;
        return ans;
    }
};