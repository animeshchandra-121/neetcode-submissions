class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int max_freq = 0; long long total = 0;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            while((long long)(i - l + 1) * nums[i] > total + k){
                total -= nums[l];
                l += 1;
            }
            max_freq = max(max_freq, (i - l + 1));
        }
        return max_freq;
    }
};