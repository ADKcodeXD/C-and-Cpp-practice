#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> //�������������ͷ�ļ�
#include <conio.h> //������밴��������ͷ�ļ���kbhit�� 
#define width 60// ��ͼ���
#define high 30// ��ͼ�߶� 
#define snakemax 30// �ߵ�������
//�����ʳ��  ���������� ������߿�
//��������
void drawmap();
void createfood();
void input();
void gotoxy(int x,int y);
int menu();
void speed();
int death();
void help();
int win();
void pause();
//ȫ�ֱ��� ������ʼ�� �ƶ�����ı�
int  key='w';//��ʼ�������� 
int change=0; //�жϷ����Ƿ�ı� //��������û�õ� 

// ��¼ʳ������Ľṹ�� 
struct{
	int x;
	int y;
}food; 

//��¼�ߵ����꼰��Ϣ�Ľṹ�� 
struct{
	int x[snakemax];
	int y[snakemax];
	int len;
	int speed; 
}snake;

int main ()// ������ʵ�� 
{
	//�趨���ڴ�С 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rc;
    rc.Left = 5;
    rc.Top = 5;
    rc.Right = width+50;
    rc.Bottom = high+8;
  
    SetConsoleWindowInfo(hOut, TRUE, &rc);
	int t;
	A:if(menu()){
		exit(0);
	}
	drawmap();
	while(1){
	input();
	speed();
	Sleep(snake.speed);//����Sleep������С�ߵ��ٶ�
	createfood();
	if(!death()){
		break;
	} 
	if(win()){
	system("cls");
	gotoxy(width/2,high/2);
    printf("��ϲ��Ӯ����Ϸ\n");
    printf("\t\t�밴1���¿�ʼ��Ϸ�����������˳���Ϸ");
    while(1){
	if(kbhit()){
    	fflush(stdin);
        t=getch();
    	if(t=='1'){
    		system("cls");
    		goto A;
    	}else 
    	break;
    }
    }
    gotoxy(0,high); 
    return;
	} 
    }
    system("cls");
    gotoxy(width/2,high/2);
    printf("game over\n");
    printf("\t\t�밴1���¿�ʼ��Ϸ�����������˳���Ϸ");
    while(1){
	if(kbhit()){
    	fflush(stdin);
        t=getch();
    	if(t=='1'){
    		system("cls");
    		goto A;
    	}else 
    	break;
    }
    }
	gotoxy(0,high);
	system("pause");
	return 0;
}

//ģ�鹦����ƣ�������ƣ� 

//��ʼ����ͼģ�� 
void drawmap(){
	//��Ϊ�������� һ���������ֽ�
	//��ʼ��ʳ��
	srand(time(NULL));
	while(1){
	food.x=rand()%(width-4)+2;
	food.y=rand()%(high-2)+1;
    if(food.x%2==0){
    	break;
      }
	}
	gotoxy(food.x,food.y);
    printf("��");
	//�߿����
	int i,k;
	for(i=0;i<=high;i++){
		gotoxy(0,i);
		printf("��");
		gotoxy(width,i);
		printf("��");
	} 
	for (k=0;k<=width;k+=2){
		gotoxy(k,0);
		printf("��");
		gotoxy(k,high);
		printf("��");
	}
	printf("\n");
	//��ʼ��С�ߵ�λ�� �ٶ� ����
	snake.len=3;
	snake.speed=500; 
	//��ʼ��ͷ����Ļ�м�
	snake.x[0]=width/2;
	snake.y[0]=high/2;
	gotoxy(snake.x[0],snake.y[0]);
	printf("��");
	//ʣ���ߵ�����
	for(i=1;i<snake.len;i++){
		snake.x[i]=snake.x[i-1]+2;
		snake.y[i]=snake.y[i-1];
		gotoxy(snake.x[i],snake.y[i]);
		printf("��");
	} 
} 
// ʳ��Ĳ���
void createfood(){
	//�����ж����Ƿ����ʳ��
	//��Ϊ��ͷ������� ����ռ�����ֽ� �������������ż���� 
	//�Ҳ���ˢ��������
	if(food.x==snake.x[0]&&food.y==snake.y[0]){
	while(1){
	int i;
	int flag=1;//��־�����㲻�������ϵı�־ 
	srand(time(NULL));//�����������
	food.x=rand()%(width-4)+2;
	food.y=rand()%(high-2)+1;
	for(i=0;i<snake.len;i++){
		if(snake.x[i]==food.x&&snake.y[i]==food.y){
			flag=0;
			break;//����forѭ�� ������������orֱ�ӽ���if�ж�������ѭ�� 
		}
	}
	if(flag=1&&food.x%2!=0){
		food.x++;
		break;
	}
	if(flag=1&&food.x%2==0){
		break;//������ѭ�� 
	}
  }
  gotoxy(food.x,food.y);
  printf("��");
  snake.len++;
 } 
}
// ���� �������� 
void input(){
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
		}else
		if(t==' '){
			pause();//���������ǿո�
		}
	//��key =t�����ȥ�����ݣ��趨ΪWASD�ֱ����������ҷ�����ƣ�
	}
	// �������� ����������Ч �Զ���key�ĳ�ʼֵ��ִ�� 
