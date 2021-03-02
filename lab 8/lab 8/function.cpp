#include<stdio.h>
#include <stdlib.h>
#include "func.h"
struct Node
	{
		double num;
		Node* prev;
		Node* next;
	};
Answer return_response()
{
		Node* previous = NULL;
		Node* first = NULL;
		Node* last = NULL;
		for (;;)
		{
			double temp;
			int res = scanf("%lf\n", &temp);
			if (res < 1)
			{
				if (last == 0 || first == 0)
				{
					Answer ans;
					ans.index = -1;
					ans.max = 0;
					return ans;
				}
				last->next = first;
				first->prev = last;
				break;
			}
			Node* current = (Node*)malloc(sizeof(Node));
			if (current == 0)
			{
				Answer ans;
				ans.index = -1;
				ans.max = 0;
				return ans;
			}
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
		Answer ans;
		ans.max = 0.0;
		ans.index = 0;
		for (int i = 1;;i++) {
			double a = current->num - current->prev->num;
			double b = current->num - current->next->num;
			double c = a + b;
			if (c > ans.max)
			{
				ans.max = c;
				ans.index = i;
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
		return ans;
}