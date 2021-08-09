#include <stdio.h>
#include <string.h>
#define N 3
void sort(char *a[],int n)
{
	int i,j,index,*temp;
	for(i=0;i<N;i++)
	{
		for(j=i;j<N;j++){
			if(strcmp(a[i],a[j])>1){
				index=j;
			}
		}
		temp=a[i];
		a[i]=a[index];
		a[index]=temp;
	}
}
void main ()
{
	char *a[N]={"Csads","Bseqwe","Wsdahd"};int i;
    sort(a,N);
	for(i=0;i<N;i++)
	printf("%s\n",a[i]);
} 
