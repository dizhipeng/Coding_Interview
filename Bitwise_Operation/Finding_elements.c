#include <stdio.h>

int addition_in_radix_n(int a,int b,int n);

int main()
{

	/*Find the element which appears onces, while all other elements appear k times*/
	int a[]={3,3,3,5,5,5,9,25,9,9,11,11,11,6,6,6};
	int size_a=sizeof(a)/sizeof(a[0]);

	/*Find two elements which appears once respectively, while all other elements appear twice*/
	int b[]={7,7,29,9,29,8,8,2,2,16,16,5,17,17};	
	int size_b=sizeof(b)/sizeof(b[0]);

	int i=0;
	int temp=0;
	int bit=0;
	int tar1=0,tar2=0;

	tar1=0;
	for(i=0;i<size_a;++i)
	{
		tar1=addition_in_radix_n(tar1,a[i],3);
	}
	printf("The element which appears only once among other elements appear k times is %d\r\n",tar1);

	for(i=0;i<size_b;++i)	/*The result is tar1^tar2, all other elements which appear twice will be 0*/
	{
		temp^=b[i];
	}
	
	bit=1;		/*Find the low '1' bit of temp, which indicactes that tar1 and tar2 differ at that bit*/
	while((temp&bit)==0)
	{		
		bit<<=1;
	}

	for(i=0;i<size_b;++i)
	{
		if(b[i]&bit)		/*Group tar1 and tar2 according to the different bit*/
		{
			tar1^=b[i];
		}
		else
		{
			tar2^=b[i];
		}
	}

	printf("The two elements which appear only once respectively is %d and %d\r\n",tar1,tar2);

}

/*Add number a and number b bitwise without any carry*/
int addition_in_radix_n(int a,int b,int n)
{
	int result=0;
	int weight=1;
	int digit=0;

	if(n<=0)
	{
		return -1;
	}

	while(a>0||b>0)
	{
		digit=(a%n+b%n)%n;
		digit*=weight;
		result+=digit;
		a/=n;
		b/=n;
		weight*=n;
	}

	return result;
}

