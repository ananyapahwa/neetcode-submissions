class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        unordered_map<int,bool> present;
        for(int n: nums) present[n] = true;
        
        int maxi = 1;
        for(int n: nums){
            if(!present[n]) continue;
            int t = 1;
            present[n] = false;
            int tempN = n;
            //smaller than n;
            while(present[--n]){
                t++;
                present[n] = false;
              
            }
            while(present[++tempN]){
                t++;
                present[tempN] = false;
            }

            maxi = max(maxi, t);
        }
    return maxi;
    }
};
