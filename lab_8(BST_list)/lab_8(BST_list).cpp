#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};
node *tree = NULL;

void input_tree( node **root, int key )
{
	if ((*root) == NULL)				//Проверяем дерево на существование
	{
		(*root) = new node;
		(*root)->data = key;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}
	else
	{
		if ( key >= (*root)->data )
			input_tree(&(*root)->right, key);
		else
			input_tree(&(*root)->left, key);
	}
}

void output_tree( node *root)
{
	if (root == NULL) return;
	else
	{
		output_tree(root->left);
		cout << root->data << " ";
		output_tree(root->right);
	}
}

int main()
{
	setlocale(0, "rus");
	srand(time(NULL));

	int n = 0;					//количество элементов
	int num = 0;				//передаваемое число
	cout << "Введите количество элементов ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		num = rand() % 100 + 1;
		input_tree(&tree, num);
	}

	output_tree(tree);
	
	cout << endl;
	system("PAUSE");
	return 0;
}