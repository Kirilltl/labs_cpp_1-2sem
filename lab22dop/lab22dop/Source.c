//laba 2 dop
#include <stdio.h>
#include <stdlib.h>
int is_alpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
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
void bubblesort(char* uknaslo[], int che)
{
    for (int j = 0; j < (che - 1); j++)
    {
        for (int i = 0; i < (che - 1); i++)
        {
            int result = comparesl(uknaslo[i], uknaslo[i + 1]);
            char* temp;
            if (result > 0)
            {
                temp = uknaslo[i];
                uknaslo[i] = uknaslo[i + 1];
                uknaslo[i + 1] = temp;
            }
        }
    }
}
char* get_string(int* len) 
{
    *len = 0;
    int capacity = 1;
    char* str = (char*)malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') 
    {
        str[(*len)++] = c;
        if (*len >= capacity) 
        {
            capacity *= 2;
            str = (char*)realloc(str, capacity * sizeof(char));
        }
        c = getchar();
    }
    str[*len] = '\0';
    return str;
}
char** get_words(char* str, int* wc)
{
    *wc = 0;
    int flag = 1;
    int capacity = 1;
    char** words = (char**)malloc(sizeof(char*));
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (is_alpha(str[i]) == 1 && flag)
        {
            words[*wc] = &str[i];
            (*wc)++;
            flag = 0;
            if (*wc >= capacity) 
            {
                capacity *= 2;
                words = (char**)realloc(words, capacity * sizeof(char*));
            }
        }
        else if (is_alpha(str[i]) == 0)
        {
            str[i] = '\0';
            flag = 1;
        }
    }
    return words;
}
int main()
{
    int len;
    char* str = get_string(&len);
    printf("You wrote: '%s'\n", str); 
    int wc;
    char** words = get_words(str, &wc);
    bubblesort(words, wc);
    for (int i = 0; i < wc; i++)
        printf("word: '%s'\n", words[i]);
    free(words);
    free(str);
    return 0;
}