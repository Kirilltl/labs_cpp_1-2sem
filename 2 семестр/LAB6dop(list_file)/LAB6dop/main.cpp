#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char* value;
	struct node* left;
	struct node* right;
} node;
char is_alpha(char str) {
	return ((str >= 'A') && (str <= 'Z')) || ((str >= 'a') && (str <= 'z'));
}
int strcomp(char* s1, char* s2) {
	while ((*s1 != 0) && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
void add_node(node** root, char* word) {
	int i = 0, len = 10;
	if (!*root) {
		*root = (node*)malloc(sizeof(**root));
		if (!*root) {
			exit(1);
		}
		(*root)->value = (char*)malloc(len * sizeof(char));
		while (word[i]) {
			if (i == len) {
				len *= 2;
				if (!(*root)->value) {
					exit(1);
				}
				char* tmp = (char*)realloc((*root)->value, len * sizeof(char));
				if (!tmp) {
					exit(1);
				}
				(*root)->value = tmp;
			}
			if (!(*root)->value) {
				exit(1);
			}
			(*root)->value[i] = word[i];
			i++;
		}
		if (!(*root)->value) {
			exit(1);
		}
		(*root)->value[i] = 0;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}
	if (strcomp(word, (*root)->value) < 0) {
		add_node(&(*root)->left, word);
	}
	else {
		add_node(&(*root)->right, word);
	}
}
node* readFile(const char* file) {
	FILE* fp;
	if ((fp = fopen(file, "r")) == NULL)
	{
		exit(1);
	}
	node* root = NULL;
	int a = 0, len = 10, i = 0;
	char in_word = 0;
	char* word = (char*)malloc(len * sizeof(char));
	while ((a = fgetc(fp)) != EOF) {
		if (is_alpha(a)) {
			if (i == len) {
				len *= 2;
				char* tmp = word;
				word = (char*)realloc(word, len * sizeof(char));
				if (word == NULL) {
					free(tmp);
					printf("Not enough memory!");
					return 0;
				}
			}
			if (!word) {
				exit(1);
			}
			word[i] = a;
			in_word = 1;
			i++;
		}
		else {
			if (in_word) {
				word[i] = 0;
				add_node(&root, word);
				free(word);
				word = (char*)malloc(len * sizeof(char));
				if (word == NULL) {
					printf("Not enough memory!");
					return 0;
				}
				i = 0;
				in_word = 0;
			}
		}
	}
	if (in_word) {
		add_node(&root, word);
		free(word);
	}
	fclose(fp);
	return root;
}
void print_tree(node* root) {
	if (root) {
		print_tree(root->left);
		printf("%s\n", root->value);
		print_tree(root->right);
	}
	else {
		return;
	}
}
void unite(node** dst, node* src) {
	if (src) {
		unite(dst, src->left);
		add_node(dst, src->value);
		unite(dst, src->right);
	}
	else {
		return;
	}
}
int main() {
	node* tree1 = readFile("C:\\github\\labs\\LAB6dop(list_file)\\one.txt");
	node* tree2 = readFile("C:\\github\\labs\\LAB6dop(list_file)\\two.txt");
	node* tree3 = readFile("C:\\github\\labs\\LAB6dop(list_file)\\three.txt");
	node* merge = NULL;
	unite(&merge, tree1);
	unite(&merge, tree2);
	unite(&merge, tree3);
	print_tree(merge);
}

