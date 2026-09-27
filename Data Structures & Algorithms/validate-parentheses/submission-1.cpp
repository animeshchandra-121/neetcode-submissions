class Solution {
public:
    bool isValid(string s) {
        std::stack<char> paranthesis;
        for(char ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                paranthesis.push(ch);
            }else{
                if (paranthesis.empty())
                    return false;
                if (ch == ')'&& paranthesis.top() == '(')
                    paranthesis.pop();
                else if (ch == ']'&& paranthesis.top() == '[')
                    paranthesis.pop();
                else if (ch == '}' && paranthesis.top() == '{')
                    paranthesis.pop();
                else
                    return false;
            }
        }
        return paranthesis.empty();
    }
};
