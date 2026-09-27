class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        int k = s1.size();
        for(int i = 0; i < k; i++){
            map1[s1[i]] += 1;
        }
        for(int r = 0; r < s2.size(); r++){
            map2[s2[r]]++;
            if(r >= k){
                map2[s2[r - k]]--;
                if (map2[s2[r - k]] == 0)
                    map2.erase(s2[r - k]);
            }
            if(map2 == map1){
                return true;
            }
        }
        return false;
    }
};
