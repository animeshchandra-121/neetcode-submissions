class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = -1;
        int prefix_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            int rem = prefix_sum % k;
            if(freq.count(rem)){
                if(i - freq[rem] > 1) return true;
            }else{
                freq[rem] = i;
            }
        }
        return false;
    }
};