class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        int res = 0;
        for(int num: nums){
            int prev = max(count[num], count[k]);
            count[num] = prev + 1;
            res = max(res, count[num] - count[k]);
        }
        return res + count[k];
    }
};