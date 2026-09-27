class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        int right_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            right_sum = total_sum - nums[i] - left_sum;
            cout<< "right_sum: " << right_sum << " ";
            if(left_sum == right_sum){
                return i;
            }
            left_sum += nums[i];
            cout<< "left sum: " << left_sum << " ";
        }
        return -1;
    }
};