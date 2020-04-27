char *resize(char const *str, unsigned size, unsigned new_size)
{
    char *str2 = new char[new_size];

    for(int i = 0; i < new_size; i++)
    {
        str2[i] = str[i];
    }
    delete [] str;
    return str2;
}
