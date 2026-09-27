class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_count = 0; int even_count = 1;
        int prefix_sum = 0; int count = 0;
       const int MOD = 1e9 + 7;
        for(int num : arr){
            prefix_sum += num;
            if(prefix_sum % 2 != 0){
                odd_count += 1;
                count += even_count;
            }else{
                even_count += 1;
                count += odd_count;
            }
            count %= MOD;
        }
        return count;
    }
};