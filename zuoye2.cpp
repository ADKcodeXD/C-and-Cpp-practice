#include<stdio.h>
int main(void){
	int a=0,b=0,c=0,cnt=0;
	scanf("%d",&a);
	while(a!=0){
		b=a%10;
		printf("%d\n",b);
		a/=10;
		cnt++;
		c=c*10+b;
	}
	printf("该数字为%d位数,逆序输出为%d",cnt,c);
} 
