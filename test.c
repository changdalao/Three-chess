#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("***1.play        2.exit***\n");
	printf("**************************\n");
}
void game()
{
	char win;
	char arr[ROW][COL]={0};
	InitiaArr(arr,ROW,COL);			//初始化棋盘
	DisplayShow(arr,ROW,COL);		//打印棋盘
	while(1)
	{
		ComputerMove(arr,ROW,COL);
		DisplayShow(arr,ROW,COL);
		win=IfWin(arr,ROW,COL);
		if(win!=' ')
			break;
		PlayerMove(arr,ROW,COL);
		DisplayShow(arr,ROW,COL);
		win=IfWin(arr,ROW,COL);
	}
	if(win=='q')
		printf("Draw!\n");
	else if(win=='X')
		printf("Computer Win!\n");
	else
		printf("Player Win!\n");
}
int main()
{
	int choose=0;
	srand((unsigned int)time(NULL));			//生成随机数
	while(1)
	{
		menu();
		printf("Please choose>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			game();
			break;
		case 2:
			printf("exit game!\n");
			return 0;
		default:
			printf("error choose!\n");
			break;
		}
	}
	return 0;
}