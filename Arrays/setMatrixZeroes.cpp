
// The logic is to use the first element of the row and column as a flag while traversing top to down.

//  Then when moving upwarads use the same flag to set rest of the elements of that row or column to zero.

// Note: we use col0 or row0 an extra variable because the first element of first row and first column would coincide and the flag value will be overlapped.

void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}