/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        // stack<char>  st = new stack<char> ();
        stack<char> st;
        for(char c : s){
            if(c == '(')  st.push(')');
            else if(c == '[')  st.push(']');
            else if(c == '{')  st.push('}');
            else if(st.empty() || st.top() != c)  return false;
            else if(st.top() == c) st.pop();
        }

        return st.empty();
    }
};