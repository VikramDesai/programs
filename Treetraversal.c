#include<stdio.h>
#include<stdlib.h>




typedef struct Node {

int data;
struct Node* left;
struct Node* right; 

}node;


node* newNode(int data)
{

node* newnode = (node*)malloc(sizeof(node));
newnode->data = data;
newnode->left = NULL;
newnode->right = NULL;
return(newnode);

}

void printPreorder(node* newnode);
void printInorder(node* newnode);
void printPostorder(node* newnode);

void printPreorder(node* newnode)
{

if(newnode == NULL)
return;

printf("%d \n", newnode->data);

printPreorder(newnode->left);

printPreorder(newnode->right);	

}


void printInorder(node* newnode)
{

if(newnode == NULL)
return

printInorder(newnode->left);

printf("%d \n",newnode->data);

printInorder(newnode->right);

}


void printPostOrder(node* newnode)
{

if(newnode == NULL)
return;

printPostOrder(newnode->left);
printPostOrder(newnode->right);

printf("%d \n",newnode->data);

}

int main(int argc,char* argv[])
{

 node* root = newNode(1);
 root->left = newNode(2);
 root->right = newNode(3);
 root->left->left = newNode(4);
 root->left->right = newNode(5);
 root->right->left = newNode(6);
 root->right->right = newNode(7);


printf("Printing PreOrder: \n");

printPreorder(root);


printf("Printing InOrder: \n");
printInorder(root);

printf("Printing PreOrder: \n");
printPostOrder(root);
}
