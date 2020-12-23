#include<stdio.h>
#include<stdlib.h>
//#include<limits.h>
int length_word(char* a)
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
	if (str == NULL)
	{
		free(str);
		exit(1);
	}
	char c = getchar();
	while (c != '\n') {
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
				exit(1);
			}
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
	if (words == NULL)
	{
		free(str);
		free(words);
		exit(1);
	}
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
				char** temp = (char**)realloc(words, capacity * sizeof(char*));
				if (temp != NULL)
				{
					words = temp;
				}
				else
				{
					free(str);
					free(words);
					exit(1);
				}
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
	printf("Input string:");
	int neisp;
	char* str = get_string(&neisp); 
	int wc;
	char** words = get_words(str, &wc); 
	printf("Input word:");
	char* word = get_string(&neisp); 
	int maxlen = 0;
	//int minlen = INT_MAX;
	int minlen = 2147483647;
	char* changeword = 0;
	int temp;
	printf("Input temp(0 - change min or 1 - change max):");
	int fake = scanf("%d", &temp);
	if(fake == 0)	
	{
		free(words);
		free(str);
		free(word);
		exit (1);
	}
	if (temp == 1)
	{
		for (int i = 0; i < wc; i++)
		{
			int len = length_word(words[i]);
			if (len > maxlen)
			{
				maxlen = len;
				changeword = words[i];
			}
		}
	}
	else if (temp == 0)
	{
		for (int i = 0; i < wc; i++)
		{
			int len = length_word(words[i]);
			if (len < minlen)
			{
				minlen = len;
				changeword = words[i];
			}
		}
	}
	else 
	{
		printf("YOU CAN'T ENTER THESE SYMBOLS!!! \n");
		return;
	}
	for (int i = 0; i < wc; i++)
	{
		if (words[i] != changeword)
			printf("%s ", words[i]);
		else
			printf("%s ", word);
	}
	printf("\n");
	free(str);
	free(words);
	free(word);
}