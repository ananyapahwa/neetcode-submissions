class Solution {
public:
    bool isPossible(double k, vector<int>& piles, int h){
        int eaten = 0;
        int hours = 0;
        for(double p: piles){
            hours += ceil(p/k);
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(start <= end){
            int mid = start + (end- start)/2;

            if(isPossible(mid, piles, h)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;
    }
};
