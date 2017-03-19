#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

class Stack
{
	struct node* top;
   public:
	Stack();
	bool IsEmpty();
	void Display();
	void Push(int );
	int Pop();
};

Stack::Stack()
{
	top = NULL;
}

bool Stack::IsEmpty()
{
	return ( top == NULL);
}

void Stack::Display()
{
	printf("\nStack");
	struct node* current = top;
	while(current!=NULL)
	{
		printf("\n%d",current->data);
		current=current->next;
	}
}
	
void Stack::Push(int data)
{
	struct node* newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next = NULL;

	if(!IsEmpty())
	{
		newNode->next = top;
	}
	top = newNode;
}

int Stack::Pop()
{
	int val = -1;
	if(!IsEmpty())
	{
		struct node* temp = top;
		val = temp->data;
		top = top->next;
		free(temp);
	}
	return val;
}


class Graph
{
	int n;
	int A[100][100];

   public:
	Graph(int);
	bool IsConnected(int,int);
	void AddEdge(int,int);
	void DFS(int,int);
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

void Graph::DFS(int x, int required)
{
	bool visited[100];
	for ( int i=0;i<=n;i++)
		visited[i]=0;

	Stack s;
	s.Push(x);
	visited[x]=1;
	while(!s.IsEmpty())
	{
		int k = s.Pop();
		printf("\n %d",k);

		if( k == required)
			break;
		for(int i =n;i>=0;i--)
		{
			if(IsConnected(k,i) && !visited[i])
			{
				visited[i]=1;
				s.Push(i);
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
	g.DFS(1,8);
	
	return 0;
}
/*
int main()
{
	Stack s;
	s.Push(10);
	s.Display();
	s.Push(20);
	s.Display();
	s.Push(30);
	s.Display();
	int val = s.Pop();
	printf("\nRemoved %d",val);
	s.Display();
	s.Push(40);
	s.Display();
	
	return 0;
}
*/
