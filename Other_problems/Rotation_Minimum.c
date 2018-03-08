#include <stdio.h>


int main()
{

/*                        /              */
/*                       / |             */
/*                      /  |             */
/*                         |   /         */
/*                         |  /          */
/*                         | /           */
/*        rotation point-> |/            */

	/*Suppose distinct elements*/		/*Indistinct elements will be considered later*/		
	int a[]={11,14,1,2,3,5,6,7};			
	int size_a=sizeof(a)/sizeof(a[0]);		
							
	int low=0;					
	int high=size_a-1;				
	int mid=(low+high)/2;				        

	while(a[low]>a[high]&&mid>low)
	{

		if(a[mid]<a[low])			/*The rotation point is in a[low..mid], because inversion exists*/
		{
			high=mid;			/*mid must be included, because mid is possibly the rotation point*/
		}
		else if(a[mid]>a[low])			/*The rotation point is in a[mid..high], because inversion doesn't exist in a[mid..low]*/
		{
			low=mid;	
		}
		else	/*a[mid]==a[low]*/				/*a[mid] and a[low] is the same element, boundary condition*/
		{

		}

		mid=(low+high)/2;
	}

	if(a[low]>a[high])
	{
		low=high;
	}

	printf("The smallest element is %d\r\n",a[low]);

}



