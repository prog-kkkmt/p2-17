void strcat(chat *to, conts char *from)
{
    while (*to != 0)
    {
        to++;
    }
    do
    {
        *to = *from;
    }
    while(to++, *from++ != 0);
}
