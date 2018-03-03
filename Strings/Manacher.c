#include <stdio.h>

#define MAX_LEN 50

int main()
{

	char str[]="abc1234321ab";
	char str_exp[MAX_LEN]={0};	/*Expand the string by # to handle uniformly the odd and even situation*/

	int pal_len[MAX_LEN]={0};	/*The range of every character as the center that forms a palindrome*/
	int range=0,center=0;		/*The rightmost range that is reached by any known palindrome,and the center of that palindorem*/

	int i=0,j=0,l=0;
	int boundary=0;

	/*Expand the origin string*/
	for(i=0,l=0;str[i]!=0;++i)
	{
		str_exp[l++]=str[i];
		str_exp[l++]='#';
	}

	for(i=0,range=-1;str_exp[i]!=0;++i)
	{

		if(range<i)	/*The range is not covered the current character, has to calculate manuly*/
		{
			j=1;
			while((i-j>=0)&&(str_exp[i+j]!=0)&&str_exp[i-j]==str_exp[i+j])
			{
				j++;
			}
			
			pal_len[i]=j-1;

			if((i+j-1)>range)
			{
				range=i+j-1;
				center=i;
			}
		}
		else
		{
			/*Three case based on the boundary condition*/
			boundary=pal_len[2*center-i];

			if(range<boundary)
			{

			}
			else if(boundary>range)
			{

			}
			else
			{

			}
		}
	}
	//printf("%s\r\n",str_exp);
	

}
