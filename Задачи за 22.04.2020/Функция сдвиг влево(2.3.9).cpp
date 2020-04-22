void rotate(int * m, unsigned n, int sdvig)
{
sdvig = sdvig % int(n);

    if(sdvig)
        {
        sdvig = sdvig > 0 ? sdvig : n + sdvig;

        int * a = m;
        int * b = m + n - 1;
        while(a < b)
            {
            int c = *a;
            *a++ = *b;
            *b-- = c;
            }

        a = m;
        b = m + n-1-sdvig;
        while(a < b)
            {
            int c = *a;
            *a++ = *b;
            *b-- = c;
            }

        a = m + n - sdvig;
        b = m + n - 1;
        while(a < b)
            {
            int c = *a;
            *a++ = *b;
            *b-- = c;
            }
    }
}
