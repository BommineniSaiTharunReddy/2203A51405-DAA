#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareAsc(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}
int main() 
{
    int productIds[100]; 
    int n = 0,i;
    char input[1000];
    char *token;
    printf("Enter Product IDs (comma-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    token = strtok(input, ",");
    while (token != NULL) 
    {
        productIds[n++] = atoi(token);
        token = strtok(NULL, ",");
    }
    qsort(productIds, n, sizeof(int), compareAsc);
    printf("After Sorting Product IDs:\n");
    for (i = 0; i < n; i++) 
    {
        if (i > 0) printf(",");
        printf("%d", productIds[i]);
    }
    printf("\n");
    return 0;
}