#ifndef _vector_
#define _vector_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class CVector
{
private:
    int N;
    double *px;
public:
    CVector(int n = 1);
    ~CVector();
    void prn();
    void gen();
    double max();
};
#endif // _vector_
