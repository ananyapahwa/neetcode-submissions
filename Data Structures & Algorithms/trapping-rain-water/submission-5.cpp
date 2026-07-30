class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(height.size() <= 1) return 0;
        int i=0;
        int j = n-1;
        int maxL = 0, maxR = 0;
        int ans = 0;
        while(i < j){
            if(height[i] < height[j]){
                maxL = max(maxL, height[i]);
                ans += maxL - height[i];
                i++;
            }else{
                maxR = max(maxR, height[j]);
                ans += maxR - height[j];
                j--;
            }
        }


        return ans;
    }
};
