class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i , j; 
        for (i = 0 ; i < (matrix.size()+1) / 2; i++) {
            for (j = i; j < matrix.size() - 1 - i; j++ ) {
                int count = 4;
                exchange(matrix, j , i, matrix[j][i] , count);
            }
        }

    }

    void exchange(vector<vector<int>>& matrix, int x, int y , int currentTmp, int &count) {
        if (count == 0){return;}
        count--;
        int destinationX = y;
        int destinationY = matrix.size() - 1 - x;
        int tmp = matrix[destinationX][destinationY];
        matrix[destinationX][destinationY] = currentTmp;
        exchange(matrix, destinationX, destinationY , tmp , count);
    }
};