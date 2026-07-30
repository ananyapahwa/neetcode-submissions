class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(height.size() <= 1) return 0;
        int i=0;
        //step 1: start from a non-zero number
        while(i<n && height[i] == 0) i++;
        int j = i+1;
        int ans = 0;
        //step 2: find the next greater element
        while(i<n && j<n){
            int temp = 0;
            while(j<n && height[j] < height[i]){
                temp += height[i] - height[j];
                // cout<<height[i]<<" "<<height[j]<<endl;
                j++;
            }

            if(j<n){
                ans += temp;
                i = j;
                j++;
            }
            else{
                i++;
                j=i+1;
                int maxRight = i;
                for(int k=i; k<n; k++){
                    if(height[maxRight] < height[k])
                        maxRight = k;
                }

                for(int k=i; k<maxRight; k++){
                     ans += height[maxRight] - height[k];
                }
               
            }
        }

        return ans;
    }
};
