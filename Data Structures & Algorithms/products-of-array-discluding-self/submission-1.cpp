//WITH NO EXTRA SPACE

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        //constructing prefix multiplication
        ans[0] = 1;
        for(int i=1; i<n; i++){
            ans[i] = nums[i-1]*ans[i-1];
        }

        //calculating the answer
        int suffix = 1;
        for(int i=n-1; i >= 0; i--){
            ans[i]= ans[i]*suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
