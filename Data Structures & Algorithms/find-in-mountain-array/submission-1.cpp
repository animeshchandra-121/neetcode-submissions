/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // finding the pivot
        int low = 0;
        int high = mountainArr.length() - 1;
        int pivot = 0;
        while(low < high){
            int mid = (low + high) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        pivot = low;
        // finding index to left part of the pivot
        int left = 0;
        int right = pivot - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            if(mountainArr.get(mid) > target) right = mid - 1;
            else left = mid + 1;
        }
        // finding the index on the right part of the array
        int reverse_left = pivot;
        int reverse_right = mountainArr.length() - 1;
        while(reverse_left <= reverse_right){
            int reverse_mid = (reverse_left + reverse_right) / 2;
            if(target == mountainArr.get(reverse_mid)){
                return reverse_mid;
            }
            if(mountainArr.get(reverse_mid) > target) reverse_left = reverse_mid + 1;
            else reverse_right = reverse_mid - 1;
        }
        return -1;
    }
};