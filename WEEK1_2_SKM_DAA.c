#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compareDesc(const void *a, const void *b) 
{
    return (*(int*)b - *(int*)a);
}
int main() 
{
    int trackingNumbers[100];
    int n = 0,i;
    char input[1000];
    char *token;
    printf("Enter Package Tracking Numbers (comma-separated):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    token = strtok(input, ",");
    while (token != NULL) 
    {
        trackingNumbers[n++] = atoi(token);
        token = strtok(NULL, ",");
    }
    qsort(trackingNumbers, n, sizeof(int), compareDesc);
    printf("After Sorting Package Tracking Numbers:\n");
    for (i = 0; i < n; i++) 
    {
        if (i > 0) printf(",");
        printf("%d", trackingNumbers[i]);
    }
    printf("\n");
    return 0;
}