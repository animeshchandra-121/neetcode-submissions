/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> doors;
        for(auto& num : intervals){
            doors[num.start] += 1;
            doors[num.end] -= 1;
        }
        int res = 0;
        int count = 0;
        for(auto& [key, value]: doors){
            count += value;
            res = max(res, count);
        }
        return res;
    }
};
