#include<stdio.h>

struct first
{
int number;
char name[20];
int on_hand;
}
a={20,"Disk Drive",15},
b={.number=23, .name="CD", .on_hand=5},
c={.name="Floppy", .on_hand=7},
d={.number=23, "Hard Disk", .on_hand=5};

struct
{
int number;
char ID;
float course_grade;
}student1,student2;

void main(){

    printf("a.number = %d\n",a.number);
    printf("a.name = %s\n",a.name);
    printf("a.on_hand = %d\n",a.on_hand);
printf("\n");
    a.number++;
    printf("a.number++ = %d\n",a.number);
printf("\n");
    printf("b.number = %d\n",b.number);
    printf("b.name = %s\n",b.name);
    printf("b.on_hand = %d\n",b.on_hand);
printf("\n");
    printf("c.number = %d\n",c.number);
    printf("c.name = %s\n",c.name);
    printf("c.on_hand = %d\n",c.on_hand);
printf("\n");
    printf("d.number = %d\n",d.number);
    printf("d.name = %s\n",d.name);
    printf("d.on_hand = %d\n",d.on_hand);
printf("\n");
    //doesnt work here only in struct
    printf("Enter Value for a.number: ");
    scanf(" %d", &a.name);
    printf("a.number = %d\n",a.number);


/*
    struct NAME{
        int number;
        char name[10];
        int on_hand;
        part1, part2, x,y,a,b;
        }
        */
}
