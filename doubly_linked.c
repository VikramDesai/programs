#include<iostream>

using namespace std;


typedef struct linkednode{

	int data=0;
	struct linkednode* prev=NULL;
	struct linkednode* next=NULL;

}node;

node* head;

node* last;


void insert_begin(int val)
{

	node* temp = (node*)malloc(sizeof(node));
	temp->data = val;

	if(head == NULL)
	{
	   head = temp;
	   head->prev = NULL;
	   head->next = NULL;
	   last=head;	 				
 
	}	
       else
	{	
 	  temp->next = head;
	  head->prev = temp;
	  head = temp;	
	}

}

void insert_end(int val)
{

	node* temp=(node*)malloc(sizeof(node));
	temp->data = val;
	
	if(head == NULL)
	{
	  head=temp;
	  head->next = NULL;	
	  head->prev = NULL;
	  last = head;	
	}
	else
{	
	last=head;
	while(last->next != NULL)
	{
	  last = last->next;	


	}
	
	last->next = temp;
	temp->prev = last;
	last=temp;

}

}


void insert_after(int val, int node_val)
{
 
 //handle null condition and node not available condtition 
  node* temp = (node*)malloc(sizeof(node));
  temp->data = val;	

  last= head;

  while(last->next != NULL && last->data != node_val)
    {
	last = last->next;
		
    }


  if(last->next == NULL)
 {
  printf("Error: node not present \n");		

 }	
else{

  temp->next = last->next;
  las->next->prev = temp;	
  last->next = temp;
  temp->prev = last;	

}  

last=head;
}

void delete_from_end()
{

	node* temp1;
        last =head;	
    
        if(last->next!= NULL)
	{
	  last = last->next;

	}
        temp1 = last;
	last= last->prev;
	last->next = NULL;

	free(temp1);
}	


void delete_from_val(int val)
{

	node* temp1;
	last=head;

  while(last->next!= NULL && last->data != val)	
	last=last->next;	

  temp1 = last;
  last = last->prev;
  last->next = NULL;  		
  
temp1->next = NULL;
temp1->prev = NULL;

free(temp1);	


}

void printlist()
{
  last =head;

while(last->next != NULL)
{
  printf("the node value is : %d \n", last->data);
 
}

}

