#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> //设置随机数所需头文件
#include <conio.h> //监控输入按键的所需头文件（kbhit） 
#define width 60// 地图宽度
#define high 30// 地图高度 
#define snakemax 30// 蛇的最大节数
//●代表食物  ■代表蛇身 □代表边框
//函数声明
void drawmap();
void createfood();
void input();
void gotoxy(int x,int y);
int menu();
void speed();
int death();
void help();
int win();
void pause();
//全局变量 按键初始化 移动方向改变
int  key='w';//初始方向往上 
int change=0; //判断方向是否改变 //后来基本没用到 

// 记录食物坐标的结构体 
struct{
	int x;
	int y;
}food; 

//记录蛇的坐标及信息的结构体 
struct{
	int x[snakemax];
	int y[snakemax];
	int len;
	int speed; 
}snake;

int main ()// 主函数实现 
{
	//设定窗口大小 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rc;
    rc.Left = 5;
    rc.Top = 5;
    rc.Right = width+50;
    rc.Bottom = high+8;
  
    SetConsoleWindowInfo(hOut, TRUE, &rc);
	int t;
	A:if(menu()){
		exit(0);
	}
	drawmap();
	while(1){
	input();
	speed();
	Sleep(snake.speed);//利用Sleep来控制小蛇的速度
	createfood();
	if(!death()){
		break;
	} 
	if(win()){
	system("cls");
	gotoxy(width/2,high/2);
    printf("恭喜你赢得游戏\n");
    printf("\t\t请按1重新开始游戏，按其他键退出游戏");
    while(1){
	if(kbhit()){
    	fflush(stdin);
        t=getch();
    	if(t=='1'){
    		system("cls");
    		goto A;
    	}else 
    	break;
    }
    }
    gotoxy(0,high); 
    return;
	} 
    }
    system("cls");
    gotoxy(width/2,high/2);
    printf("game over\n");
    printf("\t\t请按1重新开始游戏，按其他键退出游戏");
    while(1){
	if(kbhit()){
    	fflush(stdin);
        t=getch();
    	if(t=='1'){
    		system("cls");
    		goto A;
    	}else 
    	break;
    }
    }
	gotoxy(0,high);
	system("pause");
	return 0;
}

//模块功能设计（函数设计） 

