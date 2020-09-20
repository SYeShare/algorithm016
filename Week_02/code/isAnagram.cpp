//242. 有效的字母异位词
//49. 字母异位词分组 https://leetcode-cn.com/problems/group-anagrams/solution/c-yin-ru-hashbiao-shi-jian-32ms-ji-bai-9948-nei-cu/


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())  return false;

        int hash[26] = {0};

        for(char c: s) hash[c - 'a'] ++;
        for(char c: t) {
            if(--hash[c-'a'] == -1)  return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        int sub = 0; //res 序号
        unordered_map<string,int> valuemap; //判断是否存在；存在补，不存在加

        string strtmp;
        for(auto str :strs){
            strtmp = str;
            sort(strtmp.begin(),strtmp.end());
            if(valuemap.count(strtmp)){
                res[valuemap[strtmp]].emplace_back(str);
            }else{
                valuemap[strtmp] = sub++;
                vector<string> vectmp(1,str);
                res.emplace_back(vectmp);
            }
        }
        return res;
    }
};