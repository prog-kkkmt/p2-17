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

