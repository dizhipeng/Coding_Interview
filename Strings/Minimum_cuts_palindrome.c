#include <stdio.h>

#define MAX_LEN 50

int main()
{

	char str[]="BBAACDCADCDDADD";
	char palindrome[MAX_LEN]={0};
	int len=sizeof(str)/sizeof(str[0])-2;
	int i=0,j=0,l=0,min=0,pos=0;
	int dp[MAX_LEN][MAX_LEN]={0};	/*dp[i][j] means whether str[i..j] is a palindrome; 1 indicates it is, 0 otherwise*/
	int cuts[MAX_LEN]={0};		/*dp1[i] means the minmum cuts to make every substring of str[0..i] a palindrome*/
	int position[MAX_LEN]={0};		/*The position of the cut at each step*/
	int start=0,end=len;

				/*Init: dp[i][i]=1*/
	for(i=0;i<len;++i)	/*dp[i][i+1]=1 if str[i]!=str[i+1], 0 otherwise*/
	{
		dp[i][i]=1;	/*one letter is a trivial palindrome;*/

		if(str[i]==str[i+1])
		{
			dp[i][i+1]=1;	/*Two same characters are themselves palindrome*/
		}
		else
		{
			dp[i][i+1]=0;	/*Two different characters are not palindrome*/
		}
	}
	dp[i][i]=1;
		
	/*dp[i][j]=dp[i+1][j-1] if str[i]==str[j]*/
	/*=0 if str[i]!=str[j]*/
	for(l=2;l<=len;++l)
	{
		i=0;
		for(j=i+l;j<=len;j=(++i)+l)
		{
			if(str[i]==str[j])
			{
				dp[i][j]=dp[i+1][j-1];	/*If str[i+1..j-1] is a palindrome then str[i..j] is also one. Otherwise str[i..j] is not*/
			}
			else
			{
				dp[i][j]=0;		/*str[i..j] is not palindrome because str[i] and str[j] are different characters*/
				
			}
		}
	}

	for(i=0;i<=len;++i)
	{
		if(dp[0][i]==1)	/*str[0..i] is already a palidrome, don't need any cut. Include i=0*/
		{
			//printf("str[0,%d] is palindrome\r\n",i);
			cuts[i]=0;
			position[i]=-1;
			continue;
		}
#if 0
		if(dp[0][i-1]==1)
		{
			dp1[i]=1;
			cut[i]=i;
			continue;	
		}
#endif
		min=cuts[i-1]+1;	/*To begin with, cut at position i*/
		pos=i;

		for(j=i-1;j>=0;--j)		/*Try every possible cut position to find the minimum cut*/
		{
			if( (j==i-1 || dp[j+1][i-1]==1) && str[i]==str[j])	/*Meaning str[i..j] is a palindrome*/
			{
				if(cuts[j-1]+1<min)	/*Find a smaller cut at position j*/
				{
					min=cuts[j-1]+1;
					pos=j;
				}
			}
		}

		cuts[i]=min;
		position[i]=pos;
	}

	/*Print every cut in the palindrome string based on the position[i]*/
	start=pos;	/*The begin character of the current cut*/
	end=len;	/*End of the string*/
	pos=MAX_LEN-1;	/*Record the position of the palindrome*/
	while(start>=0)
	{
		for(i=end;i>=start;--i)
		{
			palindrome[--pos]=str[i];
		}
		palindrome[--pos]=' ';

		end=start-1;		/*The previous cut start[start..end]*/
		start=position[end];

	}

	for(i=end;i>=0;--i)
	{
		palindrome[--pos]=str[i];
	}

	/*The final result*/
	printf("The minimum palindrome cuts for the string:\r\n%s\r\n",palindrome+pos);

}
