class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int n = nums.size();
       vector<double> prefix(n + 1, 0.0);
       for(int i = 0; i < n; i++){
         prefix[i + 1] = prefix[i] + log(nums[i]);
       }
       int count = 0;
       for(int i = 0; i < n; i++){
        int low = i+1; int high = n + 1;
        while(low < high){
            int mid = (low + high)/2;
            if(prefix[mid] < log(k) + prefix[i] - 1e-12){
                low = mid + 1;
            }
            else{ high = mid;}
        }
        count += low - i - 1;
       }
       return count;
    }
};