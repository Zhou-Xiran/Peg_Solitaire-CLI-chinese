#include"other_functions.h"
#include"../board/Hole.h"
#include"../board/board.h"
//输出格子当前状态：
char output(char g)
{
        char ox;
        switch(board[g].getHasPeg())
        {
        case 0:
                ox='O';
                break;
        case 1:
                ox='X';
                break;
        }
        return ox;
}

//位置对应下标
char conversionFromCoordToIndex(char x,char y)
{
        /*register */char h/*=0*/;
	if(y==0||y==1)
	{
		h=y*3+x-2;
	}
	else if(y==2||y==3||y==4)
	{
		h=(y-2)*7+x+6;
	}
	else if(y==5||y==6)
	{
		h=(y-5)*3+x+25;
	}
        return h;
}

