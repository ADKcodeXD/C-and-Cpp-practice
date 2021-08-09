#include <stdio.h>
#define PI 3.14
int fun(int a,int b)
{
	int qian,bai,shi,ge,c;
	qian=a/10;
	bai=b/10;
	shi=a%10;
	ge=b%10;
	c=qian*1000+bai*100+shi*10+ge;
	return c;
}
void main()
{
	int a,b,c;
	printf("«Î ‰»Îa∫Õb°£\n");
	scanf("%d %d",&a,&b);
	c=fun(a,b);
	printf("c=%d",c);
}

