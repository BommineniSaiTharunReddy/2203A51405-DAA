#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareAsc(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int main() 
{
    int orders[100];
    int n = 0,i;
    char input[1000];
    char *token;
    printf("Enter orders Priority Number (comma-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    token = strtok(input, ",");
    while (token != NULL) 
    {
        orders[n++] = atoi(token);
        token = strtok(NULL, ",");
    }
    qsort(orders, n, sizeof(int), compareAsc);
    printf("After Sorting Orders Priority:\n");
    for (i = 0; i < n; i++) 
    {
        if (i > 0) printf(",");
        printf("%d", orders[i]);
    }
    printf("\n");
    return 0;
}