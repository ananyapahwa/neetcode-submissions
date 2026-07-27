class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            
            // if(target-n == n){
            //     if(mp[n]) return{}
            // }
            // cout<<nums[i]<<" "<<mp[n]<<endl;
            // cout<<target-n<<" "<<mp[target-n]<<endl;
            if(mp[target-n]){
                return {mp[target-n]-1, i};
            }

            mp[n] = i+1; 
        }


        return {-1, -1};
    }
};
