#include<stdio.h>
#include<stdlib.h>





int binarysearch(int *a, int len, int key)
{
 int min=0, max=len-1;	
 return binarysearchutil(a,len,key,min,max); 

}

int binarysearchutil(int *a,int len, int key, int min, int max)
{

//printf("min:%d and max:%d\n",min,max);
 
if( min > max && a !=  NULL)
return -1;  
  
 int mid=(max+min)/2;
 if(a[mid] == key)
  return mid;
 else
{
  if(a[mid] > key)
  max= mid -1;
  else
  min = mid+1;			

}

return binarysearchutil(a,len,key,min,max); 		

}


int main()
{

int a[10]={6,7,34,42,56,76,85,98,104,135};

int found= -1;
found = binarysearch(a,10,7);	

printf("%d \n",found);

}
