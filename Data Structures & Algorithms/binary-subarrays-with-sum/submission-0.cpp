class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;
        freq[0] = 1;
        int prefix_sum = 0; int ans = 0;
        for(int num: nums){
            prefix_sum += num;
            if(freq.count(prefix_sum - goal)){
                ans += freq[prefix_sum - goal];
            }
            freq[prefix_sum]++;
        }
        return ans;
    }
};