#includealgorithm

class Solution {
public
    static bool cmp(pairint, int &p1, pairint,int &p2){
        return p1.secondp2.second;
    };

    vectorint twoSum(vectorint& nums, int target) {
        vectorint v;
        bool flag = false;
        vectorpairint, int  numbs;
        
        for(int i = 0; inums.size();i++){
            numbs.push_back(make_pair(i,nums[i]));
        }
        sort(numbs.begin(), numbs.end(),cmp);
        for(int i = 0; inums.size();i++){
            if(!flag){
                for(int j = i+1; jnums.size();j++){
                int candi = numbs[i].second + numbs[j].second;
                if(target == candi){
                    flag = true;
                    v.push_back(numbs[i].first);
                    v.push_back(numbs[j].first);
                    break;
                }
                else if(candi  target){
                    break;
                }
            }
            }
            
        }
        return v;
    }
};