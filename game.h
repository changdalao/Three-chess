#ifndef __CAME_H__
#define __CAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ROW 3
#define COL 3

//º¯ÊýÉùÃ÷
void InitiaArr(char arr[ROW][COL],int row,int col);
void DisplayShow(char arr[ROW][COL],int row,int col);
void ComputerMove(char arr[ROW][COL],int row,int col);
void PlayerMove(char arr[ROW][COL],int row,int col);
char IfWin(char arr[ROW][COL],int row,int col);

#endif