#include<iostream>
#include<string>
#include<list>
#include<stdio.h>

using namespace std;


class Resource{


int value;

public:

Resource()
{

value = 0;	
}

void reset()
{
 value=0;	
}

int getvalue()
{

return value;
}

void setvalue(int data)
{

value = data;

}
};



class ObjectPool
{

 private:

 list<Resource*> resources;
 
 static  ObjectPool* instance;

  ObjectPool(){ };

 public:

 
 static ObjectPool* getInstance()
 {

	if(instance == 0)
	{

	   instance = new ObjectPool();

	}
	else
	{
          return instance;

	 }


 }

 
 Resource* getresources()
 {

   if(resources.empty())
    {
      printf("Creating new resources \n");
	return new newresource;	

    } 
    else
	{
  	
   	Resource* val = resources.front();
	resources.pop_front();
   	return val;
	}


} 


void returnresources(Resource* val)
{

	val->reset();
	resources.push_back(val);
	
}


};


static ObjectPool* instance=0;

int main()
{

	ObjectPool* inst = ObjectPool::getInstance();
	Resource* r1,r2;

	r1 = inst->getresources();
	r2 = inst->getresources();

	r1->setvalue(10);

	printf("The value in r1 is %d\n", r1->getvalue());
	r2->setvalue(20);

	printf("The value in r2 is %d\n", r2->getvalue());
	inst->returnresources(r1);
 	inst->returnresources(r2);
	
	r1 = inst->getresources();
	r2 = inst->getresources();
	printf("The value in r1 is %d\n", r1->getvalue());
	
	printf("The value in r2 is %d\n", r2->getvalue());

}
