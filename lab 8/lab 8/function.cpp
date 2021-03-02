#include<stdio.h>
#include <stdlib.h>
int check(double a,double b,double c)
{
		struct Node
		{
			float num;
			Node* prev;
			Node* next;
		};
		Node* previous = NULL;
		Node* first = NULL;
		Node* last = NULL;
		for (;;)
		{
			double temp;
			int res = scanf("%lf\n", &temp);
			if (res < 1)
			{
				last->next = first;
				first->prev = last;
				break;
			}
			Node* current = (Node*)malloc(sizeof(Node));
			current->num = temp;
			if (first == NULL)
				first = current;
			if (previous != NULL)
			{
				previous->next = current;
				current->prev = previous;
			}
			previous = current;
			last = current;
		}
		Node* current = first;
		double max = 0.0;
		int index = 0;
		for (int i = 1;;i++) 
		{
			double a = current->num - current->prev->num;
			double b = current->num - current->next->num;
			double c = a + b;
			if (c > max)
			{
				return 1;
				max = c;
				index = i;
			}
			if (current == last)
				break;
			current = current->next;
		}
		current = first;
		for (;;)
		{
			Node* to_free = current;
			if (current == last)
			{
				free(current);
				break;
			}
			current = current->next;
			free(to_free);
		}
		
}