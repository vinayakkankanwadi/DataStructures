#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

class Queue
{
	struct node* front;
	struct node* rear;

   public:
	Queue();
	bool IsEmpty();
	void EnQueue(int data);
	int DeQueue();
	void Display();
};
	
Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

bool Queue::IsEmpty()
{
	return (front == NULL);
}

void Queue::Display()
{
	printf("\n Queue:");
	struct node * current = front;
	if(current == NULL)
		printf("\nQueue Empty");
	else
	{
		while(current!=NULL)
		{
			printf("%d",current->data);
			current=current->next;
		}
	}
}

void Queue::EnQueue(int data)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if( front ==NULL)
	{
		front = newNode;	
	}
	else
	{
		rear->next = newNode;	
	}
	rear = newNode;
}

int Queue::DeQueue()
{
	int value = -1;
	if(!IsEmpty())
	{
		struct node* temp = front;
		value = temp->data;
		front = front->next;
		free(temp);
	}
	return value;
}

int main()
{
	Queue q;
	q.EnQueue(3);
	q.EnQueue(4);
	q.EnQueue(2);
	q.Display();
	int val = q.DeQueue();
	printf("\n Removed %d",val);
	q.Display();
}
