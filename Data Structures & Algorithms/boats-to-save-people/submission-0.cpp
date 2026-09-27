class Solution {
public:
    int numRescueBoats(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0; int right = nums.size() - 1;
        int count= 0;
        while(left <= right){
            if(nums[right] + nums[left] <= k){
                left++;
            }
            count++;
            right--;
        }
        return count;
    }
};