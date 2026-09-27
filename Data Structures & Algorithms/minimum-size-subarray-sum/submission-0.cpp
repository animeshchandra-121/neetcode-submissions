class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sums = 0;
        int res_len = INT_MAX; int len = 0;
        for(int r = 0; r < n; r++){
            sums += nums[r];
            while(sums >= target){
                len = r - l + 1;
                res_len = min(res_len, len);
                sums -= nums[l];
                l++;
            }
        }
        return res_len == INT_MAX ? 0 : res_len;
    }
};