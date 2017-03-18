#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * NewNode(int data)
{
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct node* insert(struct node* node, int data)
{
	if( node == NULL)
	{
		return NewNode(data);
	}
	else
	{
		if(data <= node->data )
		{
			node->left = insert(node->left,data);
		}
		else
		{
			node->right = insert(node->right,data);
		}
		return (node);
	}
}

void PrintTree(struct node* node)
{
	if(node == NULL)
		return ;

	PrintTree(node->left);
	printf("%d ", node->data);
	PrintTree(node->right);
}

int main()
{
	struct node * root =NULL;
	root = insert(root,4);
	printf("\n");
	PrintTree(root);
	root = insert(root,2);
	printf("\n");
	PrintTree(root);
	root = insert(root,5);
	printf("\n");
	PrintTree(root);
	root = insert(root,1);
	printf("\n");
	PrintTree(root);
	root = insert(root,3);
	printf("\n");
	PrintTree(root);
	return 0;
}
