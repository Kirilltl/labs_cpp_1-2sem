#include<stdio.h>
#include<stdlib.h>
int length_word(char* a)
{
    int res = 0;
    for (int i = 0; a[i] != '\0'; i++)
        res++;
    return res;
}
void twist_word(char* b)
{
    int len = length_word(b);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = b[i];
        b[i] = b[len - 1 - i];
        b[len - 1 - i] = temp;
    }
}
int is_alpha(char ch, char* delimeters, int delimeters_number)
{
    for (int i = 0; i < delimeters_number; i++)
    {
        if (ch == delimeters[i])
        {
            return 0;
        }
    }

    return 1;
}
char* get_string(int* len)
{
    *len = 0;
    int capacity = 1;
    char* str = (char*)malloc(sizeof(char));
    if (str == NULL)
    {
        free(str);
        return NULL;
    }
    char c = getchar();
    while (c != '\n')
    {
        str[(*len)++] = c;
        if (*len >= capacity)
        {
            capacity *= 2;
            char* temp = (char*)realloc(str, capacity * sizeof(char));
            if (temp != NULL)
            {
                str = temp;
            }
            else
            {
                free(str);
                return NULL;
            }
        }
        c = getchar();
    }
    str[*len] = '\0';
    return str;
}
char** get_words(char* str, int* wc, char* delimeters, int delimeters_number)
{
    *wc = 0;
    int flag = 1;
    int capacity = 1;
    char** words = (char**)malloc(sizeof(char*));
    if (words == NULL)
    {
        free(str);
        free(words);
        free(delimeters);
        exit(1);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        int alpha = is_alpha(str[i], delimeters, delimeters_number);

        if (alpha == 1 && flag)
        {
            words[*wc] = &str[i];
            (*wc)++;
            flag = 0;
            if (*wc >= capacity)
            {
                capacity *= 2;
                char** temp = (char**)realloc(words, capacity * sizeof(char*));
                if (temp != NULL)
                {
                    words = temp;
                }
                else
                {
                    free(str);
                    free(words);
                    free(delimeters);
                    exit(1);
                }
            }
        }
        else if (alpha == 0)
        {
            str[i] = '\0';
            flag = 1;
        }
    }
    return words;
}
int main()
{
    printf("Input delimeters:");
    int delimeters_number;
    char* delimeters = get_string(&delimeters_number);
    if (delimeters == NULL)
    {
        exit(1);
    }
    printf("Delimeters number: %d\n", delimeters_number);
    printf("Input string:");
    int len;
    char* str = get_string(&len);
    if (str == NULL)
    {
        free(delimeters);
        exit(1);
    }
    int wc;
    char** words = get_words(str, &wc, delimeters, delimeters_number);
    for (int i = 0; i < wc; i++)
    {
        twist_word(words[i]);
        printf("This is an inverted word: %s\n", words[i]);
    }
    free(str);
    free(words);
    free(delimeters);
    return 0;
}