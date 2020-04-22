int strstr(const char *text, const char *pattern)
{
    int i=0,j=0;
    if (*pattern=='\0')
    return 0;
    while (text[i] !='\0')
    {
        j=0;
        while (text[i+j]==pattern[j])
        {
                j++;
                if (pattern[j]=='\0')
                return i;               
            }
            
        
        i++;
    }
    return -1;
}