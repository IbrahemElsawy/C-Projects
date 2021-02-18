/* Introduction to Programming Using C (IPC144 - NQQ) Final Assessment Part C: stock.h

By: Ibrahem Elsawy

*/


#pragma once // It accepts the compability with other compilers.

#define MAX_ITEM_NAME 31
#define MAX_ITEMS_IN_SALE 30
#define NUM_CATS 7

struct Stock
{
	int amount;
	int category;
	double price;
	int byWeight;
};

struct StockRecord
{
	struct Stock stock;
	char name[MAX_ITEM_NAME + 1];
	double amountSold;
};

struct SalesRecord
{
	int productID;
	double quantity;
	int category;
	char name[31];
};

// The function prototypes for the functions in stock.c

int readStockItems(struct StockRecord storeStock[], int size, int source);

void centreText(int columns, char padding, char text[]);

void printStockReport(struct StockRecord storeStock[], int size);

int readSale(struct StockRecord storeStock[], int size, struct SalesRecord saleItems[]);

double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int size);

void getTopSellers(struct StockRecord storeStock[], int size, struct SalesRecord topSellers[], int topSales, int category);

void printTopSellers(struct StockRecord storeStock[], struct SalesRecord topSellers[], int size, int category);