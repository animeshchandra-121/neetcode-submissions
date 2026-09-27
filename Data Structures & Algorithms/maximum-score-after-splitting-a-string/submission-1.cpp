class Solution {
public:
    int maxScore(string s) {
        int total_ones = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') total_ones++;
        }
        int ones = 0, zeros = 0;
        int res = 0;
        if(s[0] == '1') ones++;
        else zeros++;
        for(int i = 1; i < s.length(); i++){
            res = max(res, zeros + total_ones - ones);
            if(s[i] == '0') zeros++;
            if(s[i] == '1') ones++;
        }
        return res;
    }
};