class Solution {
public:
    bool check(vector<int>& nums, int limit, int k) {
        int cnt = 1;
        int sum = 0;

        for (int x : nums) {
            if (sum + x <= limit) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }
        }

        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};