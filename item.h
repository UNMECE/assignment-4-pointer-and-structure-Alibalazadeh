#ifndef _ITEM
#define _ITEM
struct _Item
{
	double price;
	char *SKU;
	char *name;
	char *category;
};
typedef struct _Item Item;
void add_item(Item *item_list, double price, char *SKU, char *category, char *name, int index);

#endif 


