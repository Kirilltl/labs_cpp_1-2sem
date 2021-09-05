#ifndef _FUNC_H_
#define _FUNC_H_
struct Node
{
    char* word;
    Node* next;
    Node* prev;
};
struct List
{
    Node* start;
    Node* end;
};
List* create_list(const char* file);
void delete_list(List* list);
void delete_spaces(const char* file);
void check_list(List* list);
#endif
