//647. 回文子串
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = i, r = i; //以单字母为中心
            while (l >= 0 && r < n && s[l--] == s[r++]) ++ans;
            l = i, r = i + 1; //以双字母为中心
            while (l >= 0 && r < n && s[l--] == s[r++]) ++ans;
        }
        return ans;
    }
};

作者：Gary_coding
链接：https://leetcode-cn.com/problems/palindromic-substrings/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-zhong-xin-kuo-zh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。