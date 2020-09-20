//1. 两数之和

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

    //暴力法
    #if 0
        for(int i =0; i< nums.size() -1 ;i++){
            for(int j = i+1; j< nums.size() ; j++){
                if(nums[j] == target- nums[i]){
                    res.emplace_back(i);
                    res.emplace_back(j);
                    return res;
                }
            }
        }
    #endif

    //使用map结构；
    #if 1
        unordered_map<int,int> map;
        for(auto i =0 ; i < nums.size();i++){
            map[nums[i]] = i; 
        }

        for(auto i =0 ; i < nums.size();i++){
            int value = target - nums[i];

            if(map.count(value) && map[value] != i){
                res.emplace_back(i);
                res.emplace_back(map[value]);
                break;
            }
        }
    #endif

        return res;
    }
};