#include<stdio.h>
#include<stdlib.h>
int is_alpha(char ch)
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
int comparesl(char* s1, char* s2)
{
    while (1)
    {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 == '\0' || c2 == '\0')
            return c1 - c2;
        if (c1 != c2)
            return c1 - c2;
        *s1++;
        *s2++;
    }
}
struct Node
{
    char* word;  
    Node* next;  
};
struct List
{
    int id;      
    Node* start; 
    Node* end;   
};
void insert(List* list, Node* node)
{
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
        if (comparesl(n->word, node->word) < 0)
        {
            prev = n;
            n = n->next;
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
List* create_list(const char* file, int id)
{
    FILE* fp;
    if ((fp = fopen(file, "r")) == NULL) 
    {
        printf("Cannot open file '%s'\n", file);
        exit(1);
    }
    List* list = (List*)malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;
    list->id = id;
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
            insert(list, node); 
            inserted = 1;       
            first_letter = 1;        
        }
        c = fgetc(fp);
    }
    fclose(fp);
    return list;
}
void print_list(List* list)
{
    printf("List %d:\n", list->id);
    for (Node* n = list->start; n != NULL; n = n->next)
    {
        printf("Node->word: '%s'\n", n->word);
    }
}
void merge(List* dst, List* src)
{
    Node* n = src->start;
    while (n != NULL)
    {
        Node* node = n; 
        n = n->next;    
        insert(dst, node); 
    }
    src->start = NULL;
    src->end = NULL;
}
void delete_list(List* list)
{
    printf("Delete list %d\n", list->id);
    Node* n = list->start; 
    while (n != NULL)
    {
        Node* node = n;  
        n = n->next;     
        printf("  delete '%s'\n", node->word);
        free(node->word);
        free(node);       
    }
    free(list);
}
int main()
{
    List* one = create_list("C:\\github\\labs\\lab6\\Debug\\one.txt", 1);
    List* two = create_list("C:\\github\\labs\\lab6\\Debug\\two.txt", 2);
    List* three = create_list("C:\\github\\labs\\lab6\\Debug\\three.txt", 3);
    print_list(one);
    print_list(two);
    print_list(three);
    merge(one, two);
    merge(one, three);
    printf("\n After merge:\n");
    print_list(one);
    print_list(two);
    print_list(three);
    printf("\n");
    delete_list(one);
    delete_list(two);
    delete_list(three);
    return 0;
}

