#include <stdio.h>
#include <string.h>
void hashLinearProbing(char s[], char h1[26][20])
{
    int j = 0;
    while (h1[((s[0] - 'a') % 26) + j][0] != 'A')
    {
        j++;
        if (((s[0] - 'a') % 26) + j >= 26)
            j = -26 + j;
    }
    strcpy(h1[((s[0] - 'a') % 26) + j], s);
}
void hashQuadraticProbing(char s[], char h2[26][20])
{
    int i=0,j = 0;
    while (h2[((s[0] - 'a') % 26) + j][0] != 'A')
    {
        i++;
        j = i * i;
        if (((s[0] - 'a') % 26) + j >= 26)
            j = -26 + j;
    }
    strcpy(h2[((s[0] - 'a') % 26) + j], s);
}
void searchLinearProbing(char q[], char h1[26][20])
{
    int j = 0,c=0;
    while (strcmp(h1[((q[0] - 'a') % 26) + j], q) != 0)
    {
        c++;
        j++;
        if (((q[0] - 'a') % 26) + j >= 26)
            j = -26 + j;
    }
    printf("Element found at position %d\n", ((q[0] - 'a') % 26) + j + 1);
    printf("Number of comparisons: %d", c);
}
void searchQuadraticProbing(char q[], char h2[26][20])
{
    int j = 0,c=0,i=0;
    while (strcmp(h2[((q[0] - 'a') % 26) + j], q)!= 0)
    {
        c++;
        i++;
        j = i * i;
        if (((q[0] - 'a') % 26) + j >= 26)
        {
            j = -26 + j;
        }
    }
    printf("Element found at position %d\n", ((q[0] - 'a') % 26) + j + 1);
    printf("Number of comparisons: %d", c);
}
void main()
{
    int i, j,n;
    char s[20],h1[26][20],word[20],h2[26][20];
    for (i = 0; i < 26; i++)
        for (j = 0; j < 20; j++)//initialisation
        {
            h1[i][j] = 'A';
            h2[i][j] = 'A';
            if (j == 19)
            {
                h1[i][j] = '\0';
                h2[i][j] = '\0';
            }
        }
    printf("Enter number of words\n");
    scanf("%d", &n);
    printf("Enter the words. Must start with a lowercase alphabet\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        hashLinearProbing(s, h1);
        hashQuadraticProbing(s, h2);
    }
    printf("Hash table with linear probing collision resolution:\n");
    for (i = 0; i < 26; i++)
    {
        if (h1[i][0] != 'A')
            printf("%s, ", h1[i]);
        else
            printf(" ");
    }
    printf("\nHash table with quadratic probing collision resolution:\n");
    for (i = 0; i < 26; i++)
    {
        if (h2[i][0] != 'A')
            printf("%s, ", h2[i]);
        else
            printf(" ");
    }
    printf("\nEnter word to search for\n");
    scanf("%s", word);
    printf("In linear probing hash table:\n");
    searchLinearProbing(word, h1);
    printf("In quadratic probing hash table\n");
    searchQuadraticProbing(word, h2);
    printf("\n");
}