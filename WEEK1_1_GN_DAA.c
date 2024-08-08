#include <stdio.h>
#include <stdlib.h>
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
    int times[4];
    int i;
    char sortType;
    printf("Enter time to reach destination:\n");
    for (i = 0; i < 4; i++) 
    {
        scanf("%d", &times[i]);
    }
    printf("Enter 'a' for ascending or 'd' for descending order: ");
    scanf(" %c", &sortType);
    if (sortType == 'a') 
    {
        qsort(times, 4, sizeof(int), compareAsc);
    } 
    else if (sortType == 'd') 
    {
        qsort(times, 4, sizeof(int), compareDesc);
    } 
    else 
    {
        printf("Invalid sort type\n");
        return 1;
    }
    printf("OUTPUT:\n");
    for (i = 0; i < 4; i++) 
    {
        printf("%d\n", times[i]);
    }
    return 0;
}