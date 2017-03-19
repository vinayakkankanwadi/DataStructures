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


class Graph
{
	int n;
	int A[100][100];

   public:
	Graph(int);
	bool IsConnected(int,int);
	void AddEdge(int,int);
	void BFS(int,int);
};

Graph::Graph(int in)
{
	n = in;
	for (int i=0;i<in;i++)
	{
		for(int j=0;j<in;j++)
			A[i][j]=0;
	}	
}

bool Graph::IsConnected(int x,int y)
{
	return (A[x-1][y-1]==1);
}

void Graph::AddEdge(int x,int y)
{
	A[x-1][y-1] = 1;
	A[y-1][x-1] = 1;
}

void Graph::BFS(int x, int required)
{
	bool visited[100];
	for ( int i=0;i<=n;i++)
		visited[i]=0;

	Queue q;
	q.EnQueue(x);
	visited[x]=1;
	while(!q.IsEmpty())
	{
		int k = q.DeQueue();
		printf("\n %d",k);

		if( k == required)
			break;
		for(int i =1;i<=n;i++)
		{
			if(IsConnected(k,i) && !visited[i])
			{
				visited[i]=1;
				q.EnQueue(i);
			}
		}
	}
}

int main()
{
	Graph g(8);
	g.AddEdge(1,2);
	g.AddEdge(1,3);
	g.AddEdge(1,4);
	g.AddEdge(2,5);
	g.AddEdge(2,6);
	g.AddEdge(4,7);
	g.AddEdge(4,8);
	g.BFS(1,8);
	
	return 0;
}
