
#include <stdio.h>
#include <stdlib.h>
int is_alpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}


struct Node
{
    char* word;
    Node* next;
};


void read_file(const char* file)
{
    FILE* fp;
    if ((fp = fopen(file, "r")) == NULL)
    {
        printf("Cannot open file '%s'\n", file);
        exit(1);
    }
  //  List* list = (List*)malloc(sizeof(List));
 //   list->start = NULL;
 //   list->end = NULL;
 //   list->id = id;
    char c = fgetc(fp);
    int len = 0;
    int capacity = 1;
    int first_letter = 1;
    int inserted = 0;
    Node* node = NULL;
    while (c != EOF)
    {
        if (is_alpha(c) && first_letter)
        {
            len = 0;
            capacity = 1;
            inserted = 0;
            node = (Node*)malloc(sizeof(Node));
            node->word = (char*)malloc(sizeof(char));
            node->word[len] = c;
            first_letter = 0;
            len++;
        }
        else if (is_alpha(c) && !first_letter)
        {
            if (len >= capacity)
            {
                capacity *= 2;
                node->word = (char*)realloc(node->word, capacity * sizeof(char));

            }
            node->word[len] = c;
            len++;
        }
        else if (!is_alpha(c) && !first_letter && !inserted)
        {
            if (len >= capacity)
            {
                node->word = (char*)realloc(node->word, capacity + 1);
            }
            node->word[len] = '\0';
            len++;
          //  insert(list, node);
            inserted = 1;
            first_letter = 1;
        }
        c = fgetc(fp);
    }
    fclose(fp);
}
int main()
{
    read_file("C:\\github\\labs\\lab6\\Debug\\one.txt");
}