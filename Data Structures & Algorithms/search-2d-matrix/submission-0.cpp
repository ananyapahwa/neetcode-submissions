class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(); //row
        int m = matrix[0].size();   //column
        
        //find the row 
        int start = 0, end = n-1;
        int row; 
        while(start <= end){
            int mid = start+(end-start)/2;

            //found the row
            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target){
                row = mid;
                break;
            }
            else if(matrix[mid][0] >= target) end = mid-1;
            else start = mid+1;
        }


        //binary search in that row
        start = 0; end = m-1;

        while(start <= end){
            int mid = start+(end-start)/2;

            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) end = mid-1;
            else start = mid+1;
        }


        return false;
    }
};
