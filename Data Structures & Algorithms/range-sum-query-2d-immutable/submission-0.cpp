class NumMatrix {
public:
    vector<vector<int>> prefixsum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixsum.assign(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)); //created with an extra row and col
        for(int i=0;i<matrix.size();i++)
        {
            int sum=0;
            for(int j=0;j<matrix[i].size();j++)
            {
                sum+=matrix[i][j];
                prefixsum[i+1][j+1] = sum+prefixsum[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; row2++; col1++; col2++;
        int leftsum= prefixsum[row2][col1-1];
        int topsum= prefixsum[row1-1][col2];
        int topleft= prefixsum[row1-1][col1-1];
        int totalbox= prefixsum[row2][col2];
        return totalbox-leftsum-topsum+topleft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */