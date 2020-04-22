void strcat(char *to, const char *from)
{
  for (; *to; to++);
      for (; *from != '\0';)
        *to++ = *from++;
  *to++ = '\0';
}
