class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int l = 0;
        int max_count_of_char = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++){
            map[s[r]]++;
            max_count_of_char = max(max_count_of_char, map[s[r]]);
            while((r - l + 1) - max_count_of_char > k){
                map[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
