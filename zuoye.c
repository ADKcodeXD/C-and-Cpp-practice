#include <stdio.h>
int strcmp(char *p1,char *p2)
{
	int result;
	while(*p1==*p2&&*p1!='\0'&&*p2!='\0'){
		p1++;
		p2++;
	}
	if(*p1==*p2&&*p1=='\0'&&*p2=='\0'){
		result=0;
	}else
	if(*p1-*p2>0){
		result=1;
	}else
	if(*p1-*p2<0){
		result=-1;
	}
	return result;
}
int main()
{
	char a[10],b[10];
	scanf("%s",a);
	scanf("%s",b);
	if(strcmp(a,b)>0){
		printf("frist>second");
	}else if(strcmp(a,b)==0){
		printf("frist=second");
	}else if(strcmp(a,b)<0){
		printf("frist<second");
	}
	return 0;
}
