#include <stdio.h>

int find_median_in_two_sorted_arrays(int a[],int b[],int size);

int main()
{

	int a[]={1,3,5,6,7,11,14};
	int b[]={2,4,8,9,10,12,13};

	int size_a=sizeof(a)/sizeof(a[0]);
	int size_b=sizeof(b)/sizeof(b[0]);

	printf("%d\r\n",find_median_in_two_sorted_arrays(a,b,size_a-1));

}

int find_median_in_two_sorted_arrays(int a[],int b[],int size)
{
	int high1=size,high2=size;
	int low1=0,low2=0;
	int mid1=0,mid2=0;
	
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




