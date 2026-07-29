class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        unordered_map<int, bool> present;

        for(int n: nums){
            present[n] = true;
        }
        int maxi = INT_MIN;
        for(int n: nums){
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
