#include <stdio.h>

#define BOARD_SIZE 8
#define BOARD_ROW BOARD_SIZE
#define BOARD_COL BOARD_SIZE

int check_position(int echec[][BOARD_SIZE],int row,int col);
int put_queen(int echec[][BOARD_COL],int row,int* num);

int main(void)
{
	int echec[BOARD_ROW][BOARD_COL]={0};
	int i=0,j=0,num=0;
#if 0
	put_queen(echec,0);	/*Find one of all the available position starting at a row*/

	printf("One possible solution:");
	for(i=0;i<BOARD_ROW;++i)
	{
		for(j=0;j<BOARD_COL;++j)
		{
			printf("%d ",echec[i][j]);
		}
		printf("\r\n");
	}
#endif
	printf("All the possible results:\r\n");
	put_queen(echec,0,&num);
	printf("The number of methods: %d\r\n",num);
}

/*Check whether position echec[row][col] is allow to put a queen*/
int check_position(int echec[][BOARD_COL],int row,int col)
{
	int i=0,j=0;

	for(i=row-1,j=1;i>=0;--i,++j)	/*Check begins at the upper row*/
	{

		if(echec[i][col]==1)				/*Check upright direct*/
		{
			return -1;				
		}

		if((col+j)<BOARD_COL && echec[i][col+j])	/*Check upper-right direction*/
		{
			return -1;
		}

		if((col-j)>=0 && echec[i][col-j])		/*Check upper-left direction*/
		{
			return -1;
		}
	}

	return 0;	/*No conflicts*/

}



/*Put the queen from a row all the way down, until all the rows has a queen*/
int put_queen(int echec[][BOARD_COL],int row,int* num)
{
	int i=0,j=0;

	if(row>=BOARD_ROW)	/*Finished*/
	{
		(*num)++;		/*Record the time of sucess*/

		/*Print the result*/
		for(i=0;i<BOARD_ROW;++i)
		{
			for(j=0;j<BOARD_COL;++j)
			{
				printf("%d ",echec[i][j]);
			}
			printf("\r\n");
		}
		printf("\r\n");
		return 0;	/*Suceed*/
	}

	for(i=0;i<BOARD_COL;++i)	/*Try every column of this row*/
	{

		if(check_position(echec,row,i)==0)	/*position echec[row][i] is available*/
		{
			echec[row][i]=1;		/*Occupy this position*/

			put_queen(echec,row+1,num);		/*Put queen from the next row until the end, if suceeded*/
			//{
				//return 0;		/*If only one method is desired, then simply return sucess after a solution is found*/
			//}

			echec[row][i]=0;		/*Clear the current queen and go on trying*/
		}
	}

	return -1;	/*All columns of this row are checked, no position for the queen, failed*/
}
