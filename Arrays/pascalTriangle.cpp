vector<vector<int>> pascalTriangle(int numRows)
{

    //  The first and last element of each row is one, which provide us a cushion to not go out of bounds in start or end.
    //  Rest of the elements we fill by simple math.
    vector<vector<int>> r(numRows);
    for (int i = 0; i < numRows; i++)
    {
        r[i].resize(i + 1);    // increase the size of next row by 1
        r[i][0] = r[i][i] = 1; // initialize first and last element of each row as 1

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j]; // perform simple addition of elements of above row
    }
    return r;
}