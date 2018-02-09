#include <stdio.h>

#define K 4	/*Find all elements that appear more than N/K times in an array*/
		/*At most K-1 kinds of these elements*/
		/*This is the general situation of find the element appears more than half times*/
typedef struct appear
{
	int candidate;
	int times;
}APPEAR;

int main()
{

	/*Find the element which appears onces, while all other elements appear k times*/
	int a[]={1,4,5,1,4,1,5,1,4,9,9,9,9,9,9,9,9,1,5,1,4,1,5,4,1,4,4,1,5,5,5};
	int size_a=sizeof(a)/sizeof(a[0]);
	int empty=0;
	int found=0;
	APPEAR e[K-1]={0};

	int i=0,j=0;

	for(i=0;i<size_a;++i)
	{
		empty=-1;
		found=0;
		for(j=0;j<K-1;++j)
		{
			if(e[j].times>0)	/*This position has a candidate*/
			{
				if(e[j].candidate==a[i])	/*The current element is a candidate, appears one more time*/
				{				
					++(e[j].times);
					found=1;		/*Set the found flag*/
					break;
				}
			}
			else
			{
				empty=j;		/*Save a empty space for future use*/
			}
		}

		if(found==0)	/*If the element is not a cadidate*/
		{
			if(empty==-1)	/*No more space for the new candidate*/
			{
				for(j=0;j<K-1;++j)
				{
					--(e[j].times);		/*Every candidate appears one less time to make room for the new candidate*/
				}
			}
			else
			{
				e[empty].candidate=a[i];	/*Save the current element as a candidate*/
				++(e[empty].times);
			}
		}
		
	}

	/*Out put the result*/
	printf("Find all elements which appear more than %d times in the array:\r\n",size_a/K);
	for(j=0;j<K-1;++j)
	{

		if(e[j].times>0)	/*This position has a candidate*/
		{
			found=0;

			for(i=0;i<size_a;++i)	/*Test whether it really appears more than N/K times*/
			{
				if(e[j].candidate==a[i])
				{
					++found;
				}
			}

			if(found>size_a/K)
			{
				printf("Element %d appears %d times\r\n",e[j].candidate,found);
			}
		}

	}

}
