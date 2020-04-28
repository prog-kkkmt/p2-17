int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    /**Ёффективным способом выдел€ем пам€ть под матрицу размера[cols * rows]*/
    int **m2 = new int *[cols];
    *m2 = new int [cols * rows];
    for(int i = 1; i != cols; i++)
    {
        m2[i] = m2[i - 1] + rows;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            n2[j][i] = m[i][j];
        }
    }
    return m2;
}
