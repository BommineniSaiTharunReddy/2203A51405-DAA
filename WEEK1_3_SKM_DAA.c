#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareAsc(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int compareDesc(const void *a, const void *b) 
{
    return (*(int*)b - *(int*)a);
}
int main() 
{
    int prices[100];
    int n = 0,i;
    char input[1000];
    char *token;
    char sortOrder;

    printf("Enter Product Prices (comma-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    token = strtok(input, ",");
    while (token != NULL) 
    {
        prices[n++] = atoi(token);
        token = strtok(NULL, ",");
    }
    printf("Enter 'a' for ascending or 'd' for descending order: ");
    scanf(" %c", &sortOrder);
    if (sortOrder == 'a') 
    {
        qsort(prices, n, sizeof(int), compareAsc);
    } 
    else if (sortOrder == 'd') 
    {
        qsort(prices, n, sizeof(int), compareDesc);
    } 
    else 
    {
        printf("Invalid sort order\n");
        return 1;
    }
    printf("After Sorting Product Prices:\n");
    for (i = 0; i < n; i++) 
    {
        if (i > 0) printf(",");
        printf("%d", prices[i]);
    }
    printf("\n");
    return 0;
}
