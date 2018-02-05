#include <stdio.h>

#define MAX_SIZE 50

int binary_search(int a[],int low,int high,int key);

int main()
{

	int a[]={2,1,5,3,6,4,8,9,7};
	int c[MAX_SIZE]={0};		/*DP array*/
	int max_subseq[MAX_SIZE]={0};	/*Store result for print*/
	int end[MAX_SIZE]={0};		/*Auxiliary array for binary search, store the end element in a[..] of length i in end[i]*/
	
	int i=0,j=0;
	int array_size=sizeof(a)/sizeof(a[0]);
	int max_index=0,current_index=0,length=0,position=0;

	c[0]=1;
	end[0]=a[0];
	length=0;
	for(i=1;i<array_size;++i)
	{

#if 0 
		for(j=i-1;j>=0;--j)	/*T(n)=O(n^2)'s solution'*/
		{
			if(a[j]<a[i]&&c[j]>=c[i])	/*Compare every subsequence to find the longest*/
			{
				c[i]=c[j]+1;
			}
		}
		/*If not find, then subsequence end with c[i] has length 1 by default*/
#endif

		/*T(n)=O(n*lgn) solution, using axiliary array to determin the length of subsequence by binary search*/
		position=binary_search(end,0,length,a[i]);

		if(position>length)
		{
			length=position;	/*Length grows because a maximum element has been found*/
			c[i]=length+1;		/*Record the length ending with a[i]*/
		}

		/*Record the new end*/
		end[position]=a[i];

	}

	/*Build the subsequnce based on c[..]*/
	max_index=array_size-1;
	current_index=max_index;
	length=MAX_SIZE;
	for(i=array_size-1;i>=0;--i)
	{
		/*If a longer subsquence end has been found, replace the current one*/
		if(c[i]>c[max_index])
		{
			max_index=i;
			current_index=max_index;	/*Build from the newly found maximum tail*/
			length=MAX_SIZE;
			max_subseq[--length]=a[current_index];
		}

		if(a[i]<a[current_index]&&c[i]+1==c[current_index])
		{
			current_index=i; /*Find a proper successor of the current c, append to the subsequence*/
			max_subseq[--length]=a[current_index];
		}
	}

	/*Print the result*/
	printf("The longest increasing subsequence is:\r\n");
	for(i=length;i<MAX_SIZE;++i)
	{
		printf("%d,",max_subseq[i]);
	}
	printf("\b \r\n");

	return 0;
}

/*Search the first element whose value is bigger than key*/
int binary_search(int a[],int low,int high,int key)
{

	int mid=0;
	
	while(high>=low)
	{
		mid=(low+high)/2;
		if(a[mid]>key)
		{
			high=mid-1;
		}
		else if(a[mid]<key)
		{
			low=mid+1;
		}
		else	/*Or simply replace the second condition from else if  to if*/
		{
			printf("There should be no equal value in the sequence\r\n");
			return -1;
		}

	}
	
	/*The first element bigger than key is always in a[low]*/
	return low;
}





