#include <stdio.h>

struct student
{
    char name[40];
    int id;
    float grade;
}
struct Student s[10];

// setting up rules for comparison 
// to sort the students based on names 
int comparator(const void* p, const void* q) 
{ 
    return strcmp(((struct Student*)p)->name, 
                  ((struct Student*)q)->name); 
} 
int main()
{
    int N, *i = 0;
    

    /* get data */
    printf("Enter data....");
    for(i = 0; i < N; i++)
    {
        s[i].roll = i + 1;
        printf("Student number: %d", i);
        printf("Enter name: ");
        scanf("\n%s", &s[i].name);

        printf("Enter id: ");
        scanf("\n%d", &s[i].id);

        printf("Enter grade: ");
        scanf("\n%lf", &s[i].grade);
    }

    /* Display data */
    for(i = 0; i < N; i++)
    {
        printf("Student number: %d", i + 1);
        printf("Name: ");
        puts(s[i].name);
        printf("\nID: %d", s[i].id);
        printf("\nGrade: %lf", s[i].grade);

    }
}