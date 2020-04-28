void swap_min(int *m[], unsigned rows, unsigned cols)
{
    if(rows)
    {
        int min = **m; min_i = 0; /**(**m - указатель на нулевой элемент матрици),
        (min_i - номер строки в которой будет минимальный элемент)*/

        for(int i = 0; i < roes * cols; i++)
        {
            if(min > m[i / cols][i % cols])
            {
                min = m[i / cols][i % cols];
                min_i = i / cols;
            }
        }
        /**Меняем местами строки*/
        int *t = *m;
        *m = m[min_i];
        m[min_i] = t;
    }
}
