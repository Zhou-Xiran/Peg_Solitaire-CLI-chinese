#include<iostream>
#include<fstream>
#include"board/Hole.h"
#include"other_functions/other_functions.h"
#include"board/board.h"
#include"config.h"


bool no_gameEnd=1;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::flush;
	using std::string;
	using std::ifstream;
	using std::ios;

	board[16].removePeg();

	cout<<"输入：“begin”开始游戏；\n"
	    <<"输入：“END”结束游戏；\n"
            <<"输入：“How to play?”查看玩法。"<<endl;
	char firstLetter;
	firstLetter=cin.get();
	scanf("%*[^\n]");
	switch(firstLetter)
	{
		case'b':
		{
			char operation;				//操作
			char n;					//纵坐标
			char m;					//横坐标
			char o,p;
			char moves=-1;				//步数
			char theLandingHole_index=100;		//将要跳到的位置（board下标）
			char thePegToBeJumped_index;		//将要跳过的位置（board下标）
			char theJumpingPeg_sOldPosition_index;	//要跳的棋子（board下标）
			char theJumpingPeg_sNewPosition_index;	//跳了的棋子的新位置（board下标）
			bool no_error=1;			//没有错误
			cout<<"    X X X\n"
			    <<"    X X X\n"
			    <<"X X X X X X X\n"
			    <<"X X X O X X X\n"
			    <<"X X X X X X X\n"
			    <<"    X X X\n"
			    <<"    X X X"
			    <<endl;
			while(no_gameEnd)
			{
				cin>>m>>n>>operation;       //通过用户输入获取位置和操作
				bool EN=m=='E'&&n=='N';
				m-='0';
				n-='0';
				if(((n==0||n==1||n==5||n==6)&&(m==2||m==3||m==4))||((n==2||n==3||n==4)&&(m==0||m==1||m==2||m==3||m==4||m==5||m==6))||EN)
				{
					char theJumpingPeg_sOldPosition_index=conversionFromCoordToIndex(m,n);

					switch(operation)
					{
						//当用户输入的操作为"l"（左跳）时：
						case'l': 
							o=m-1;
							p=m-2;
							if(!(((m==2||m==3)&&(n==0||n==1||n==5||n==6))
							   ||((m==0||m==1)&&(n==2||n==3||n==4))))
							{
								bool check1,check2,check3;
								theLandingHole_index=conversionFromCoordToIndex(p,n);
								thePegToBeJumped_index=conversionFromCoordToIndex(o,n);
								check1=board[theJumpingPeg_sOldPosition_index].check_removePeg(); 
								check2=board[thePegToBeJumped_index].check_removePeg();
								check3=board[theLandingHole_index].check_putPeg();
								if(check1&&check2&&check3)
								{
									theJumpingPeg_sNewPosition_index=theLandingHole_index;
									board[theJumpingPeg_sOldPosition_index].removePeg();
									board[thePegToBeJumped_index].removePeg();
									board[theLandingHole_index].putPeg();
								}
								else
								{
									no_error=0;
									cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
								}
							}
							else
							{
								no_error=0;
								cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
							}
							break;
						//当用户输入的操作为"r"（右跳）时：
						case'r':
							o=m+1;
							p=m+2;
							if(!(((m==3||m==4)&&(n==0||n==1||m==5||m==6))
							   ||((m==5||m==6)&&(n==2||n==3||n==4))))
							{
								bool check1,check2,check3;
								theLandingHole_index=conversionFromCoordToIndex(p,n);
								thePegToBeJumped_index=conversionFromCoordToIndex(o,n);
								check1=board[theJumpingPeg_sOldPosition_index].check_removePeg(); 
								check2=board[thePegToBeJumped_index].check_removePeg();
								check3=board[theLandingHole_index].check_putPeg();
								if(check1&&check2&&check3)
								{
									theJumpingPeg_sNewPosition_index=theLandingHole_index;
									board[theJumpingPeg_sOldPosition_index].removePeg();
									board[thePegToBeJumped_index].removePeg();
									board[theLandingHole_index].putPeg();
								}
								else
								{
									no_error=0;
									cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
								}
							}
							else
							{
								no_error=0;
								cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
							}
							break;
						//当用户输入的操作为"u"（上跳）时：
						case'u':
							o=n+1;
							p=n+2;
							if(!(((m==0||m==1||m==5||m==6)&&(n==3||n==4))
							   ||((m==2||m==3||m==4)&&(n==5||n==6))))
							{
								theLandingHole_index=conversionFromCoordToIndex(m,p);
								thePegToBeJumped_index=conversionFromCoordToIndex(m,o);
								bool check1,check2,check3;    
								check1=board[theJumpingPeg_sOldPosition_index].check_removePeg(); 
								check2=board[thePegToBeJumped_index].check_removePeg();
								check3=board[theLandingHole_index].check_putPeg();
								if(check1&&check2&&check3)
								{
									theJumpingPeg_sNewPosition_index=theLandingHole_index;
									board[theJumpingPeg_sOldPosition_index].removePeg();
									board[thePegToBeJumped_index].removePeg();
									board[theLandingHole_index].putPeg();
								}
								else
								{
									no_error=0;
									cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
								}
							}
							else
							{
								no_error=0;
								cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
							}
							break;
						//当用户输入的操作为"d"（下跳）时：
						case'd':
							o=n-1;
							p=n-2;
							if(!(((m==2||m==3||m==4)&&(n==0||n==1))
							   ||((m==0||m==1||m==5||m==6)&&(n==2||m==3))))
							{
								theLandingHole_index=conversionFromCoordToIndex(m,p);
								thePegToBeJumped_index=conversionFromCoordToIndex(m,o);
								bool check1,check2,check3;    
								check1=board[theJumpingPeg_sOldPosition_index].check_removePeg(); 
								check2=board[thePegToBeJumped_index].check_removePeg();
								check3=board[theLandingHole_index].check_putPeg();
								if(check1&&check2&&check3)
								{
									theJumpingPeg_sNewPosition_index=theLandingHole_index;
									board[theJumpingPeg_sOldPosition_index].removePeg();
									board[thePegToBeJumped_index].removePeg();
									board[theLandingHole_index].putPeg();
								}
								else
								{
									no_error=0;
									cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
								}
							}
							else
							{
								no_error=0;
								cout<<"错误：该位置无法执行此操作\e[1A\r   \r"<<flush;
							}
							break;
						case'D':
							if(EN)
							{
								no_gameEnd=0;
							}
							else
							{
								no_error=0;
								cout<<"错误：没有该操作\e[1A\r   \r"<<flush;
							}
							break;
						default:
							no_error=0;
							cout<<"错误：没有该操作\e[1A\r   \r"<<flush;
					}


				}
				else
				{
					no_error=0;
					cout<<"错误：该位置不存在\e[1A\r   \r"<<flush;
				}
				if(no_error&&no_gameEnd)
				{
					cout<<"\e[2K\r"
					    <<"    "<<output(30)<<' '<<output(31)<<' '<<output(32)<<'\n'
					    <<"    "<<output(27)<<' '<<output(28)<<' '<<output(29)<<'\n'
					    <<output(20)<<' '<<output(21)<<' '<<output(22)<<' '<<output(23)<<' '<<output(24)<<' '<<output(25)<<' '<<output(26)<<'\n'
					    <<output(13)<<' '<<output(14)<<' '<<output(15)<<' '<<output(16)<<' '<<output(17)<<' '<<output(18)<<' '<<output(19)<<'\n'
					    <<output(6)<<' '<<output(7)<<' '<<output(8)<<' '<<output(9)<<' '<<output(10)<<' '<<output(11)<<' '<<output(12)<<'\n'
					    <<"    "<<output(3)<<' '<<output(4)<<' '<<output(5)<<'\n'
					    <<"    "<<output(0)<<' '<<output(1)<<' '<<output(2)<<endl;           //输出棋盘当前状态
				}
				if(theJumpingPeg_sOldPosition_index!=theJumpingPeg_sNewPosition_index&&no_error)
				{
					++moves;
				}
				no_error=1;
				//检测游戏是否结束（该功能尚未完成）：
/*			        for(int i=0;i<33;++i)
				{
					if((i==0||i==3||(i>5&&i<11)||(i>12&&i<18)||(i>19&&i<25)||i==27||i==30)
					&& !(board[i].getHasPeg()&&board[i+1].getHasPeg()&&!board[i+2].getHasPeg())|| !(!board[i].getHasPeg()&&board[i+1].getHasPeg()&&board[i+2].getHasPeg()))
					{
						no_gameEnd=0;
					}
					if(i>12&&i<20)
					{
						if(!(board[i].getHasPeg()&&(board[i+7].getHasPeg()!=board[i-7].getHasPeg())))
						{
							no_gameEnd=0;
						}
					}
					if(i>14&&i<18)
					{
						if(!((board[i+12].getHasPeg()&&(board[i+7].getHasPeg()!=board[i+15].getHasPeg()))||(board[i-12].getHasPeg()&&(board[i-7].getHasPeg()!=board[i-15].getHasPeg()))))
						{
							no_gameEnd=0;
						}
					}
				}*/

			}
			{
				int remainingPegs=0;
				for(int i=0;i<33;++i)
				{
					if(board[i].getHasPeg())
					{
						++remainingPegs;
					}
				}
				cout<<"游戏结束，共"<<(int)moves<<"步，剩余"<<remainingPegs<<"颗棋子";
				if(remainingPegs==1&&board[16].getHasPeg())
				{
					cout<<"，且在中心！"<<endl;
				}
				else
				{
					cout<<"。"<<endl;
				}
			}
			break;
		}
		case'H':
			ifstream howToPlay(DOCS_DIR"/How_to_play.txt", ios::in);
			if(howToPlay.is_open())
			{
				string line;
				while(getline(howToPlay,line))
				{
					cout<<line<<'\n';
				}
				cout<<flush;
			}
			break;
	}
        return 0;
}
