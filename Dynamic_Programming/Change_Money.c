#include <stdio.h>

#define MAX_KIND	10
#define MAX_AIM		50
#define POS_INFI	(0xffffff)

int main(void)
{
	int aim=11;
	int coins[]={2,3,5,10};
	int coins_num=sizeof(coins)/sizeof(coins[0]);
	int i=0,j=0,rest=0;

	/*How many kinds[i][j] of change method using coins[0..i] to change aim=j. Final: kinds[cois_num][aim]*/
	int kinds[MAX_KIND][MAX_AIM]={0};
	/*The minimum coins choosed in set coins[0..i] to change aim=j*/
	int min[MAX_KIND][MAX_AIM]={0};
	int change[MAX_KIND][MAX_AIM]={0};

	/*Initial: kind[i][0] for all i, all equal 1 because there is only one kind of change for 0: 0 coins*/
	for(i=0;i<coins_num;++i)
	{
		kinds[i][0]=1;
		min[i][0]=0;	/*For min,do not need any coins to change 0*/
	}
	
	/*Initial: kind[0][j] for all, calulate whether exist a change use only coins[0] for different aims=j*/
	for(j=1;j<aim;++j)
	{
		if(j%coins[0]==0)		
		{
			kinds[0][j]=1;			/*j as an aim can be changed using coins[0]*/
			min[0][j]=j/coins[0];	/*Coins used*/
		}
		else					
		{
			kinds[0][j]=0;		/*Can't change*/
			min[0][j]=POS_INFI;	/*POS_INFI means no changes*/
		}
	}

	/*Calculating general case*/
	for(i=1;i<coins_num;++i)
	{
		for(j=1;j<=aim;++j)
		{
			/*The kinds of using coins[0..i] to change aim=j is composed of:*/
			/*The kinds of don't use coins[i] to change aim=j, namely kinds[i-1][j]*/
			/*The kinds of use at least one coins[i] to change aim=j, namely kinds[i][j-] */
			rest=((j-coins[i])<0)?0:(kinds[i][j-coins[i]]);
			kinds[i][j]=kinds[i-1][j]+rest;

			/*Same as kinds[i][j], but the dp equation becomes: min{min[i][j-coins[i]],min[i-1][j]}*/	
			rest=rest=((j-coins[i])<0)?(POS_INFI):(kinds[i][j-coins[i]]+1);
			min[i][j]=(min[i-1][j]<rest)?(min[i-1][j]):rest;	/*Don't need to consider min[i][j-k*coins[i]]+k for k>1,because k=1 is always the minimum or equal*/
		}
	}

	/*Print the result*/
	printf("The are %d kinds of method to change %d using ",kinds[coins_num-1][aim],aim);

	for(i=0;i<coins_num;++i)
	{
		printf("%d,",coins[i]);
	}
	printf("\b \r\n");

	printf("The method which use the minimum coins are:\r\n");
	i=coins_num-1;
	j=aim;
	while(i>0 && j>0)
	{
		if(min[i][j]==POS_INFI)
		{
			printf("Can't change!\r\n");
			return -1;
		}

		if(min[i][j]==min[i-1][j])
		{
			--i;
		}
		else if( (j-coins[i])>=0 && (min[i][j]==min[i-1][j]+1))
		{
			printf("%d,",coins[i]);
			j-=coins[i];
		}
		else
		{
			printf("Error!\r\n");
			return -1;
		}
	}

	
	

}
