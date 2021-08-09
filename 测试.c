#include<stdio.h>
#include <conio.h>
int key='w'; 
void main(){
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
		}
//		if(t==' '){
//			pause(); //如果输入的是空格 
//		}
		               //令key =t输入进去的数据（设定为WASD分别是上左下右方向控制）
	}
} 
