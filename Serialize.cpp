#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>


using namespace std;

typedef struct Node{

int data;
struct Node* left;
struct Node* right;

}node;


node* newnode(int data)
{

	
node* lnode = (node*)malloc(sizeof(node));
lnode->left=NULL;
lnode->right=NULL;
return lnode;

}



void treeToFile(node* aInNode, ofstream& input_file)
{

if(aInNode == NULL)
{
	input_file<<"#"<<"";
	return;
	
}
input_file<<aInNode->data<<"";
treeToFile(aInNode->left, input_file);
treeToFile(aInNode->right, input_file);

}



node* fileToTree(ifstream& input_file)
{

 string s;
 input_file>>s;

if(s=="#")
return NULL;

while(s=="")
{
  input_file>>s;	

}

int value = atoi(s.c_str());

node* root = newnode(value);

root->left = fileToTree(input_file);
root->right = fileToTree(input_file);

return root;


}

void printPreOrder(node* aInNode)
{

 if(aInNode == NULL)
 return;

 printf("%d\n",aInNode->data);

 printPreOrder(aInNode->left);

 printPreOrder(aInNode->right);	


}



int main(int argc,char* argv[])
{

node* root = newnode(4);
root->left = newnode(2);
root->right = newnode(6);
root->left->left = newnode(1);
root->left->right = newnode(3);
root->right->left = newnode(5);
root->right->right = newnode(7);


ofstream sFile(argv[1]);

treeToFile(root,sFile);
sFile.close();

ifstream inFile(argv[1]);

node* root1 = fileToTree(inFile);

inFile.close();

printPreOrder(root1);

}
