#include<iostream>
#include<string>
using namespace std;
//leetcode
class Solution {
public:
    bool isPalindrome(int x) {
        //Version1. changing int to string

        string s = to_string(x);
        for (int i = 0; i < (s.size()) / 2; i++) {
            cout << s[i] << "\t" << s.size() - i - 1;
            if (s[i] != s[s.size() - i - 1]) {
                return 0;
            }
        }
        return 1;

    }
};