#include<stdio.h>
#include"func.h"
int main()
{
    delete_spaces("C:\\github\\labs\\lab 10\\mass.txt");
    List* one = create_list("tmp.txt");
    for (Node* n = one->start; n != NULL; n = n->next)
        printf("Node->word: '%s'\n", n->word);
    delete_list(one);
    return 0;
}