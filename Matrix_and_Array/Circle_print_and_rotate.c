#include <stdio.h>

#define M 4
#define N 4
#define INPUT 0
#define OUTPUT 1

int circle(int a[M][N],int *c,int *size,int layer,int in_or_out);	
int switch_subarray(int a[],int head,int mid,int tail);

int main()
{

	/*Find the element which appears onces, while all other elements appear k times*/
	int a[M][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	int c[50]={0};
	int size_c=sizeof(c)/sizeof(c[0]);
	int i=0,j=0;

	circle(a,c,&size_c,1,OUTPUT);
	switch_subarray(c,0,size_c-4,size_c-1);
	circle(a,c,&size_c,1,INPUT);

	printf("Rotate the matrix by 90 degree clockwise:\r\n");
	for(i=0;i<M;++i)
	{
		for(j=0;j<N;++j)
		{
			printf("%2d  ",a[i][j]);
		}
		printf("\r\n");
	}

	//switch_subarray(c,0,size_c-5,size_c-1);
}

/*This function has some limitations dealing with various M and N, fix it later*/
int circle(int a[M][N],int *c,int *size,int layer,int in_or_out)
{
	int i=layer-1,j=layer-2;
	int counter=0;

	if(layer<=0||j>=(M-layer)||i>=(N-layer))
	{
		return -1;
	}
	
	while(j<(M-layer)&&(counter<(*size)))
	{
		if(in_or_out==OUTPUT)
		{
			c[counter++]=a[i][++j];
		}
		else
		{
			a[i][++j]=c[counter++];
		}
	}

	while(i<(N-layer)&&(counter<(*size)))
	{
		if(in_or_out==OUTPUT)
		{
			c[counter++]=a[++i][j];
		}
		else
		{
			a[++i][j]=c[counter++];
		}
	}

	while((j>(layer-1))&&(counter<(*size)))
	{
		if(in_or_out==OUTPUT)
		{
			c[counter++]=a[i][--j];
		}
		else
		{
			a[i][--j]=c[counter++];
		}
	}

	while((i>layer)&&(counter<(*size)))
	{
		if(in_or_out==OUTPUT)
		{
			c[counter++]=a[--i][j];
		}
		else
		{
			a[--i][j]=c[counter++];
		}
	}

	(*size)=counter;

}

/*Switch the position of two parts of the array: from a[head..mid,mid+1..tail] to a[mid+1..tail,head..mid]*/
/*Without additional space requirements*/
int switch_subarray(int a[],int head,int mid,int tail)
{
	int i=0,j=0,temp;

	/*Inverse elements a[head..mid]*/
	i=head;
	j=mid;
	while(i<j)
	{
		temp=a[i];
		a[i++]=a[j];
		a[j--]=temp;
	}

	/*Inverse elements a[mid+1..tail]*/
	i=mid+1;
	j=tail;
	while(i<j)
	{
		temp=a[i];
		a[i++]=a[j];
		a[j--]=temp;
	}

	/*Inverse elements a[head..tail]*/
	i=head;
	j=tail;
	while(i<j)
	{
		temp=a[i];
		a[i++]=a[j];
		a[j--]=temp;
	}
}

