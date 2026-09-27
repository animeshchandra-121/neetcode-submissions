class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int target = prefix[n] % p;
        if(target == 0) return 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        int res = n;
        for(int i = 0; i <= n; i++){
            if(dict.count((prefix[i] - target + p)%p)){
                res = min(res, i - dict[((prefix[i] - target + p)%p)]);
            }
            dict[prefix[i] % p] = i;
        }
        if(res >= n) return -1;
        return res;
    }
};