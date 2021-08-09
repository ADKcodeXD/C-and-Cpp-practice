#include<stdio.h>
void paixu(int* a,int len)
{
	int temp=a[0],i,j;
	for(j=0;j<len;j++){
		for(i=0;i<len;i++){
			if(a[i]>a[i+1]){
				temp=a[i+1];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
}
void main()
{
	int len,i;
	printf("请输入数组长度。\n");
	scanf("%d",&len);
	int a[len];
	printf("请输入数组。\n"); 
	for(i=0;i<len;i++){
		scanf("%d",&a[i]);
	} 
	paixu(a[len],len);
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}

}

