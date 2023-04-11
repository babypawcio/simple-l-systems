#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void changing(char *algae)
{
    char *supporting_tab = malloc(1000 * sizeof(char));
    int i, j = 0;
    for(i = 0; i < strlen(algae); i++)
    {
        if (algae[i] == 'A')
        {
            supporting_tab[j] = 'A';
            supporting_tab[j+1] = 'B';
            j+=2;
        }
        else if (algae[i] == 'B')
        {
            supporting_tab[j] = 'A';
            j++;
        }
        supporting_tab[j] = '\0';
    }
    strcpy(algae, supporting_tab);
    free(supporting_tab);
}

int main()
{
    char algae[1000] = "A"; // pierwszy elemeent - A 
    int i;
    for(i = 0; i <= 10; i++)
    {
        printf("%d. %s\n", i, algae);
        changing(algae);
    }
    return 0;
}