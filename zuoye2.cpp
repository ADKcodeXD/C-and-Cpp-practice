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
	printf("������Ϊ%dλ��,�������Ϊ%d",cnt,c);
} 
