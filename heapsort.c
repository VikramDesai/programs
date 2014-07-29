#include<stdio.h>
#include<stdlib.h>

typedef struct MaximumHeap{

int* arr;
int size;

}max;

void swap(int *a, int *b);
void heapsort(int *arr, int size);
void printArry(int* arr, int size);
void Maxheapify(max* aInHeap, int idx);

max* BuildHeapArray(int *arr,int size);


int main(int argc, char* argv[])
{


int arr[] ={4,6,10,3,5};

int size = sizeof(arr)/sizeof(arr[0]);
 

quicksort(arr,size);
printf("The Sorted Array is: \n");
printArray(arr,size);


}


void swap(int *a, int *b)
{
	int temp=0;
	temp= *a;
	*a = *b;
	*b = temp;

}


void heapsort(int *arr, int size)
{

	
max* maxheap = BuildheapArray(arr,size);

while (maxheap->size > 1)
{
	swap(&maxheap->arr[0],&maxheap->arr[size-1]);
	--maxheap->size;

	MaxHeapify(maxheap,0);

}


}


void printArry(int* arr, int size)
{
  int i;
  for( i=0;i<size;i++)
  {
	printf("%d \t",*(++arr) );

  }			


}


void Maxheapify(max* aInHeap, int idx)
{

	int largest = idx;
	int left = (idx<<2)+1;
	int right = (idx<<2)+2;

	if( left <= aInHeap->size && aInHeap->arr[left] > aInHeap->arr[largest])
	{
	  largest = left;	
	
	}		
	
	if( right <= aInHeap->size && aInHeap->arr[right] > aInHeap->arr[largest])
	{
	  largest = right;	
	}

	if(largest != idx)
	{
	  swap(&aInHeap->arr[largest],&aInHeap->arr[idx]);
	  MaxHeapify(aInHeap,largest);	
	}


}





max* BuildHeapArray(int *arr,int size)
{

	max* maxheap = (max*)malloc(sizeof(max));
	maxheap->arr = arr;
	maxheap->size = size;

	int i = (maxheap->size -2)/2;
	for( ; i>0 ; --i)
	{
	  Maxheapify(maxheap,i);	
	
	}

	return maxheap;	
}


