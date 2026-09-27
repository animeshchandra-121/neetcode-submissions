class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map_of_t;
        for(int i = 0; i < t.size(); i++){
            map_of_t[t[i]] += 1;
        }
        int l = 0; int minLength = INT_MAX; 
         pair<int, int> res = {-1, -1}; int need = map_of_t.size();
        unordered_map<char, int> map_of_s;
        int have = 0;
        for(int r = 0; r < s.size(); r++){
            map_of_s[s[r]] += 1;
            if(map_of_t.count(s[r]) && map_of_s[s[r]] == map_of_t[s[r]]){
                have++;
            }
            while(have == need){
                if((r - l + 1) < minLength){
                    minLength = r - l + 1;
                    res = {l, r};
                }
                map_of_s[s[l]]--;
                if(map_of_t.count(s[l]) && map_of_s[s[l]] < map_of_t[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return minLength == INT_MAX ? "" : s.substr(res.first, minLength);
    }
};
