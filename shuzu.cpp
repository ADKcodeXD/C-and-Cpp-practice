#include <stdio.h>
int main()
{
	int n=0; 
	scanf("%d",&n);
	int name[n][10];int number[n][10];int point[n];
	for(int i=0;i<n;i++){
		scanf("%s %s %d",name[i],number[i],&point[i]);
	}
	int min=point[0],max=point[0];int x,y;
	for(int i=0;i<n;i++){
		if(point[i]<min){
			min=point[i];
			x=i;
		}
		if(point[i]>max){
			max=point[i];
			y=i;
		}
	}
	printf("%s %s\n",name[x],number[x]);
	printf("%s %s\n",name[y],number[y]);
}
