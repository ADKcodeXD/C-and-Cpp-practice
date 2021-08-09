#include <stdio.h>
int main()
{
	int a[5]={1,3,5,7,9},b[6];
	int cha;int i,j;
	scanf("%d",&cha);
	for(i=0,j=0;i<5;j++,i++){
		b[j]=a[i];
		if(cha>a[i]&&cha<a[i+1]||cha==a[i]){
			b[j]=a[i];
			b[j+1]=cha;
			j++;
		}
	}
	for(j=0;j<6;j++){
	printf("%d ",b[j]);
   }
} 
