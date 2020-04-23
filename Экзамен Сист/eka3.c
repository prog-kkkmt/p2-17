#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct msh
{
char nom[10];
char name[20];
int count;
};

void zap(struct msh *c, int n)
{
    FILE *file;
    file = fopen("output.txt", "w");
    int max = c[0].count;
    for(int i = 1; i < n; i++)
        if(max < c[i].count)
            max = c[i].count;
    char str[50];
    strcpy(str, c[0].name);
    for(int i = 0; i < n; i++)
        if(max == c[i].count)
        {
            if(strcmp (str, c[i].name))
                fprintf(file, "%s \n", c[i].name);
            strcpy(str, c[i].name);
        }
    fclose(file);
}

int main()
{
        int n = 1;
        struct msh c[100];
        FILE *f;
        f = fopen("input.txt", "r");
        int i = 0;
        while(fscanf(f,"%s %s %d", c[i].nom, c[i].name, &(c[i].count)) != EOF)
        {
            i++;
            n = i;
        }
        fclose(f);
        for(int j = 0; j < n; j++)
                printf("%s %s %d \n", c[j].nom, c[j].name, c[j].count);
        zap(c, n);
        return 0;
}
