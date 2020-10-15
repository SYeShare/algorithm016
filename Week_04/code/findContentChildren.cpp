//455. 分发饼干

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int child= 0, size = 0;

        while(child != g.size() && size != s.size()){
            if(g[child] <= s[size]){
                child ++;
            }
            size++;
        }
        return child;
    }
};