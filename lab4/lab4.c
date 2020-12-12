#include<stdio.h>
#include<stdlib.h>
int lengthword(char* a)
{
	int res = 0;
	for (int i = 0; a[i] != '\0'; i++)
		res++;
	return res;
}
int is_alpha(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
char* get_string(int* len)
{
	*len = 0;
	int capacity = 1;
	char* str = (char*)malloc(sizeof(char));
	char c = getchar();
	while (c != '\n') {
		str[(*len)++] = c;
		if (*len >= capacity)
		{
			capacity *= 2;
			str = (char*)realloc(str, capacity * sizeof(char));
		}
		c = getchar();
	}
	str[*len] = '\0';
	printf("\n");
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
	printf("\n");
	return words;
}
int main()
{
	printf("Input string:");
	int neisp;
	char* str = get_string(&neisp);
	int wc;
	char** words = get_words(str, &wc);
	printf("Input word:");
	char* word = get_string(&neisp);
	int maxlen = 0;
	char* maxword = 0;
	printf("Input 1/0:");
	int nullone;
	for (int i = 0; i < wc; i++)
	{
		int len = lengthword(words[i]);
		if (len > maxlen)
		{
			maxlen = len;
			maxword = words[i];
		}
	}
	for (int i = 0; i < wc; i++)
	{
		if (words[i] != maxword)
			printf("%s ", words[i]);
		else
			printf("%s ", word);
	}
	printf("\n");
	free(str);
	free(words);
}
