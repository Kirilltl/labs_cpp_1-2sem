#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "func.h"

int is_alpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}
void insert(List* list, Node* node)
{
    if (!list->end)
    {
        node->next = NULL;
        node->prev = NULL;
        list->end = node;
        list->start = node;
        return;
    }
    list->end->next = node;
    node->prev = list->end;
    node->next = NULL;
    list->end = node;
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
    int flag_space = 0;
    int flag_star = 0;
    while (c != EOF)
    {
        c = fgetc(fp);
        if (flag_space == 0)
        {
            if (c == ' ')
            {
                flag_space = 1;
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
                flag_space = 1;
            }
            else
            {
                if (c == '[' || c == ']')
                {
                    fputc(c, fp2);
                    flag_space = 0;
                }
                else
                {
                    fputc(' ', fp2);
                    fputc(c, fp2);
                    flag_space = 0;
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
            insert(list, node);
            inserted = 1;
            first_letter = 1;
        }
        c = fgetc(fp);
    }
    fclose(fp);
    return list;
}
void delete_list(List* list)
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
void check_list(List* list)
{
    for (Node* node = list->start; node != NULL; node = node->next)
    {
        if (node->prev == NULL || node->next == NULL)
            continue;
        if (strlen(node->word) > strlen(node->prev->word) &&
            strlen(node->word) > strlen(node->next->word))
            printf("result: %s \n", node->word);
    }
}