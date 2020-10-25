/*22. 括号生成
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/
class Solution {
public:
    vector<string> res;

    void parenthesis(int left,int right,int n,string s){
        if(left == n && right == n){
            res.emplace_back(s);
            return ;
        }

        if(left < n){
            parenthesis(left+1,right,n,s+'(');
        }
        if(right < left){
            parenthesis(left,right+1,n,s+')');
        }
        return;
    }  

    vector<string> generateParenthesis(int n) {

        string s;
        int left = 0, right = 0;
        parenthesis(left,right,n,s);

        return res;
    }
};