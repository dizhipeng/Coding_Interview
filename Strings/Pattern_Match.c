#include <stdio.h>

#define MAX_LEN 50

int matching(char str[],char pattern[],int pos1,int pos2);

int main()
{
	/* Symbol . means any single character, symbol x* means one or more x characters*/
	char str[]="ababcc",pattern[]=".*bc*";


	printf("%d\r\n",matching(str,pattern,0,0));

}

int matching(char str[],char pattern[],int pos1,int pos2)
{
	int i=0;

	if(str[pos1]=='0' && pattern[pos2]=='0')	/*Both string and pattern are empty*/
	{
		return 0;	/*Match suceeds*/
	}
	else
	{
		return -1;	/*Match fails*/
	}

	/*Match one character*/
	if(str[pos1]==pattern[pos2] || pattern[pos2]=='.')
	{
		return matching(str,pattern,pos1+1,pos2+1);		/*Match the rest of the string*/
	}
	else if(pattern[pos2]=='*')		/*Encounter * pattern*/
	{
		i=pos1;
		while(str[i]==pattern[pos2-1] || pattern[pos2-1]=='.' )			/*The * pattern may represent multiple situations, must check all of them*/
		{
			if((matching(str,pattern,i+1,pos2+1)==0))	/*Match the rest of the string*/
			{	
				return 0;	/*If any suceeds, return*/
			}
			i++;
		}
		return -1;
	}
	else
	{
		return -1;	/*Find a mismatched character, failed*/
	}
}

#if 0	/*Check whether the patter is legal*/
int patter_legal(char pattern[])
{
	int i=0;

	while(pattern[i]!=0)
	{

	}

}
#endif
