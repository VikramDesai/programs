#include<stdio.h>
#include<stdlib.h>

typedef struct Newnode{

	int data;
	struct Newnode* left;
	struct Newnode* right;
	struct Newnode* parent;	
}node;


node* newnode(int data)
{

	node* newnode = (node*)malloc(sizeof(node));
	
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;

	return(newnode);
}




node* inorderNext(node* newnode)
{

	if(newnode == NULL)
	 return NULL;
	
	node* nextnode = NULL;
	if(newnode->right != NULL)
	{
		node *rightnode = newnode->right;

		while(rightnode->left != NULL)
		{
			rightnode = rightnode->left;
		}		

		nextnode = rightnode;	

	}	
	else if( newnode->parent != NULL)
	{

		node* lparent = newnode->parent;
		node* lcurrent = newnode;

		while( lparent != NULL && lcurrent == lparent->right)
		{
			lcurrent = lparent;
			lparent = lparent->parent;

		}
		nextnode = lparent;	
	}	



  return nextnode;

}








int main(int argc, char* argv[])
{

	node* root = newnode(4);
	root->left = newnode(3);
	root->left->parent = root;
	root->left->left = newnode(1);
	root->left->left->parent = root->left;
	root->left->right = newnode(2);
	root->left->right->parent = root->left;
	root->right = newnode(6);
	root->right->parent = root;
	root->right->left = newnode(5);
	root->right->left->parent = root->right;
	root->right->right = newnode(7);
	root->right->right->parent = root->right; 
	



 	node* nextnode = inorderNext(root->left->right);

	printf("The next inorder node is %d \n", nextnode->data);
}
