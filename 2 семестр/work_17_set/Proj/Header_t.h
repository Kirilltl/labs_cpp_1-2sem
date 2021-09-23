#ifndef HEADER_T_H
#define HEADER_T_H
#include<iostream>
#include <stdlib.h>
template <typename T>
class Set
{
private:
	typedef struct node {
		T value;
		struct node* left;
		struct node* right;
	} node;
	node* m_root;
	bool m_found;
	int m_size;
	void insert(node** root, T word) {
		int i = 0, len = 10;
		if (!*root) {
			*root = (node*)malloc(sizeof(**root));
			if (!*root) {
				exit(1);
			}
		
			(*root)->value = word;
			(*root)->left = NULL;
			(*root)->right = NULL;
			return;
		}
		if (word < (*root)->value) {
			insert(&(*root)->left, word);
		}
		else {
			insert(&(*root)->right, word);
		}
	}
	void print_tree(node* root) {
		if (root) {
			print_tree(root->left);
			std::cout << root->value << std::endl;
			print_tree(root->right);
		}
		else {
			return;
		}
	}
	void find(node* root, T word) {
		if (root) {
			find(root->left, word);
			if (root->value==word)
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
		else 
		{
			return;
		}
	}
	void deleteTree(node* root)
	{
		if (root) {
			deleteTree(root->left);
			deleteTree(root->right);
		}
		else 
		{
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
	void insert(T word) {
		insert(&m_root, word);
		m_size++;
	}
	void print_all() {
		print_tree(m_root);
	}
	bool find(T word) {
		m_found = false;
		find(m_root, word);

		return m_found;
	}
	void intersect(Set& s2, Set& n)
	{
		intersect(m_root, s2, n);
		if (n.m_size == 0)
			throw std::runtime_error("intersection with an empty set");
	}
	~Set()
	{
		deleteTree(m_root);
	}


};
#endif
