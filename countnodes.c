#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

int data;
struct node* left;
struct node* right;

}node;



node* newnode(int data)
{

node* lnewnode = (node*)malloc(sizeof(node));
lnewnode->data = data;
lnewnode->left = NULL;
lnewnode->right = NULL;

return lnewnode;

}



node* insert(node* aInNode, int data)
{

if(aInNode == NULL)
return(newnode(data));

if(data <= aInNode->data)
{
aInNode->left = insert(aInNode->left,data);
}
else
{
aInNode->right = insert(aInNode->right,data);

}

return aInNode;

}


void printPreOrder(node* root)
{

 if(root == NULL)
 return;

 printf("%d\n", root->data);

 printPreOrder(root->left);	

 printPreOrder(root->right);

}

int countnodes(node* aInNode)
{

	if(aInNode == NULL)
	return(0);

	else
	{		
	  int  res = (countnodes(aInNode->left)+countnodes(aInNode->right)+1);
	   return res;	

	}



}



int main(int argc, char* argv[])
{

/*node* root = newnode(4);
root->left = newnode(3);
root->right = newnode(6);
root->left->right = newnode(2);
root->right->left = newnode(5);
root->right->right = newnode(7);
*/

node* root = NULL;
root = insert(root, 4);
int res1;

insert(root,2);
insert(root,3);
insert(root,1);
insert(root,6);
insert(root,5);
insert(root,7);


printPreOrder(root);

res1 = countnodes(root);
printf("Number of nodes: %d\n", res1);
}
