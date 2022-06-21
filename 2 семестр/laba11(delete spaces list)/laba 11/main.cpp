#include<stdio.h>
#include "func.h"
int main()
{
    delete_spaces("C:\\github\\labs\\laba 11\\laba 11\\one.txt");
    List* one = create_list("tmp.txt");
    for (Node* n = one->start; n != NULL; n = n->next)
        printf("Node->word: '%s'\n", n->word);
    check_list(one);
    delete_list(one);
    return 0;
}








