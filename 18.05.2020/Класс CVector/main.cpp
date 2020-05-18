#include "vector.h"
int main()
{
    srand(time(NULL));
    CVector massiv(3);
    massiv.gen();
    massiv.prn();
    printf("Max = %3.2lf\n", massiv.max());
}
