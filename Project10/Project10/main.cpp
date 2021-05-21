//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include"func.h"
//int main(int argc, char* argv[])
//{
//    if (argc != 3)
//    {
//        printf("Filename is not set,\nCorrect input for example: %s , input_file", argv[0]);
//        return 1;
//    }
//    char* mass_txt = argv[1];
//    delete_spaces(mass_txt);
//    List* one = create_list("tmp.txt");
//    for (Node* n = one->start; n != NULL; n = n->next)
//        printf("Node->word: '%s' \n", n->word);
//    delete_list(one);
//    return 0;
//}

#include<stdio.h>
#include"func.h"
int main()
{
    delete_spaces("C:\\github\\labs\\Project10\\mass.txt");
    List* one = create_list("tmp.txt");
    for (Node* n = one->start; n != NULL; n = n->next)
        printf("Node->word: '%s' \n", n->word);
    delete_list(one);
    return 0;
}