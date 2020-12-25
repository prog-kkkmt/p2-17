//Ќапишите функцию, котора€ принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows x cols ,
//и возвращает транспонированную матрицу M^T (тоже двумерный целочисленный массив) размера rows x cols.
//≈сли в M на пересечении i-ой строки и j-ого столбца сто€ло число x, то на пересечении  j-ой строки и i-ого столбца в матрице M^T
//тоже будет сто€ть число x, или другими словами M^T[j][i] = M[i][j].


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
int **matrix = new int *[cols];

for (int i = 0; i<cols; i++)
matrix[i] = new int [rows];

for (int i=0; i<cols; i++)
{
for (int j=0; j<rows; j++)
{
matrix[i][j] = m[j][i];
}
}
return(matrix);
}
