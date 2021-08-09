#include <stdio.h>
int check(char c[][100],int *p)
{
	int ispat=1;
	int cnt=0;
	while(c[*p][cnt]!='\0'){
		if(*c[*p][cnt]!='P'||*c[*p][cnt]!="A"||*c[*p][cnt]!="T"||*c[*p][cnt]!=" "){
			ispat=0;
			printf("%c\n",c[*p][cnt]);
			break;
		}
		cnt++;
	}
	return(ispat);
}
int main()
{
	int i;
	scanf("%d",&i);
	char a[i][100];
	for(int j=0;j<i;j++){
		scanf("%s",a[j]);
	}
	for(int k=0;k<i;k++){
		int *q=&k;
		if(check(a,q)==0){
			printf("NO\n");
		}
		else
		printf("YES\n");
	}
}
