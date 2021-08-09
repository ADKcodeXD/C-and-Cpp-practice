#include<stdio.h>
int main()
{
	char a[4]="good";int i;
	for(i=0;i<5;i++)
	{
		if(a[i]=='\0'){
		printf("yes \n");}
		printf("no \n");
	}
	printf("%s",a);
}
