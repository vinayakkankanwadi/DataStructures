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
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	
	newNode->next = *nodeRef;
	*nodeRef = newNode;
}

int DetectLoop(struct node * list)
{
	struct node *slow_p = list,*fast_p=list;
	while(slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if( slow_p == fast_p)
		{
			printf("\nLoop Found");
			return 1;
		}
	}

	return 0;
}

int main()
{
	struct node* head=NULL;

	AddNodeAtHead(&head,20);
	AddNodeAtHead(&head,4);
	AddNodeAtHead(&head,15);
	AddNodeAtHead(&head,10);
	PrintNode(head);

	head->next->next->next->next = head;
	DetectLoop(head);

	return 0;
}
