#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include <stdlib.h>
template <typename T>
class Set
{
private:

	typedef struct node {
		char* value;
		struct node* left;
		struct node* right;
	} node;

	node* m_root;
	bool m_found;
	int m_size;

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
	void insert(node** root, const char* word) {
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
		if (strcomp((char*)word, (*root)->value) < 0) {
			insert(&(*root)->left, word);
		}
		else {
			insert(&(*root)->right, word);
		}
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
	void find(node* root, const char* word) {
		if (root) {
			find(root->left, word);
			if (strcomp(root->value, (char*)word) == 0)
			{
				m_found = true;
			}
			find(root->right, word);
		}
		else {
			return;
		}
	}
	void intersect(node* root, Set& s2, Set& n) {
		if (root) {
			intersect(root->left, s2, n);
			if (s2.find(root->value) == true)
			{
				n.insert(root->value);
			}
			intersect(root->right, s2, n);
		}
		else {
			return;
		}

	}

	void deleteTree(node* root)
	{
		if (root) {
			deleteTree(root->left);
			free(root->value);
			deleteTree(root->right);
		}
		else {
			return;
		}

	}

public:
	Set() {
		m_root = NULL;
		m_found = false;
		m_size = 0;
	}
	int get_size() {
		return m_size;
	}

	void insert(const char* word) {
		insert(&m_root, word);
		m_size++;
	}
	void print_all() {
		print_tree(m_root);
	}
	bool find(const char* word) {
		m_found = false;
		find(m_root, word);

		return m_found;
	}
	void intersect(Set& s2, Set& n)
	{
		intersect(m_root, s2, n);

		printf("done\n");
		if (n.m_size == 0)
			throw std::runtime_error("intersection with an empty set");
	}
	~Set()
	{
		deleteTree(m_root);
	}


};
#endif