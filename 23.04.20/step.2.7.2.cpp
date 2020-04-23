void swap_min(int *m[], unsigned rows, unsigned cols)
{
  int minN = 0;
  int min = m[0][0];
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (min > m[i][j])
      {
        minN = i;
        min = m[i][j];
      }
    }
  }

  int *temp = m[minN];
  m[minN] = m[0];
  m[0] = temp;
}
