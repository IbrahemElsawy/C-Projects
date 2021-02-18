/* Introduction to Programming Using C (IPC144NQQ) Final Assessment Part C: stock.c

By: Ibrahem Elsawy

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "stock.h"

#define MAX_STOCK_ENTRIES 100

int readStockItems(struct StockRecord storeStock[], int size, int source)
{
	int i, numStockItems = 0;

	for (i = 0; i < size; i++)
	{
		scanf("%d, %d, %lf, %d, %31[^\n]%*c", &storeStock[i].stock.amount, &storeStock[i].stock.category, &storeStock[i].stock.price, &storeStock[i].stock.byWeight, &storeStock[i].name);

		if (storeStock[i].stock.amount == 0)
		{
			break;
		}
		
		while (!(storeStock[i].stock.category >= 1 && storeStock[i].stock.category <= 7))
		{
			printf("Invalid Category - Enter a number between 1 and 7: ");
			scanf("%d, %lf, %d, %31[^\n]%*c", &storeStock[i].stock.category, &storeStock[i].stock.price, &storeStock[i].stock.byWeight, &storeStock[i].name);
		}

		while (!(storeStock[i].stock.byWeight >= 0 && storeStock[i].stock.byWeight <= 1))
		{
			printf("Invalid soldByWeight - Enter a number between 0 and 1: ");
			scanf("%d, %31[^\n]%*c", &storeStock[i].stock.byWeight, &storeStock[i].name);
		}

		numStockItems++;
	}

	return numStockItems;
}

void centreText(int columns, char padding, char text[])
{
	int i;
	int numPadding = (columns - strlen(text)) / 2;
	numPadding = ((columns - strlen(text)) % 2) > 0 ? numPadding++ : numPadding;

	for (i = 0; i < numPadding; i++)
	{
		printf("%c", padding);
	}
	printf("%s", text);
	for (i = 0; i < numPadding; i++)
	{
		printf("%c", padding);
	}
}

const char* getCatName(int category)
{
	char name[31] = "";

	switch (category)
	{
	case 1:
		strcpy(name, "produce");
		break;
	case 2:
		strcpy(name, "bakery");
		break;
	case 3:
		strcpy(name, "meat");
		break;
	case 4:
		strcpy(name, "dairy");
		break;
	case 5:
		strcpy(name, "baking");
		break;
	case 6:
		strcpy(name, "house wares");
		break;
	default:
		strcpy(name, "miscellaneous");
		break;
	}

	name[strlen(name)] = '\0';

	return name;
}

void printStockReport(struct StockRecord storeStock[], int size)
{
	int i;
	char category[31] = "";

	printf("ID                        Product        Category   Price Quantity\n");

	for (i = 0; i < size; i++)
	{
		strcpy(category, getCatName(storeStock[i].stock.category));
		printf("%d		%s			%s		%.2lf	%d\n", i + 1, storeStock[i].name, category, storeStock[i].stock.price, storeStock[i].stock.amount - (int)storeStock[i].amountSold);
	}
}

int readSale(struct StockRecord storeStock[], int numStockItems, struct SalesRecord saleItems[])
{
	int productID = 1, counter = 0;
	double quantity;

	while (productID != 0)
	{
		printf("Enter a product ID to purchase, and the quantity (0 to stop): ");
		scanf("%d, %lf", &productID, &quantity);

		while (productID < 0 || productID > numStockItems)
		{
			printf("Invalid Product - Enter a number between 0 and %d: ", numStockItems);
			scanf("%d, %lf", &productID, &quantity);
		}
		
		if (productID == 0)
		{
			break;
		}

		while (quantity < 0.10 || quantity > 100)
		{
			printf("Invalid quantity - Enter a number between 0.10 and 100.00: ");
			scanf("%d, %lf", &productID, &quantity);
		}

		if (quantity > storeStock[productID - 1].stock.amount)
		{
			quantity = storeStock[productID - 1].stock.amount;
		}

		storeStock[productID - 1].amountSold += quantity; 
		saleItems[counter].productID = productID -1;
		saleItems[counter].quantity = (double)quantity;
		saleItems[counter].category = storeStock[productID - 1].stock.category;

		counter++;
	}

	return counter;
}

double printSalesReport(struct StockRecord storeStock[], struct SalesRecord saleItems[], int size)
{
	int i;
	double price, totalPerItem, subTotal = 0.0, tax = 0.0, totalSales = 0.0;
	char name[31] = "";

	printf("*********************** Seneca Groceries ***********************\n");
	printf("================================================================\n");

	for (i =0; i < size; i++)
	{
		strcpy(name, storeStock[saleItems[i].productID].name);
		price = storeStock[saleItems[i].productID].stock.price;
		totalPerItem = saleItems[i].quantity * price;
		subTotal += totalPerItem;
		if (saleItems[i].category == 6 || saleItems[i].category == 7)
		{
			tax += totalPerItem * .13;
		}
		
		printf("%23s %5.2lf %.2lf\n", name, price, totalPerItem);
	}

	totalSales = subTotal + tax;

	printf("Purchase Total		%.2lf\n", subTotal);
	printf("Tax			%.2lf\n", tax);
	printf("Total			%.2lf\n", totalSales);
	printf("Thank you for shopping at Seneca!\n\n");

	return subTotal;
}

/*void swapRecords(struct SalesRecord record1, struct SalesRecord record2)
{

}*/

void getTopSellers(struct StockRecord storeStock[], int size, struct SalesRecord topSellers[], int topSales, int category)
{
	int i, j, topSellersSize = 0, numPasses = 0;
	struct SalesRecord tempRecord;

	for (i = 0; i < size; i++)
	{
		if (category + 1 == storeStock[i].stock.category && storeStock[i].amountSold > 0)
		{
			topSellers[topSellersSize].productID = i + 1;
			topSellers[topSellersSize].quantity = storeStock[i].amountSold;
			topSellers[topSellersSize].category = category + 1;
			strcpy(topSellers[topSellersSize].name, storeStock[i].name);
			topSellersSize++;
		}
	}

	for (i = 1; i < topSellersSize; i++)
	{
		for (j = 0; j < topSellersSize - 1; j++)
		{
			if (topSellers[j].quantity < topSellers[j+1].quantity)
			{
				tempRecord = topSellers[j];
				topSellers[j] = topSellers[j+1];
				topSellers[j + 1] = tempRecord;
			}
		}
	}
}

void printTopSellers(struct StockRecord storeStock[], struct SalesRecord topSellers[], int size, int category)
{
	int i = 0;
	char cat[31] = "";

	printf("------------ Top %d sellers in %s ------------\n", size, strcpy(cat, getCatName(category+1)));
	printf("Rank                       Product   Sales\n");
	for (i = 0; i < size; i++)
	{
		if (category + 1 == topSellers[i].category)
		{
			printf("%d		%s	%.2lf\n", i + 1, topSellers[i].name, topSellers[i].quantity);
		}
		else
		{
			printf("%d		<none>		0.00\n", i + 1);
		}
	}
	
}