//	if(!change){
		gotoxy(snake.x[snake.len-1],snake.y[snake.len-1]);
		printf("  ");//����һ����� 
//	} 
	//ʣ�µ���ǰŲ��
	for (i=snake.len-1;i>0;i--){
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	} 
	//�ƶ�����Ĵ���
	switch(key){
		case 'w':
		case 'W':
			snake.y[0]--;
			break;
		case 's':
		case 'S':
			snake.y[0]++;
		    break;
		case 'a':
		case 'A':
			snake.x[0]-=2;
		    break;
		case 'd':
		case 'D':
			snake.x[0]+=2;
		    break;
	} 
    gotoxy(snake.x[0],snake.y[0]);
	printf("��");
	gotoxy(width+6,high/3);
	printf("���ĵ÷�ĿǰΪ%d",snake.len-3);
	gotoxy(width+6,high*2/3);
	printf("��ǰ�ٶ�Ϊ%d",500-snake.speed);
	gotoxy(width+6,high);
	printf("С��ʾ���Ե�Խ���ٶ�Խ��");
} 
//�����ж�
int death(){
	int flag=1;
	if(snake.x[0]==0||snake.x[0]==width-2||snake.y[0]==0||snake.y[0]==high-1){
		flag=0;//�ж���ͷ�Ƿ�ײǽ  -2����Ϊÿ��ͼ��ռ�����ֽ� 
	} 
	//�ж����Ƿ�ײ������
	int i;
	for (i=1;i<snake.len-1;i++){
		if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0]){
			flag=0;
		}
	}
	return flag;
}
//̰���ߵ��ٶ�����(���ų����������ٶȱ��)
//ÿ��һ��ʳ��ٶ�����20��������100
void speed(){
	if(snake.speed>=100){
	snake.speed=500-(snake.len-3)*20;
    }
}
//��ʼ�˵�
int menu(){
	int key2=' '; 
	gotoxy(0,high/2-8);
	printf("\t***************̰����ver1.0****************\n");
	printf("\t****************1.��ʼ��Ϸ*****************\n");
	printf("\t****************2.����*********************\n");
	printf("\t****************3.�˳���Ϸ*****************\n");
	//����һ����ѭ���������밴������ִ���κβ��� 
	while(1){
	if(_kbhit()) 
	{
	    fflush(stdin);
	    key2=_getch();
	    break;	    
	}
	}
	if(key2=='1'){
		system("cls");
		return 0;
	}else if(key2=='2'){
		system("cls");
		help();
		return 0;
	}else {
		system("cls");
		gotoxy(0,high/2-4);
		printf("��Ϸ����"); 
		return 1;
	}
  }
// �����˵�
void help(){
	gotoxy(0,high/2-4);
	printf("\t****************����Ϸ�淨�ܼ�*************\n");
	printf("\t*******WASD�ֱ����С�ߵ��������ҷ���********\n");
	printf("\t**********��Ϸ�п��԰��¿ո����ͣ***********\n");
	printf("\t***�����Ե�ʳ��ﵽһ������ʱ�򽫻�Ӯ����Ϸ**\n");
	printf("\t************�����������ʼ��Ϸ***************\n");
	system("pause");
	system("cls");
}
//��ͣϵͳ 
void pause()
{
    gotoxy(width+2,high/2);
    printf("������ͣ���ٴΰ���������ɼ�����Ϸ");
	while(1)
	{
		//����а��� ��ֱ������ѭ�� 
		if(kbhit()){
			fflush(stdin);
			gotoxy(width+2,high/2);
			printf("                                     ");//����ʾ����� 
			break; 
		}
	} 
} 
//ʤ��ϵͳ 
int win(){
	if(snake.len==snakemax){
		return 1;
	} 
	return 0;
}
//����win32  api ���ÿ���̨����λ��  ʹ���ܹ�������� �������괦��ӡ��� 
void gotoxy(int x,int y){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��þ�� 
	COORD coord;//����coord�ṹ�� 
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(handle,coord);
}



