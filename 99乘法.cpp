#include <stdio.h>
int main()
{
	int n;
	int cnt;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d*%d=%d",i,j,i*j);
			if(i*j<10){
				printf("   ");
			}else
			printf("  ");
		}
		printf("\n");
	}
} 
