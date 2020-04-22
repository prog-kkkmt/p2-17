int strstr(const char *text, const char *pattern)
{
    const char *i = text, *p = pattern;
    for (; *i && *p; ++i) {
        if (*i != *p) 
            p = pattern;
        if (*i == *p) 
            ++p;
    }
    return *p ? -1 : (i - text) - (p - pattern);
}
