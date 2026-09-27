class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + (nums[i] == 0? 1: 0);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            int low = i, right = n + 1;
            while(low < right){
                int mid = (low + right) / 2;
                if(prefix[mid] - prefix[i] <= k){
                    low = mid + 1;
                }else{
                    right = mid;
                }
            }
            res = max(res, low - i - 1);
        }
        return res;
    }
};