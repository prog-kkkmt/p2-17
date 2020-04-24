char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *ns = new char [new_size];
    int i = 0;
    while (i<size && i<new_size)
    {
        ns[i] = str[i];
        i++;
    }
    delete[] str;
    return(ns);
}
