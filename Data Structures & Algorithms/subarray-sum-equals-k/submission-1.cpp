class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        map[0] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(map.count(prefix[i] - k) > 0){
                ans += map[prefix[i] - k];
            }
            map[prefix[i]]++;
        }
        return ans;
    }
};