#include <stdio.h>
#include <windows.h>
int main() 
{
	int x=1,t=0,p;

	while(t<50){
	int sushu=1;
	for(p=2;p<x;p++)
	{
	if(x%p==0){
	sushu=0;
	break;}	
	}
	x++;
	if (sushu==1)
	{t++;
	printf("%d\n",x);}
	}
	
}
//�����ж�һ�����Ƿ�����
//����һ��p��ʹx%p==0�� 
//������һ��x��x������ÿ�ε����ж�һ�Σ� 
//�ǣ���������ǣ������
//Ȼ��ͨ��һ��ѭ����ѭ����ʮ�Σ�����һ��t����ʾ������ 
//�����ʮ�������� 
