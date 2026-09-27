class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0; 
        int right = nums.size() - 1;
        int ans = nums[0];
        while(left <= right){
            int mid = left + ((right - left)/2);
            if(nums[0] < nums[mid]){
                if(nums[mid] <= nums[right] && nums[mid] <= ans){
                    ans = nums[mid];
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(nums[mid] <= nums[right] && nums[mid] <= ans){
                    ans = nums[mid];
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return ans;
    }
};
