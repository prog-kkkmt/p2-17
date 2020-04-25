/** Нахождение максимального */
int max(int a[], int n)
{
    int i = 0;
    int Max = a[i];
    for (i = 1; i < n; i++)
        if (a[i] > Max)
            Max = a[i];
    return Max;
}

