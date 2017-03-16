#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void PrintNode(struct node* node)
{
	printf("\nPrintNode");
	struct node* current = node;
	while(current!=NULL)
	{
		printf("\n%d",current->data);
		current=current->next;
	}
}

void AddNodeAtHead(struct node** nodeRef, int data)
{
	printf("\nAddNodeAtHead");
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	
	newNode->next = *nodeRef;
	*nodeRef = newNode;
}

void AddNodeAtTail(struct node** nodeRef, int data)
{
	printf("\nAddNodeAtTail");

	struct node* newNode =(struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	struct node* current = *nodeRef;

	if(current==NULL)
	{
		*nodeRef = newNode;
	}
	else
	{
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next = newNode;
	}
}

int main()
{
	struct node* head=NULL;

	AddNodeAtHead(&head,3);
	PrintNode(head);
	AddNodeAtTail(&head,4);
	PrintNode(head);
	AddNodeAtHead(&head,2);
	PrintNode(head);
	AddNodeAtHead(&head,1);
	PrintNode(head);
	AddNodeAtTail(&head,5);
	PrintNode(head);

	return 0;
}
