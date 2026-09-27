class Solution {
   public:
    int calPoints(vector<string>& operations) {
      stack<int> st;

        for (string op : operations) {
            if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }
            else if (op == "D") {
                int digit = st.top();
                st.push(2 * digit);
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }
        int total_sum = 0;
        while (!st.empty()) {
            total_sum += st.top();
            st.pop();
        }
        return total_sum;
    }
};