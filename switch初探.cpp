#include <stdio.h>
#include <windows.h>
int main() 
{
	int x=1,t=0,p;

	while(t<50){
	int sushu=1;
	for(p=2;p<x;p++)
	{
	if(x%p==0){
	sushu=0;
	break;}	
	}
	x++;
	if (sushu==1)
	{t++;
	printf("%d\n",x);}
	}
	
}
//首先判断一个数是否素数
//定义一个p，使x%p==0； 
//（定义一个x，x递增，每次递增判断一次） 
//是，输出；不是，不输出
//然后通过一个循环，循环五十次（定义一个t，表示次数） 
//输出五十个素数。 
