#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"func.h"
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Filename is not set\nCorrect input for example: %s input_file", argv[0]);
        exit(1);
    }
    char* mass_txt = argv[1];
    FILE* fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("The file %s was not detected", argv[1]);
        exit(1);
    }
    delete_spaces(mass_txt);
    List* one = create_list("tmp.txt");
    for (Node* n = one->start; n != NULL; n = n->next)
        printf("Node->word: '%s' \n", n->word);
    delete_list(one);
    return 0;
}

