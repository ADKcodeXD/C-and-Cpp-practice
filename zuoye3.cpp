#include <stdio.h>
int main()
{
	int i,g,n,b;
	for(i=1;i<=4;i++){
	for(g=1;g<=4-i;g++){
		printf(" ");
	}
	for(n=1;n<=(2*i-1);n++){
		printf("*");
	}
		printf("\n");
	}
	for(b=3;b>0;b--){
		for(i=1;i<=4-b;i++){
			printf(" ");
		}
		for(n=1;n<=(2*b-1);n++){
			printf("*");
		}
		printf("\n");
	}
}
