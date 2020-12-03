#include<stdio.h>

struct Contact
{
	int name;
	int number;
	int id;
	Contact* next;
};



int main()
{
	Contact one;
	one.id = 1;
	one.name = 11;
	one.number = 111;


	Contact two;
	two.id = 2;
	two.name = 22;
	two.number = 222;

	one.next = &two;
	printf("%d %d %d %p\n", one.next->name, one.next->number, one.next->id, one.next->next);

}