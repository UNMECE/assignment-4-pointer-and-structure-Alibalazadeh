#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void add_item(Item *item_list, double price, char *SKU, char *category, char *name, int index)
{
	if(index >= 0 && index < 2){

		item_list[index].SKU = (char *)malloc(sizeof(char) * strlen(SKU));
		item_list[index].name = (char *)malloc(sizeof(char) * strlen(name));
		item_list[index].category = (char *)malloc(sizeof(char) * strlen(category));
		//item_list[index].price = (char *)malloc(sizeof(char) * strlen(price));

		item_list[index].price = price;
		strcpy(item_list[index].SKU, SKU);
		strcpy(item_list[index].name, name);
		strcpy(item_list[index].category, category);
	}
}

//free
void free_items(Item *item_list, int size)
{
	for(int i =0; i<size; i++)
	{	
		free(item_list[i].SKU);
		free(item_list[i].name);
		free(item_list[i].category);
	}
		free(item_list);		
}

//double
double  average_price(Item *item_list, int size)
{
	double sum =0;
	double average = 0;
	for(int i = 0; i <size; i++)
	{
		sum+= item_list[i].price;
	}
		average = sum /size;
		printf("average of price :%f\n",average);
		return average;
}


void print_items(Item *item_list, int size)
{
	for (int i=0; i<size; i++)
	{
		printf("Item: %d\n", i+1);
		printf("name: %s\n", item_list[i].name);
		printf("category: %s\n", item_list[i].category);
		printf("SKU: %s\n", item_list[i].SKU);
		printf("price: %f\n", item_list[i].price);
	}

}
 //function that searches for a SKU
 void find_SKU(Item * item_list, char *query, int size)
 {
	int ct =0;
	while(ct <size && strcmp(item_list[ct].SKU, query) !=0)
		{
			ct ++;
		}
	if (ct>=size)
		{
			printf("item SKU %s not found\n", query);
		}
	else 
		{
			printf("found item for SKU %s\n", query);
			printf("item SKU %s\n", item_list[ct].SKU);
			printf("item category %s\n", item_list[ct].category);
			printf("item name %s\n", item_list[ct].name);
			printf("item price %s\n", item_list[ct].price);
		}

}



//main function
int main(int argc, char *argv[]){
	int num_items = 2;
	int index;

	Item *item_list = (Item *)malloc(sizeof(Item)* num_items);
	
	add_item(item_list, 1.99, "234", "fruit", "apple", index);
	index ++;

	add_item(item_list, 2.5, "345", "seafood", "salmon", index);
	index ++;

	print_items(item_list, num_items);
	average_price(item_list, num_items);
	free_items(item_list, num_items);


return 0;
}
