#include <stdio.h>
#include <string.h>

#define NAME_LEN 100

struct
{
    /* members of part */
    int number;
    char name[NAME_LEN + 1];
    int onHand;
} part1, part2; //variables



int main()
{
    int i, p;
    /* structures as arrays */
    struct part inventory[100];
   
    inventory[1].name = "top";
    inventory[2].name = "leggings";
    inventory[3].name = "earrings";
    inventory[4].name = "skirts";
    inventory[5].name = "jeans";
    inventory[6].name = "heels";
    inventory[7].name = "trainers";
    inventory[8].name = "trowsers";
    inventory[9].name = "bras";
    inventory[10].name = "corsets";
    inventory[0].name = "trainers";

     for(i = 0; i < 10; i++){
        inventory[i].number = i;
    }

    for(i = 0; i < 10; i++){
        printf("Inventory number: %d\n", inventory[i].number);
        printf("Inventory name: %s", inventory[i].name);
    }
    printf("Part number : %d \n", part1.number);


    part1.number = 123;
    part1.onHand++;

    scanf("%d", &part1.onHand);

    part1 = part2; // members in part 1 and part 2 have same value

}
/* declaring a structure tag */
struct part
{
    int number;
    char name[NAME_LEN + 1];
    int onHand;
}; struct part part5, part6;

/* declaring a structure type */
typedef struct 
{
    /* data */
    int number;
    char name[NAME_LEN + 1];
} Part;
Part part3, part4;

/* pass by values */
void print_part (struct part p)
{
    printf("Part number: %d\n", p.number);
}

/* pass by addresses */
/* for pointers to a structure use -> 
access members instead of '.' */
void update_part(struct part *p)
{
    p->number = 124;
}

/* structs as return values */
// struct part build_part(int number, const char *name, int on_hand)
// {
//     stuct part p;
//     p.number = number;
//     strcpy(p.name, name);
//     p.on_hand = on_hand;
//     return p;
// }
