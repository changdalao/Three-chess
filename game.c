#include "game.h"
void InitiaArr(char arr[ROW][COL],int row,int col)   //初始化棋盘
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			arr[i][j]=' ';
	}
}
void DisplayShow(char arr[ROW][COL],int row,int col)   //打印棋盘
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		
		printf(" %c | %c | %c \n",arr[i][0],arr[i][1],arr[i][2]);
		if(i!=row-1)
			printf("---|---|---\n");
	}
}
void ComputerMove(char arr[ROW][COL],int row,int col)		//computer下
{
	int x=0,y=0;
	Sleep(1000);
	printf("ComputerMove>\n");
	while(1)
	{
		x=rand()%row;
		y=rand()%col;
		if(arr[x][y]==' ')
		{
			arr[x][y]='X';
			break;
		}
	}
}
void PlayerMove(char arr[ROW][COL],int row,int col)		//player下
{
	int x=0,y=0;
	printf("\n");
	printf("PlayerMove>\n");
	while(1)
	{
		printf("Please enter the coordinates(x,y)>");
		scanf("%d,%d",&x,&y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if(arr[x-1][y-1]==' ')
			{
				arr[x-1][y-1]='*';
				break;
			}
			else
			{
				printf("Position is occupied!\n");
			}
		}
		else
		{
			printf("Coordinates are not legal!\n");
		}
	}
}

static int draw(char arr[ROW][COL],int row,int col)			//平局判断
{
	int i=0,j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(arr[i][j]==' ')
				return 0;
		}
	}
	return 1;
}
char IfWin(char arr[ROW][COL],int row,int col)
{
	int i=0;
	for(i=0;i<row;i++)
	{
		if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][0]!=' ')
			return arr[i][0];
	} 
	for(i=0;i<col;i++)
	{
		if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]&&arr[0][i]!=' ')
			return arr[0][i];
	}
	if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[0][0]!=' ')
	{
		return arr[0][0];
	}
	if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[1][1]!=' ')
	{
		return arr[0][2];
	}
	if(draw(arr, row, col)) 
	{        
		return 'q';    
	}   
	return ' '; 
}
