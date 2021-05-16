#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.h"
int is_alpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '[') || (ch == ']') || (ch >= '0' && ch <= '9'));
}
void insert(List* list, Node* node)
{
    for (unsigned int i = 0; i < strlen(node->word); i++)
        if (node->word[i] == '[')
        {
            node->word[i] = '\0';
            break;
        }
    if (!list->end)
    {
        node->next = NULL;
        list->end = node;
        list->start = node;
        return;
    }
    Node* prev = NULL;
    Node* n = list->start;
    while (n != NULL)
    {
        int c = strcmp(n->word, node->word);
        if (c < 0)
        {
            prev = n;
            n = n->next;
        }
        else if (c == 0)
        {
            return;
        }
        else
        {
            if (prev != NULL) {
                prev->next = node;
                node->next = n;
                return;
            }
            node->next = n;
            list->start = node;
            return;
        }
    }
    list->end->next = node;
    node->next = NULL;
    list->end = node;
}
int count_stars(char* word)
{
    int count = 0;
    for (unsigned int i = 0; i < strlen(word); i++)
        if (word[i] == '*')
            count++;
    if (count >= 2)
        return 1;
    else
        return 0;
}
int double_quotes(char* word)
{
    int counter = 0;
    for (unsigned int i = 0; i < strlen(word); i++)
        if (word[i] == '[' || word[i] == ']')
            counter++;
    if (counter >= 4)
        return 1;
    else
        return 0;
}
void delete_spaces(const char* file)
{
    FILE* fp;
    if ((fp = fopen(file, "r")) == NULL)
    {
        exit(1);
    }
    FILE* fp2;
    if ((fp2 = fopen("tmp.txt", "w")) == NULL)
    {
        exit(1);
    }
    char c = fgetc(fp);
    int flag = 0;
    while (c != EOF)
    {
        c = fgetc(fp);
        if (flag == 0)
        {
            if (c == ' ')
            {
                flag = 1;
            }
            else
            {
                fputc(c, fp2);
            }
        }
        else  
        {
            if (c == ' ')
            {
                flag = 1;
            }
            else
            {
                if (c == '[' || c == ']')
                {
                    fputc(c, fp2);
                    flag = 0;
                }
                else
                {
                    fputc(' ', fp2);
                    fputc(c, fp2);
                    flag = 0;
                }
            }
        }
    }
    fclose(fp);
    fclose(fp2);
}
    List* create_list(const char* file)
    {
        FILE* fp;
        if ((fp = fopen(file, "r")) == NULL)
        {
            exit(1);
        }
        List* list = (List*)malloc(sizeof(List));
        if (list == NULL)
            exit(1);
        list->start = NULL;
        list->end = NULL;
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
                if (node == NULL)
                    exit(1);
                node->word = (char*)malloc(sizeof(char));
                if (node->word == NULL)
                    exit(1);
                node->word[len] = c;
                first_letter = 0;
                len++;
            }
            else if (is_alpha(c) && !first_letter)
            {
                if (len >= capacity)
                {
                    capacity *= 2;
                    char* tmpp = (char*)realloc(node->word, capacity * sizeof(char));
                    if (tmpp == NULL) 
                    {
                        free(node->word);
                        return NULL;
                    }
                    else 
                    {
                        node->word = tmpp;
                    }
                }
                node->word[len] = c;
                len++;
            }
            else if (!is_alpha(c) && !first_letter && !inserted)
            {
                if (len >= capacity)
                {
                    char* tmpp = (char*)realloc(node->word, capacity + 1);
                    if (tmpp == NULL) 
                    {
                        free(node->word);
                        return NULL;
                    }
                    else 
                    {
                        node->word = tmpp;
                    }
                }
                node->word[len] = '\0';
                len++;
                if ((double_quotes(node->word)) || (count_stars(node->word)))
                    insert(list, node);
                inserted = 1;
                first_letter = 1;
            }
            c = fgetc(fp);
        }
        fclose(fp);
        return list;
    }
    void delete_list(List * list)
    {
        Node* n = list->start;
        while (n != NULL)
        {
            Node* node = n;
            n = n->next;
            free(node->word);
            free(node);
        }
        free(list);
    }






                


    