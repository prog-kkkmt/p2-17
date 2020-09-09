void swap_min(int *m[], unsigned rows, unsigned cols)
{
int buf, min = m[0][0];

for (int i = 0; i<rows; i++)
for (int j = 0; j<cols; j++)
if (m[i][j] < min)
{
buf = i;
min = m[i][j];
}
int *buf1 = m[buf];
m[buf] = m[0];
m[0] = buf1;

}
