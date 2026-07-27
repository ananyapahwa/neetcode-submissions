class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            int complement = target-n;

            auto it = mp.find(complement);

            if(it != mp.end()) return{it->second, i};

            mp[n] = i; 
        }


        return {-1, -1};
    }
};
