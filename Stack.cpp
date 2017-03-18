#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node * next;
};

class Stack
{
	struct node* top;
   public:
	Stack();
	void Push(int);
	int Pop();
	bool IsEmpty();
	void Display();
};

Stack::Stack()
{
	top = NULL;
}

bool Stack::IsEmpty()
{
	return (top == NULL);
}

void Stack::Display()
{
	printf("\nDisplay Stack:");
	struct node* current = top;
	if(current == NULL)
	{
		printf("\nStak is Empty");
	}
	else
	{
		while(current!=NULL)
		{
			printf("%d",current->data);
			current=current->next;
		}
	}	
}

void Stack::Push(int data)
{
	struct node* newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if( top!=NULL)
		newNode->next = top;

	top = newNode;
}

int Stack::Pop()
{
	int value = -1;
	if(!IsEmpty())
	{
		struct node* temp = top;
		value = temp->data;
		top =top->next;

		free(temp);
	}
	return value;
}

int main()
{
	Stack s;
	s.Push(1);
	s.Push(3);
	s.Push(2);
	s.Display();
	int val = s.Pop();
	printf("\n Deleted %d",val);
	s.Display();

	return 0;
}
