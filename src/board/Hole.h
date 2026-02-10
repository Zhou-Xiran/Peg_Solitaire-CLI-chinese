#ifndef SQUARE
#define SQUARE
class Hole                     //格子
{
private:
        bool hasPeg;      //存在棋子      
        //char coord[2];           //坐标（采用笛卡尔坐标系）
public:
        Hole();                //构造函数
	//void setCoord(char,char);//设置坐标
        //char getCoord(char);     //得到坐标
        bool getHasPeg();          //得到有无棋子
        void removePeg();             //移除棋子
        void putPeg();             //添加棋子
        bool check_removePeg();          //检测能否添加棋子
        bool check_putPeg();          //检测能否移除棋子
       
};
#endif
