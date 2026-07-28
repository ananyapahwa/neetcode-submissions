class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int n = nums.size();
        // int maxi = INT_MIN;
        // int mini = INT_MAX;
        for(int nu: nums){
            freq[nu]++;
            // maxi = max(maxi, freq[nu]);
            // mini = min(mini, freq[nu]);
        }

        vector<vector<int>> bucket(n+1);

        for(auto& f: freq){
            if(f.second != 0)
                bucket[f.second].push_back(f.first);
        }

        vector<int> ans;
        for(int i=n; i >=0 ; i--){
            if(bucket[i].size() > 0){
                for(int b: bucket[i]) {
                    if(ans.size() == k) return ans;
                    ans.push_back(b);
            }
        }
        }
        return ans;
        
    }
};
