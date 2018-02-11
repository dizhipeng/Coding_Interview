#include <stdio.h>

int find_median_in_two_sorted_arrays(int a[],int b[],int low1,int low2,int high1,int high2);
int find_rank_k_in_two_sorted_arrays(int a[],int b[],int size_a,int size_b,int k);

int main()
{

	int a[]={1,3,5,6,7,11,14};
	int b[]={2,4,8,9,10,12,13};

	int size_a=sizeof(a)/sizeof(a[0]);
	int size_b=sizeof(b)/sizeof(b[0]);

	printf("%d\r\n",find_median_in_two_sorted_arrays(a,b,0,0,size_a-1,size_b-1));

}

int find_median_in_two_sorted_arrays(int a[],int b[],int low1,int low2,int high1,int high2)
{
	int mid1=0,mid2=0;
 
	if((high1-low1)!=(high2-low2))
	{
		printf("The two arrays must have the same size");
		return -1;
	}
	
	while(low1!=high1)
	{
		mid1=(high1+low1)/2;
		mid2=(high2+low2)/2;

		if(a[mid1]==b[mid2])
		{
			return a[mid1];
		}
		else if(a[mid1]>b[mid2])
		{
			if((high1-low1)%2==0)
			{
				high1=mid1;
				low2=mid2;
			}
			else
			{
				high1=mid1;
				low2=mid2+1;
			}
		}
		else
		{
			if((high1-low1)%2==0)
			{
				low1=mid1;
				high2=mid2;
			}
			else
			{
				low1=mid1+1;
				high2=mid2;
			}
		}
		//printf("%d~%d,%d~%d\r\n",low1,high1,low2,high2);
	}

	if(a[low1]>b[low2])
	{
		return b[low2];
	}
	else
	{
		return a[low1];
	}
}

int find_rank_k_in_two_sorted_arrays(int a[],int b[],int size_a,int size_b,int k)
{
	int min_size=0,max_size=0;
	int low_a=0,low_b=0,high_a=0,high_b=0;

	k--;	/*k start from 0*/
	
	max_size=(size_a>size_b)?size_a:size_b; /*min and max are length, not indices. index=length-1*/
	min_size=(size_a>size_b)?size_b:size_a;

	if(k>=max_size)	/*Effective range: min:[k-max_size,min_size-1] max:[k-min_size,max_size-1]*/
	{
		if(size_a>size_b)
		{
			low_a=k-min_size;
			high_a=max_size-1;
			low_b=k-max_size;
			high_b=min_size-1;
		}
		else
		{
			low_b=k-min_size;
			high_b=max_size-1;
			low_a=k-max_size;
			high_a=min_size-1;
		}		
	}
	else if(k<=min_size)	/*Effective range: min:[0,k] max:[0,k]*/
	{
		low_a=0;
		low_b=0;
		high_a=k;
		high_b=k;
	}
	else		/*Effective range: min:[0,min-1] max:[k-min,k]*/
	{
		if(size_a>size_b)
		{
			low_a=k-min;
			high_a=k;
			low_b=0;
			high_b=min-1;
		}
		else
		{
			low_b=k-min;
			high_b=k;
			low_a=0;
			high_a=min-1;
		}
	}

	return find_median_in_two_sorted_arrays(a,b,low_a,high_a,low_b,high_b);
}



