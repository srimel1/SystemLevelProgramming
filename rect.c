#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point upper_left;
    struct point lower_right;
};

int area(struct rectangle rect);
struct point center(struct rectangle rect);

int main(void)
{
    struct rectangle r;
    struct point centerP, pointQ;

    r.upper_left.x = 1;
    r.upper_left.y = 4;

    r.lower_right.x = 7;
    r.lower_right.y = 1;

    printf("The area of the rectangle is %d\n", area(r));

    
}

int area(struct rectangle r)
{
    int area, length, width;
    area = length = width = 0;

    width = r.upper_left.y - r.lower_right.y;
    length = r.lower_right.x - r.upper_left.x;

    area = length * width;

    return area;
}
