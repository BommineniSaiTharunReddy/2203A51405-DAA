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
    int times[100];
    int n = 0,i;
    char input[1000];
    char sortOrder;
    printf("Enter times to reach destination (one per line, type 'done' to finish):\n");
    while (1) 
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "done") == 0) break;
        times[n++] = atoi(input);
    }
    printf("Enter 'a' for ascending or 'd' for descending order: ");
    scanf(" %c", &sortOrder);
    if (sortOrder == 'a') 
    {
        qsort(times, n, sizeof(int), compareAsc);
    } 
    else if (sortOrder == 'd') 
    {
        qsort(times, n, sizeof(int), compareDesc);
    }
    else 
    {
        printf("Invalid sort order\n");
        return 1;
    }
    printf("After Sorting times to reach destination:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", times[i]);
    }
    return 0;
}
