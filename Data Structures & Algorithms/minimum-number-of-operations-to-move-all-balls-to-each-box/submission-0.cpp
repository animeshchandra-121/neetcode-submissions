class Solution {
public:
    vector<int> minOperations(string boxes) {
        int moves_made = 0;
        int balls_present = 0;
        vector<int> answer(boxes.size(), 0);
        // for left
        for(int i = 0; i < boxes.size(); i++){
            answer[i] += moves_made;
            balls_present += boxes[i] - '0';
            moves_made += balls_present;
        }
        // for right
        moves_made = 0;
        balls_present = 0;
        for(int i = boxes.size() - 1; i >= 0; i--){
            answer[i] += moves_made;
            balls_present += boxes[i] - '0';
            moves_made += balls_present;
        }
        return answer;
    }
};