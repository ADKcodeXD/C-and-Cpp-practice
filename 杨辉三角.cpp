#include<stdio.h>
int main()
{
    char a[3][80];
    for(int n=0;n<3;n++)
    gets(a[n]);
    int big=0,small=0;
	int num=0,space=0,other=0;
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<80;j++){
			if(a[i][j]>=65&&a[i][j]<=90){
				big++;
			}else if(a[i][j]>=97&&a[i][j]<=122){
				small++;
			}else if(a[i][j]>=48&&a[i][j]<=57){
				num++;
			}else if(a[i][j]==32){
				space++;
			}else
			other++;
		}
	}
	printf("�������д�д��ĸ%d����Сд��ĸ%d��������%d�����ո�%d���������ַ�%d��",big,small,space,num,other);
	return 0;
}
