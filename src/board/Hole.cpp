#include"Hole.h"
Hole::Hole()
{
	hasPeg=1;
}
/*void Hole::setCoord(char a,char b)
{
	coord[0]=a; 
	coord[1]=b;
}
char Hole::getCoord(char d)
{
	return coord[d];
}*/
bool Hole::getHasPeg()
{
	return hasPeg;
}
void Hole::removePeg()               //removePeg()就是移除棋子
{
	if(hasPeg)                       //如果：该格子有棋子（hasPeg为1），则：
	{
		hasPeg=0;                    //移除该棋子（将hasPeg设为0）
	}
}
void Hole::putPeg()              //putPeg()就是添加棋子
{
	if(!hasPeg)                   //如果：该格子没有棋子（hasPeg为0），则：
	{
		hasPeg=1;                 //在该处添加棋子（将hasPeg设为1)
	}
}
bool Hole::check_removePeg()
{
	if(hasPeg)
		return 1;
	else
		return 0;
}
bool Hole::check_putPeg()
{
	if(!hasPeg)
		return 1;
	else
		return 0;
}
