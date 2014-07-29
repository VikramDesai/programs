#include<stdio.h>
#include<stdlib.h>










int myAtoi(char *str)
{

	int res =0;

	for(int i=0; str[i] != '\0'; i++)
	{
		res = res*10+str[i] - '0';
	}

	return res;
}





int main()
{

	char str[] = "11547654";	

	int val = myAtoi(str);

	printf("The value of my atoi is %d \n", val);
	return 0;
}
