#include "vector.h"
CVector::CVector(int n)
{
    N = n;
    px = new double [N];
}
CVector::~CVector()
{
    delete [] px;
}
void CVector::gen()
{
    for(int i = 0; i < N; i++)
    {
        px[i] = double(rand()) / RAND_MAX * 5;
    }
}
void CVector::prn()
{
    for(int i = 0; i < N; i++)
    {
        printf("%3.2lf\t", px[i]);
    }
    printf("\n");
}
double CVector::max()
{
    double M;
    int i;
    M = *px;
    for(i = 1; i < N; i++)
    {
        if(px[i] > M)
            M = px[i];
    }
    return M;
}
