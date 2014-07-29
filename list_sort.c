#include<stdio.h>
#include<stdlib.h>



typedef struct linkednode{

	int data;
	struct linkednode *next;
}node;




void push(node** head, int val)
{

	node* var = (node*)malloc(sizeof(node));
	var->data = val;
	
        var->next = (*head);
	
	(*head) = var;



}

void printnodes(node** head)
{
   node* temp = *head;
   while(temp != NULL)
{
	printf("%d\n", temp->data);
	temp = temp->next;	

}

}

void sortlist(node** head)
{

printf("Entered sorting \n");

if(head == NULL || (*head) == NULL)
return;	

node* lsorted = (*head);
node* tobeSorted = lsorted->next;

while(tobeSorted != NULL)
{

	if(tobeSorted->data < (*head)->data)
	{
	  lsorted->next = tobeSorted->next;
	  tobeSorted->next = (*head);
	  (*head) = tobeSorted;	

printf("Entered head node sorting \n");

	}
	else
	{	
		node* pnode = (*head);

		while(pnode != lsorted && pnode->next->data < tobeSorted->data)
		{
			
			pnode=pnode->next;

		}

		if(pnode != lsorted)
		{
printf("tobeSorted VAlue: %d \n", tobeSorted->data);
		  lsorted->next = tobeSorted->next;
				
		  tobeSorted->next = pnode->next;
		  pnode->next = tobeSorted;	

		}
		else
		  lsorted=lsorted->next;	


	}
	tobeSorted = tobeSorted->next;
	



}

}




int main(int argc, char* argv[])
{

  node* a = NULL;
  push(&a,5);
  push(&a,20);
  push(&a,4);
  push(&a,3);
  push(&a,30);

  printf("The nodes of the linkedlist are: \n");	
  printnodes(&a);

  sortlist(&a);	

  printnodes(&a);
}
