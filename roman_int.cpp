#include<hash_map>
class Solution {
public:
    int romanToInt(string s) {
        hashmap<char, int> map;
        int ans = 0;
        vector<int> v;
        cout << num << "\n";
        int base[7] = { 1000,500,100,50,10,5,1 };
        map.put(make_pair('M', 1000));
        map.put(make_pair('D', 500));
        map.put(make_pair('C', 100));
        map.put(make_pair('L', 50));
        map.put(make_pair('X', 10));
        map.put(make_pair('IX', 9));
        map.put(make_pair('V', 5));
        map.put(make_pair('IV', 4));
        map.put(make_pair('I', 1));

        for (int i = 0; i < base.size(); i++) {
            int a = num / base[i];
            if (a == 0) {
                contine;
            }
            else {
                v.push_back(a);
                num = num % base[i];
            }
        }
        int Size = v.size();
        for (int i = 0; i < Size(); i++) {
            ans += v[i] * 1e(Size - i);
        }
        cout << ans;
    }
};