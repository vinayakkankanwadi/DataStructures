#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
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
//	printf("\nAddNodeAtHead");
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	newNode->next = *nodeRef;

	// Additional
	if((*nodeRef)!=NULL)
		(*nodeRef)->prev = newNode;

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

void DeleteNode(struct node** headRef, struct node* del)
{
	printf("\nDel ");
	if(*headRef == NULL || del == NULL)
		return;

	if((*headRef) == del)
	{
		printf("Start");
		*headRef= del->next;
	}

	if(del->next !=NULL)
	{
		del->next->prev = del->prev;
	}

	if(del->prev !=NULL)
	{
		del->prev->next = del->next;
	}

	free(del);
}

int main()
{
	struct node* head=NULL;

	AddNodeAtHead(&head,2);
	AddNodeAtHead(&head,4);
	AddNodeAtHead(&head,8);
	AddNodeAtHead(&head,10);
	PrintNode(head);

	DeleteNode(&head,head);
	PrintNode(head);
	DeleteNode(&head,head->next);
	PrintNode(head);


	return 0;
}
