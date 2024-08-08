#include<stdio.h>
#include<string.h>
#define MAX_BOOKS 100
typedef struct{
    char title[100];
    char author[100];
    int pub_year;
    float price;
}Book;
void swap(Book *a, Book *b)
{
    Book temp = *a;
    *a = *b;
    *b = temp;
}
void sort(Book books[],int count,int ascending)
{
    for(int i = 0;i<count - 1;i++)
    {
        for(int j = i + 1;j<count;j++)
        {
            if((ascending && books[i].price > books[j].price) || (!ascending && books[i].price < books[j].price))
            {
                swap(&books[i], &books[j]);
            }
        }
    }
}
void search_sort(Book books[],int totalBooks, char* searchTitle, int ascending)
{
    Book results[MAX_BOOKS];
    int count = 0;
    for(int i = 0;i<totalBooks;i++)
    {
        if(strstr(books[i].title,searchTitle))
        {
            results[count++] = books[i];
        }
    }
    sort(results,count,ascending);
    for(int i = 0;i<count;i++)
    {
        printf("Title: %s,Author: %s,year: %d,price: $%.2f\n",results[i].title,results[i].author,results[i].pub_year,results[i].price);
    }
    if(count==0)
    {
        printf("No books found with the title '%s'.\n",searchTitle);
    }
}
int main()
{
    Book books[MAX_BOOKS] = {
        {"Godan", "Munshi Premchand", 1936, 10.99},
        {"Malgudi Days", "R.K. Narayan", 1943, 8.99},
        {"The Guide", "R.K. Narayan", 1958, 12.50},
        {"Gitanjali", "Rabindranath Tagore", 1910, 9.99},
        {"Train to Pakistan", "Khushwant Singh", 1956, 15.99}
    };
    char searchTitle[100];
    int ascending;
    printf("Enter the title to search: ");
    fgets(searchTitle,100,stdin);
    searchTitle[strcspn(searchTitle,"\n")]=0;
    printf("Sort by price (1: Low to High, 0: Hight to Low): ");
    scanf("%d",&ascending);
    search_sort(books, 5, searchTitle,ascending);
    return 0;
}