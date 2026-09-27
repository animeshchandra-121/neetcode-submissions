class Solution {
public:
    int check_validity(vector<int>& weights, int W, int days){
        int w_i = 0;
        int day = 1;
        for(int i = 0; i < weights.size(); i++){
            if(w_i + weights[i] <= W){
                w_i += weights[i];
            }else{
                w_i = weights[i];
                day++;
                if(day > days) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check_validity(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};