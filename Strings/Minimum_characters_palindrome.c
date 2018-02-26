#include <stdio.h>

#define MAX_LEN 50

int main()
{

	char str[]="A1B21C";
	char palindrome[50]={0};
	int len=sizeof(str)/sizeof(str[0])-2;
	int i=0,j=0,l=0;
	int dp[50][50]={0};	/*dp[i][j] means the cost of editing str[i..j] into palindrome, dp[0][len] is the result*/

				/*Init: dp[i][i]=0, one letter is a trivial palindrome, do not need to edit;*/
	for(i=0;i<len;++i)	/*dp[i][i+1]=1 if str[i]!=str[i+1], 0 otherwise*/
	{
		if(str[i]!=str[i+1])
		{
			dp[i][i+1]=1;	/*Add str[i] to the right or add str[i+1] to the left, cost is 1*/
		}
		else
		{
			dp[i][i+1]=0;	/*Two-letter palindrome*/
		}
	}
		
	/*dp[i][j]=dp[i-1][j-1] if str[i]==str[j]*/
	/*=min{dp[i-1][j],dp[i][j-1]}+1 if str[i]!=str[j]*/

	for(l=2;l<=len;++l)
	{
		i=0;
		for(j=i+l;j<=len;j=(++i)+l)
		{
			if(str[i]==str[j])
			{
				dp[i][j]=dp[i+1][j-1];	/*Edit str[i+1..j-1] into palindrome, then str[i..j] is automatically palindrome*/
			}
			else
			{
				if(dp[i+1][j]<dp[i][j-1])	/*Pick a minimum editing cost*/
				{
					dp[i][j]=dp[i+1][j]+1;	/*Edit str[i+1..j] into palindrome, then add str[i] to the right of str[i..j] to make it a palindrome*/
				}
				else
				{
					dp[i][j]=dp[i][j-1]+1;	/*Edit str[i..j-1] into palindrome, then add str[j] to the left of str[i..j] to make it a palindrome*/
				}
				
			}
		}
	}

	while( i>=0 && j>=0 && (j-i)>=2 )
	{
		if(str[i]!=str[j])
		{
			if(dp[i+1][j]<dp[i][j-1])	/*Editing according to dp[i][j]*/
			{
				sprintf(palindrome,"%s%c",str,str[i]);
			}
			else
			{
				sprintf(palindrome,"%c%s",str[j],str);
			}
		}
		else	/*No editing in this step*/
		{
			--i;
			--j;
		}
	}
	

}
