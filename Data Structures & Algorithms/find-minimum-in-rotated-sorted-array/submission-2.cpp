class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            //now when the condition is true
            if(start == end) return nums[start];
            //all four cases handled
            if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) 
                end = mid;
            if(nums[mid] >= nums[start] && nums[mid] > nums[end]) 
                start = mid+1;
            if(nums[mid] >= nums[start] && nums[mid] <= nums[end])
                end = mid;
        }

        return nums[start];
    }
};
