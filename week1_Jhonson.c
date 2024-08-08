#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

typedef struct {
    char destination[50];
    int packageID;
} Package;

typedef struct {
    int productID;
    char productName[50];
} Product;

typedef struct {
    int orderID;
    int priority;
    char customerName[50];
} Order;

void swapPackages(Package *a, Package *b) {
    Package temp = *a;
    *a = *b;
    *b = temp;
}

void swapProducts(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

void swapOrders(Order *a, Order *b) {
    Order temp = *a;
    *a = *b;
    *b = temp;
}

void sortPackages(Package packages[], int count) 
{
    int i,j;
    for (i = 0; i < count - 1; i++) 
    {
        for( j = i + 1; j < count; j++) 
        {
            if (strcmp(packages[i].destination, packages[j].destination) > 0) 
            {
                swapPackages(&packages[i], &packages[j]);
            }
        }
    }
}

void sortProducts(Product products[], int count) 
{
    int i,j;
    for (i = 0; i < count - 1; i++) 
    {
        for (j = i + 1; j < count; j++) 
        {
            if (products[i].productID > products[j].productID) 
            {
                swapProducts(&products[i], &products[j]);
            }
        }
    }
}
void sortOrders(Order orders[], int count) 
{
    int i,j;
    for  (i = 0; i < count - 1; i++) 
    {
        for (j = i + 1; j < count; j++) 
        {
            if (orders[i].priority > orders[j].priority) 
            {
                swapOrders(&orders[i], &orders[j]);
            }
        }
    }
}
void searchSortPackages(Package packages[], int totalPackages, char *searchDestination) 
{
    Package results[MAX_PACKAGES];
    int count = 0,i;
    for (i = 0; i < totalPackages; i++) 
    {
        if (strstr(packages[i].destination, searchDestination)) 
        {
            results[count++] = packages[i];
        }
    }
    sortPackages(results, count);
    for (i = 0; i < count; i++) 
    {
        printf("Package ID: %d, Destination: %s\n", results[i].packageID, results[i].destination);
    }
    if (count == 0) 
    {
        printf("No packages found with the destination '%s'.\n", searchDestination);
    }
}

void searchSortProducts(Product products[], int totalProducts, int minProductID, int ascending) 
{
    Product results[MAX_PRODUCTS];
    int count = 0,i;
    for (i = 0; i < totalProducts; i++) 
    {
        if (products[i].productID >= minProductID) 
        {
            results[count++] = products[i];
        }
    }
    sortProducts(results, count);
    if (!ascending) 
    {
        for (i = 0; i < count / 2; i++) 
        {
            swapProducts(&results[i], &results[count - 1 - i]);
        }
    }
    for (i = 0; i < count; i++) 
    {
        printf("Product ID: %d, Product Name: %s\n", results[i].productID, results[i].productName);
    }
    if (count == 0) 
    {
        printf("No products found with Product ID >= %d.\n", minProductID);
    }
}
void searchSortOrders(Order orders[], int totalOrders, int minPriority) 
{
    Order results[MAX_ORDERS];
    int count = 0,i;
    for (i = 0; i < totalOrders; i++) 
    {
        if (orders[i].priority >= minPriority) 
        {
            results[count++] = orders[i];
        }
    }
    sortOrders(results, count);
    for (int i = 0; i < count; i++) 
    {
        printf("Order ID: %d, Customer Name: %s, Priority: %d\n", results[i].orderID, results[i].customerName, results[i].priority);
    }
    if (count == 0) 
    {
        printf("No orders found with Priority >= %d.\n", minPriority);
    }
}
int main() 
{
    Package packages[MAX_PACKAGES] = {
        {"Mumbai", 101},
        {"Delhi", 102},
        {"Bangalore", 103}
    };

    Product products[MAX_PRODUCTS] = {
        {3, "Laptop"},
        {1, "Smartphone"},
        {2, "Tablet"}
    };

    Order orders[MAX_ORDERS] = {
        {501, 2, "Rahul Sharma"},
        {502, 1, "Priya Verma"},
        {503, 3, "Amit Kumar"}
    };

    char searchDestination[50];
    printf("Enter destination to search: ");
    fgets(searchDestination, 50, stdin);
    searchDestination[strcspn(searchDestination, "\n")] = 0;
    searchSortPackages(packages, 3, searchDestination);
    int minProductID;
    int ascending;
    printf("\nEnter minimum Product ID to search: ");
    scanf("%d", &minProductID);
    printf("Sort by Product ID (1: Ascending, 0: Descending): ");
    scanf("%d", &ascending);
    searchSortProducts(products, 3, minProductID, ascending);
    int minPriority;
    printf("\nEnter minimum Priority to search: ");
    scanf("%d", &minPriority);
    searchSortOrders(orders, 3, minPriority);

    return 0;
}
