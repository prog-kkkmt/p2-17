int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **matrix = new int *[cols];
    matrix[0] = new int[rows * cols];
    for (int i = 1; i < cols; ++i)
    {
        matrix[i] = matrix[i - 1] + rows;
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[j][i] = m[i][j];
        }
    }
    return matrix;
}
