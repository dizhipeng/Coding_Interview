#include <stdio.h>

#define MAX_SIZE 50

int binary_search(int a[],int low,int high,int key);

int main()
{

	char str1[]="abcdefg";
	char str2[]="bcdifeg";
	int size1=sizeof(str1)/sizeof(str1[0]);
	int size2=sizeof(str2)/sizeof(str2[0]);
	
	int c[MAX_SIZE][MAX_SIZE]={0};	/*Editing cost from str1[1..i] to str2[1..j], means empty string when i or j equals to 0*/
	int ic=2,dc=3,rc=4;			/*Cost to insert, delete and replace*/
	char operation[MAX_SIZE][MAX_SIZE]={0};
	
	int insert=0,delete=0,replace=0;
	int i=0,j=0;
	
	c[0][0]=0;
	operation[0][0]='n';
	for(i=1;i<size1;++i)	/*Edit str1[1..i] to empty string: delete i characters*/
	{
		c[i][0]=dc*i;
		operation[i][0]='d';
	}

	for(j=1;j<size2;++j)	/*Edit empty string to str2[1..j]: insert j characters*/
	{
		c[0][j]=ic*j;
		operation[0][j]='i';
	}

	for(i=1;i<size1;++i)
	{
		for(j=1;j<size2;++j)
		{
			if(str1[i-1]==str2[j-1])	/*Character at current position is equal*/
			{
				c[i][j]=c[i-1][j-1];	/*Don't need edit anything*/
				operation[i][j]='n';			
			}
			else		/*Otherwise, three choices to edit str1[1..i] to str2[1..j]*/
			{
				insert=c[i][j-1]+ic;	/*Edit str1[1..i] to str2[1..j-1], and insert character str2[j] to str1*/

				delete=c[i-1][j]+dc;	/*Edit str1[1..i-1] to str2[1..j], and remove the redundant character str1[i]*/

				replace=c[i-1][j-1]+rc;	/*Edit str1[1..i-1] to str2[1..j-1], and replace character str2[j] with str1[i]*/

				/*Find the minimum cost of these choices*/
				c[i][j]=insert;
				operation[i][j]='i';

				if(delete<insert&&delete<replace)
				{
					c[i][j]=delete;
					operation[i][j]='d';
				}
				else if(replace<insert&&replace<delete)
				{
					c[i][j]=replace;
					operation[i][j]='r';
				}
			}
		}
	}

#if 0
	for(i=0;i<size1;++i)
	{
		for(j=0;j<size2;++j)
		{
			printf("%c  ",operation[i][j]);
		}
		printf("\r\n");
	}
#endif

	printf("Editing str1=\'%s\' to str2=\'%s\' takes the following operations:\r\n",str1,str2);
	i=size1-1;
	j=size2-1;
	/*Print the edit operation accoring to array operation[i][j]*/
	while(i>0&&j>0)
	{
		switch(operation[i][j])
		{
			case 'n':		/*No operation*/
				--i;
				--j;
				break;

			case 'i':	/*Insert*/
				printf("Insert %c to str1 after position %d\r\n",str2[j-1],i-1);
				--j;
				break;
			case 'd':	/*Delete*/
				printf("Delete %c from str1 at position %d\r\n",str1[i-1],i-1);
				--i;
				break;
			case 'r':	/*Replace*/
				printf("Replace %c with %c of str1 at position %d\r\n",str1[i-1],str2[j-1],i-1);
				--i;
				--j;
				break;
			default: 
				printf("ERROR!\r\n");
				return -1;
		}
	}

	/*Output the rest operations until reach operation[0][0]*/
	while(i>0)
	{
		printf("Delete %c from str1 at position %d\r\n",str1[i-1],i-1);
		--i;
	}

	while(j>0)
	{
		printf("Insert %c to str1 after position %d\r\n",str2[j-1],i-1);
		--j;
	}


}





