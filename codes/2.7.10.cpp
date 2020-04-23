void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min = m[0][0], num;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(min > m[i][j])
            {
                num = i;
                min = m[i][j];
            }
    int *tmp = m[num];
    m[num] = m[0];
    m[0] = tmp;
}
