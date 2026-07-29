class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>row(9, vector<bool>(9, false));
        vector<vector<bool>>col(9, vector<bool>(9, false));
        vector<vector<bool>>box(9, vector<bool>(9, false));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                int value = board[i][j];
                if(value == '.') {
                    continue;
                }
                value = value-'1';
                int boxV = (i/3)*3+(j/3);
                if(!row[i][value] && !col[value][j] && !box[boxV][value]){
                row[i][value] = true;
                col[value][j] = true;
               
                box[boxV][value] = true;
                }else 
                    return false;


            }
        }

        return true;
    }
};
