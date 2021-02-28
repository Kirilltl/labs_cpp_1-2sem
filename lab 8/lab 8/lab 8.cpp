#include<stdio.h>
#include <stdlib.h>
struct Node
{
	float num;
	Node* prev;
	Node* next;
};
int main() {

	Node* previous = NULL;
	Node* first = NULL;
	Node* last = NULL;
	for (;;) {
		double temp;
		int res = scanf("%lf\n", &temp);
		if (res < 1) {
			last->next = first;
			first->prev = last;
			break;
		}

		Node* current = (Node*)malloc(sizeof(Node));
		current->num = temp;
		
		if(first==NULL)
			first = current;

		if (previous != NULL) {

			previous->next = current;
			current->prev = previous;
		}
		
		previous = current;
		last = current;
	}

	//printf("IN DYNAMIC MEMORY:\n");


	Node* current = first;
	double max = 0.0;
	int index = 0;
	for (int i=1;;i++) {


		double a = current->num - current->prev->num;
		double b = current->num - current->next->num;
		double c = a + b;
		if (c > max)
		{
			max = c;
			index = i;
		}

	//	printf("%lf\n", current->num);

		if (current == last)
			break;


		current = current->next;
	}


	printf("Nomer elementa = %d\n",index);
	printf("MAx. summa raznostej = %lf\n", max);

	current = first;
	for (;;) {
		Node* to_free = current;
		
		if (current == last) {
			printf("free %lf\n", current->num);
			free(current);
			break;
		}

		current = current->next;

		printf("free %lf\n", to_free->num);
		free(to_free);
		
	}

	
}