#include <stdio.h>
int main()
{
	printf("%s", c.item.book.title);
}
struct catalog_item {
	  int stock_number;
	  double price;
	  int item_type;
	union
	{
		struct
		{
			char title[TITLE_LEN+1];
			char author[AUTHOR_LEN+1];
			int num_pages;
		}book;
		struct
		{
			char design[DESIGN_LEN+1];
		}mug;
		struct
		{
			char design[DESIGN_LEN+1];
			int colors;
			int sizes;
		}shirt;
	}item;
};
	