//初始化地图模块 
void drawmap(){
	//因为上述符号 一个符号两字节
	//初始化食物
	srand(time(NULL));
	while(1){
	food.x=rand()%(width-4)+2;
	food.y=rand()%(high-2)+1;
    if(food.x%2==0){
    	break;
      }
	}
	gotoxy(food.x,food.y);
    printf("●");
	//边框绘制
	int i,k;
	for(i=0;i<=high;i++){
		gotoxy(0,i);
		printf("□");
		gotoxy(width,i);
		printf("□");
	} 
	for (k=0;k<=width;k+=2){
		gotoxy(k,0);
		printf("□");
		gotoxy(k,high);
		printf("□");
	}
	printf("\n");
	//初始化小蛇的位置 速度 长度
	snake.len=3;
	snake.speed=500; 
	//开始蛇头在屏幕中间
	snake.x[0]=width/2;
	snake.y[0]=high/2;
	gotoxy(snake.x[0],snake.y[0]);
	printf("■");
	//剩下蛇的身体
	for(i=1;i<snake.len;i++){
		snake.x[i]=snake.x[i-1]+2;
		snake.y[i]=snake.y[i-1];
		gotoxy(snake.x[i],snake.y[i]);
		printf("■");
	} 
} 
// 食物的产生
void createfood(){
	//首先判断蛇是否吃了食物
	//因为蛇头所代表的 符号占两个字节 所以坐标必须是偶数。 
	//且不能刷在蛇身上
	if(food.x==snake.x[0]&&food.y==snake.y[0]){
	while(1){
	int i;
	int flag=1;//标志，满足不在蛇身上的标志 
	srand(time(NULL));//随机函数种子
	food.x=rand()%(width-4)+2;
	food.y=rand()%(high-2)+1;
	for(i=0;i<snake.len;i++){
		if(snake.x[i]==food.x&&snake.y[i]==food.y){
			flag=0;
			break;//跳出for循环 重新生成坐标or直接进入if判断跳出死循环 
		}
	}
	if(flag=1&&food.x%2!=0){
		food.x++;
		break;
	}
	if(flag=1&&food.x%2==0){
		break;//跳出死循环 
	}
  }
  gotoxy(food.x,food.y);
  printf("●");
  snake.len++;
 } 
}
// 输入 按键处理 
void input(){
	int i;int t;
	if(_kbhit())//利用kbhit来读取键盘按键的数据 
	{
	    fflush(stdin);//及时清空缓存区 以免妨碍下一个的按键接收（快速按键）
	    t=_getch(); 
	    //判断是否是相反的键 
		if((t=='w'||t=='W')&&(key!='s'&&key!='S')){
			key=t;
		}else
		if((t=='s'||t=='S')&&(key!='w'&&key!='W')){
			key=t;
		}else
		if((t=='a'||t=='A')&&(key!='d'&&key!='D')){
			key=t;
		}else
		if((t=='d'||t=='D')&&(key!='a'&&key!='A')){
			key=t;
		}else
		if(t==' '){
			pause();//如果输入的是空格
		}
	//令key =t输入进去的数据（设定为WASD分别是上左下右方向控制）
	}
	// 若不输入 或者输入无效 自动以key的初始值来执行 
//	if(!change){
		gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
		printf("  ");//最后的一格擦除 
//	} 
	//剩下的往前挪动
	for (i=snake.len-1;i>0;i--){
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	} 
	//移动方向的处理
	switch(key){
		case 'w':
		case 'W':
			snake.y[0]--;
			break;
		case 's':
		case 'S':
			snake.y[0]++;
		    break;
		case 'a':
		case 'A':
			snake.x[0]-=2;
		    break;
		case 'd':
		case 'D':
			snake.x[0]+=2;
		    break;
	} 
    gotoxy(snake.x[0],snake.y[0]);
	printf("■");
	gotoxy(width+6,high/3);
	printf("您的得分目前为%d",snake.len-3);
	gotoxy(width+6,high*2/3);
	printf("当前速度为%d",500-snake.speed);
	gotoxy(width+6,high);
	printf("小提示：吃的越多速度越快");
} 
//死亡判断
int death(){
	int flag=1;
	if(snake.x[0]==0||snake.x[0]==width-2||snake.y[0]==0||snake.y[0]==high-1){
		flag=0;//判断蛇头是否撞墙  -2是因为每个图形占两个字节 
	} 
	//判断蛇是否撞了自身
	int i;
	for (i=1;i<snake.len-1;i++){
		if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0]){
			flag=0;
		}
	}
	return flag;
}
//贪吃蛇的速度设置(随着长度增长，速度变快)
//每吃一个食物，速度增快20，上限是100
void speed(){
	if(snake.speed>=100){
	snake.speed=500-(snake.len-3)*20;
    }
}
//开始菜单
int menu(){
	int key2=' '; 
	gotoxy(0,high/2-8);
	printf("\t***************贪吃蛇ver1.0****************\n");
	printf("\t****************1.开始游戏*****************\n");
	printf("\t****************2.帮助*********************\n");
	printf("\t****************3.退出游戏*****************\n");
	//设置一个死循环，不输入按键将不执行任何操作 
	while(1){
	if(_kbhit()) 
	{
	    fflush(stdin);
	    key2=_getch();
	    break;	    
	}
	}
	if(key2=='1'){
		system("cls");
		return 0;
	}else if(key2=='2'){
		system("cls");
		help();
		return 0;
	}else {
		system("cls");
		gotoxy(0,high/2-4);
		printf("游戏结束"); 
		return 1;
	}
  }
// 帮助菜单
void help(){
	gotoxy(0,high/2-4);
	printf("\t****************该游戏玩法很简单*************\n");
	printf("\t*******WASD分别控制小蛇的上左下右方向********\n");
	printf("\t**********游戏中可以按下空格键暂停***********\n");
	printf("\t***当您吃的食物达到一定量的时候将会赢得游戏**\n");
	printf("\t************按下任意键开始游戏***************\n");
	system("pause");
	system("cls");
}
//暂停系统 
void pause()
{
    gotoxy(width+2,high/2);
    printf("您已暂停，再次按下任意键可继续游戏");
	while(1)
	{
		//如果有按键 就直接跳出循环 
		if(kbhit()){
			fflush(stdin);
			gotoxy(width+2,high/2);
			printf("                                     ");//把提示语擦除 
			break; 
		}
	} 
} 
//胜利系统 
int win(){
	if(snake.len==snakemax){
		return 1;
	} 
	return 0;
}
//利用win32  api 设置控制台光标的位置  使得能够获得坐标 并在坐标处打印输出 
void gotoxy(int x,int y){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获得句柄 
	COORD coord;//定义coord结构体 
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(handle,coord);
}



