#include <stdio.h>

#define M 4
#define N 4

int main()
{
	int m[M][N]={{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
	int c[M][N]={0};	/*Cost*/

	int i=0,j=0;
	int temp=0,min=0;
	int path[M+N]={0};
	int index=0;

	c[0][0]=m[0][0];

	/*Compute first column of c*/
	for(i=1;i<M;++i)
	{
		c[i][0]=c[i-1][0]+m[i][0];
	}

	/*Compute first row of c*/
	for(j=1;j<N;++j)
	{
		c[0][j]=c[0][j-1]+m[0][j];
	}

	/*Compute other element until c[M][N]*/
	for(i=1;i<M;++i)
	{
		for(j=1;j<N;++j)
		{
			if(c[i][j-1]<c[i-1][j])
			{
				c[i][j]=c[i][j-1];
			}
			else
			{
				c[i][j]=c[i-1][j];
			}

			c[i][j]+=m[i][j];
		}	
	}

	i=M-1;
	j=N-1;
	index=0;

	path[index++]=m[i][j];
	/*Choose the smaller element of the left and the upper*/
	while(i>0&&j>0)
	{
		if(c[i][j-1]<c[i-1][j])
		{
			path[index++]=m[i][--j];
		}
		else
		{
			path[index++]=m[--i][j];
		}
	}

	/*Fill rest column if exists*/
	while(i>0)
	{
		path[index++]=m[--i][0];

	}

	/*Fill rest row if exitsts*/
	while(j>0)
	{
		path[index++]=m[0][--j];
	}

	/*Print result*/
	printf("The minimum path of the matrix is:\r\n");
	for(i=index-1;i>=0;--i)
	{
		printf("%d,",path[i]);
	}
	printf("\b \r\n");
	return 0;

}
