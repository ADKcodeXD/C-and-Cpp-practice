#include<stdio.h>
#include <conio.h>
int key='w'; 
void main(){
	int i;int t;
	if(_kbhit())//����kbhit����ȡ���̰��������� 
	{
	    fflush(stdin);//��ʱ��ջ����� ���������һ���İ������գ����ٰ�����
	    t=_getch(); 
	    //�ж��Ƿ����෴�ļ� 
		if((t=='w'||t=='W')&&(key!='s'&&key!='S')){
			key=t;
		}else
		if((t=='s'||t=='S')&&(key!='w'&&key!='W')){
			key=t;
		}else
		if((t=='a'||t=='A')&&(key!='d'&&key!='D')){
			key=t;
		}else
		if((t=='d'||t=='D')&&(key!='a'&&key!='A')){
			key=t;
		}
//		if(t==' '){
//			pause(); //���������ǿո� 
//		}
		               //��key =t�����ȥ�����ݣ��趨ΪWASD�ֱ����������ҷ�����ƣ�
	}
} 
