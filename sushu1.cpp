#include<stdio.h>
#include<windows.h>
int main()
{
	int x=1,count=0;	int i=2;
	while(count<50){
			int T=1;

	for(i=2;i<x;i++){
		if(x%i==0){
		T=0;
		break;
		}
	}
	if(T==1)
	{printf("%d  ",x);
		count++;
	}
	int b;b++;
	
	if(b%5==0)
	printf("\n");
	x++;}
} 
