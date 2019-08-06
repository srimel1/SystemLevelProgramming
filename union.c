#include <stdio.h>

struct catalog_item
{
    int number;
    float price;
    int item_type;
    union
    {
        /* data */
        struct{
            char title[TITLE_LENGTH+1];
            char author[AUTHOR_LEN+1];
            int num_pages;
        }book;
        struct{
            char design[DESIGN_LEN+1];
        }mug;
        struct{
            char design[DESIGN_LEN+1];
            int colors;
            int sizes;
        }shirt;
    }item;
    
};

int main()
{


}