#include<stdio.h>
#include<stdlib.h>




typedef struct Node
{

	int data;
	struct Node* next;
}node;


void insert(node **pointer, int data)
{
	node* temp;

	temp = (node*)malloc(sizeof(node));
        temp->next = NULL;
	temp->data = data; 
	while(*pointer->next !=NULL)
	{
		*pointer = *pointer->next;

	}

 	*pointer->next = temp;
	*pointer = temp;	

}

void delete(node *pointer, int data)
{

	while( pointer->next !=NULL && pointer->next->data != data )
	{
	    pointer= pointer->next;	
	
	}	

	if(pointer->next == NULL)
	{
	   printf("the element %d is not present \n", data);
		
	}
	
 	node *temp;
	
	temp = pointer->next;

	pointer->next = temp->next;

	free(temp)

}

void print(node *pointer)
{

	do()
	{
	   printf("the node value is %d \t", pointer->data);

	}while(pointer->next != NULL)

}

int find(node *pointer,int data)
{
	

}



int main()
{

	node *head, *temp ;
	
	head = (node*)malloc(sizeof(node));
	temp = head;
	temp->next = NULL;

	
	while(1)
	{
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Print \n");
		printf("4. Find \n");

		int query;
		scanf("%d",&query);
                
		switch(query)
		{
			case 1:
			int data;	 
	                scanf("%d", &data);
			insert(&head,data);
			break;

			case 2:
			int data;
			scanf("%d", &data);
			delete(head,data);
			break;

			case 3:
			printf("The list is: \n")
			print(head);
			break;

			case 4:
			int data;
			scanf("%d",&data);
			int status = find(head,data);
			if(status)
			{
	
			}
				
		}	
	}
}
