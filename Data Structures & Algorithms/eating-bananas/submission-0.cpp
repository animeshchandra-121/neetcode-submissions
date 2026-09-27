class Solution {
public:
    bool check(vector<int>& piles, int mid, int h){
        int total = 0;
        for(int i = 0; i < piles.size(); i++){
            total += ceil((double)piles[i] / mid);
            // if(piles[i] < mid){
            //     total += 1;
            // }
        }
        if(total <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(check(piles,mid,h)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
