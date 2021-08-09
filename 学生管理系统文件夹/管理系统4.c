#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct studentnode{
	char stname[20];
	char pro[20];
	int grade;
	int age;
	char number[20];
	int score1;
	int score2;
	int score3;
	double average;
	int sum;
}student;
typedef struct node *stunode;
struct node{
	student st[max];
	int number;
};
void menu(){
	printf("|-------------------------------------------------|\n");
	printf("|*************************************************|\n");
	printf("|**********      ѧ������ϵͳ         ************|\n");
	printf("|**********  ��ѡ�����й���           ************|\n");
	printf("|**********  1.¼��ѧ����Ϣ�����ݿ�   ************|\n"); 
	printf("|**********  2.�����ݿ���ɾ��ѧ����Ϣ ************|\n"); 
	printf("|**********  3.��ȡ���ݿ�ѧ����Ϣ     ************|\n"); 
	printf("|**********  4.���Ǳ���ѧ����Ϣ       ************|\n"); 
	printf("|**********  5.�޸�ѧ����Ϣ           ************|\n"); 
	printf("|**********  6.������ʾѧ���ɼ�     ************|\n"); 
	printf("|**********  7.��ѯ��ͳ����Ϣ         ************|\n"); 
	printf("|**********  8.��ʾ����ѧ����Ϣ       ************|\n"); 
	printf("|**********  9.��ʼ����ǰѧ����Ϣ     ************|\n"); 
	printf("|**********  0.�˳�ϵͳ               ************|\n"); 
	printf("|*************************************************|\n");
	printf("|-------------------------------------------------|\n");
}
void initstudent(stunode newnode){
	newnode->number=0;
	printf("��ʼ���ɹ���\n");
	printf("��ǰ�ڴ�������ѧ����Ϣ��\n");
	system("pause");
	system("cls");
}
void inputstudent(stunode stu){
	char temp1[20];char temp2[20];int j;
	if(stu->number<max){
		int N,i;
		printf("|-------------------------------------------------|\n");
		FILE *fp=fopen("./database.txt","a");
			if(fp==NULL){
				printf("¼��ʧ�ܣ���\n");
				system("pause");
				system("cls");
				return;
			}
		A:printf("|----��Ҫ¼���ѧ����������");
		scanf("%d",&N);
		if(N>max
		) {
			printf("�����������̫�����������룡\n");
			goto A; 
		}
		system("cls");
			for(i=1;i<=N;i++){
			B:printf("|----�������%d��ѧ����������",i);
			scanf("%s",&temp1);
			for(j=0;j<stu->number+1;j++){
				if(!strcmp(temp1,stu->st[j].stname)){
					printf("�ڴ��д���ͬ����\n");
					printf("�����Ƿ�ȷ�����룿(Y\\N)\n");
					char c=_getch();
					if(c=='y'||c=='Y'){
						strcpy(stu->st[stu->number].stname,temp1);
					}else if(c=='n'||c=='N'){
						goto B;
					}else{
						printf("����ָ�����\n");
						printf("Ĭ��ִ���滻\n");
						strcpy(stu->st[stu->number].stname,temp1);
					}
				}
			}
			strcpy(stu->st[stu->number].stname,temp1);
			printf("|----�������%d��ѧ�������䣺",i);
			scanf("%d",&stu->st[stu->number].age);
			printf("|----�������%d��ѧ����רҵ(�����רҵ������CS)��",i);
			scanf("%s",&stu->st[stu->number].pro);
			C:printf("|----�������%d��ѧ����ѧ�ţ�",i);
			scanf("%s",&temp2);
			for(j=0;j<stu->number;j++){
				if(!strcmp(temp2,stu->st[j].number)){
					printf("�ڴ��д���ͬѧ�ţ�\n");
					printf("���������뵱ǰ���ݣ�\n");
					goto C;
				}
			}
			strcpy(stu->st[stu->number].number,temp2);
			printf("|----�������%d��ѧ�����꼶(18������18)��",i);
			scanf("%d",&stu->st[stu->number].grade);
			printf("|----�������%d��ѧ���ĵ�һ�Ƴɼ���",i);
			scanf("%d",&stu->st[stu->number].score1);
			printf("|----�������%d��ѧ���ĵڶ��Ƴɼ���",i);
			scanf("%d",&stu->st[stu->number].score2);
			printf("|----�������%d��ѧ���ĵ����Ƴɼ���",i);
			scanf("%d",&stu->st[stu->number].score3);
			stu->st[stu->number].average=(float)(stu->st[stu->number].score1+stu->st[stu->number].score2+stu->st[stu->number].score3)/3;
			stu->st[stu->number].sum=(stu->st[stu->number].score1+stu->st[stu->number].score2+stu->st[stu->number].score3);
			fprintf(fp,"%s %s %s %d %d %d %d %.2f %d\n",stu->st[stu->number].stname,stu->st[stu->number].number,stu->st[stu->number].pro,\
			stu->st[stu->number].grade,stu->st[stu->number].score1,stu->st[stu->number].score2,\
			stu->st[stu->number].score3,stu->st[stu->number].average,stu->st[stu->number].sum);
			stu->number+=1;
			system("pause");
			system("cls");
			}
		fclose(fp);
		printf("|----¼��ɹ���\n");
	}else{
		printf("�ѳ���������ƣ��ܾ�¼�룡\n");
	}
	system("pause");
	system("cls");
}
void delstudent(stunode stu){
	int index=0;int flag=0;int i;
	char temp[20];
	if(stu->number==0){
		printf("��ǰ�ڴ�����ѧ����Ϣ��\n");
		system("pause");
		system("cls");
	}else{
		FILE *fp;
		fp=fopen(".\\database.txt","w");
		if(fp==NULL){
			printf("�ļ���ʧ�ܣ�\n");
			system("pause");
			system("cls");
			return ;
		}else{
			printf("��������Ҫɾ����ѧ����ѧ�Ż�����:");
			scanf("%s",&temp);
			for(i=0;i<stu->number;i++){
				if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
						index=i;
						flag=1;
						break;
					}
			}
			if(!flag){
				printf("δ�ҵ���ѧ��������\n");
				system("pause");
				system("cls");
				return;
			}
			for(i=index;i<stu->number-1;i++){
				stu->st[i]=stu->st[i+1];
			}
			stu->number--;
			for(i=0;i<stu->number;i++){
				fprintf(fp,"%s %s %s %d %d %d %d %.2f %d\n",stu->st[i].stname,stu->st[i].number,stu->st[i].pro,stu->st[i].grade,stu->st[i].score1,stu->st[i].score2,stu->st[i].score3,stu->st[i].average,stu->st[i].sum);
			}
			fclose(fp);
			printf("ɾ���ɹ���\n");
			system("pause");
			system("cls");
		}
	}
}
void savestudent(stunode stu){
	int i;
	FILE *fp=fopen("./database.txt","w+");
	if(fp==NULL){
		printf("�����ļ�ʧ�ܣ���\n");
		system("pause");
		system("cls");
		return; 
	}
	if(stu->number!=0){
		for(i=0;i<stu->number;i++){
			fprintf(fp,"%s %s %s %d %d %d %d %.2f %d\n",stu->st[i].stname,stu->st[i].number,stu->st[i].pro,stu->st[i].grade,stu->st[i].score1,stu->st[i].score2,stu->st[i].score3,stu->st[i].average,stu->st[i].sum);
		}
	}else{
		printf("�ڴ���û�����ݣ�\n");
	}
	printf("����ɹ���\n");
	rewind(fp);
	fclose(fp);
	system("pause");
	system("cls");
}
void changestudent(stunode stu){
	char temp[20],temp1[20],temp2[20];int index,i,j,flag; 
	if(stu->number==0){
		printf("��ǰ�ڴ�����ѧ����Ϣ��\n");
		system("pause");
		system("cls");
	}else{
		flag=0;
		printf("��������Ҫ�޸ĵ�ѧ������Ϣ��������ѧ�ţ�");
		scanf("%s",&temp);
		for(i=0;i<stu->number;i++){
			if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
				index=i;
				flag=1;
				break;
			}
		}
		if(!flag){
			printf("δ�ҵ���ѧ��������\n");
			system("pause");
			system("cls");
			return;
		}
		A:printf("|----������ѧ����������");
		scanf("%s",&temp1);
		for(i=0;i<stu->number;i++){
			if(!strcmp(temp,stu->st[i].stname)){
				printf("�ڴ��д���ͬ����\n");
				printf("�����Ƿ�ȷ�����룿(Y\\N)\n");
				char c=_getch();
				if(c=='y'||c=='Y'){
					strcpy(stu->st[index].stname,temp1);
				}else if(c=='n'||c=='N'){
					goto A;
				}else{
					printf("����ָ�����\n");
					printf("Ĭ��ִ���滻\n");
					strcpy(stu->st[index].stname,temp1);
				}
			}else{
				strcpy(stu->st[index].stname,temp1);
			}
		}
		printf("|----������ѧ�������䣺");
		scanf("%d",&stu->st[index].age);
		printf("|----������ѧ����רҵ(�����רҵ������CS)��");
		scanf("%s",&stu->st[index].pro);
		B:printf("|----������ѧ����ѧ�ţ�");
		scanf("%s",&temp2);
		for(j=0;j<stu->number;j++){
			if(!strcmp(temp2,stu->st[j].number)){
				printf("�ڴ��д���ͬѧ�ţ�\n");
				printf("���������뵱ǰ���ݣ�\n");
				goto B;
			}else{
				strcpy(stu->st[index].number,temp2);
				break;
			} 
		}
		printf("|----������ѧ�����꼶(18������18)��");
		scanf("%d",&stu->st[index].grade);
		printf("|----������ѧ���ĵ�һ�Ƴɼ���");
		scanf("%d",&stu->st[index].score1);
		printf("|----������ѧ���ĵڶ��Ƴɼ���");
		scanf("%d",&stu->st[index].score2);
		printf("|----������ѧ���ĵ����Ƴɼ���");
		scanf("%d",&stu->st[index].score3);
		stu->st[index].average=(stu->st[index].score1+stu->st[index].score2+stu->st[index].score3)/3;
		stu->st[index].sum=(stu->st[index].score1+stu->st[index].score2+stu->st[index].score3);
		printf("�޸ĳɹ�������\n");
		system("pause");
		system("cls");
	}
}
stunode readstudent(){
	stunode stu=(stunode)malloc(sizeof(struct node));
	stu->number=0;
	int i=0;
	FILE *fp=fopen("./database.txt","r");
	if(fp==NULL){
		printf("���ļ�ʧ�ܣ�������·�����Ƿ��и��ļ���û�еĻ�����ִ��һ�α�����ٴζ��룡\n");
		system("pause");
		system("cls");
		return NULL; 
	}
	while(fscanf(fp,"%s %s %s %d %d %d %d %lf %d\n",&stu->st[i].stname,&stu->st[i].number,&stu->st[i].pro,&stu->st[i].grade,&stu->st[i].score1,&stu->st[i].score2,&stu->st[i].score3,&stu->st[i].average,&stu->st[i].sum)!=EOF){
		i++;
		stu->number++;
	}
	rewind(fp);
	fclose(fp);
	printf("��ȡ�ļ���ɣ�\n");
	system("pause");
	system("cls");
	return stu;
}
void searchstudent(stunode stu){
	char temp[20];int index,i,flag;
	if(stu->number==0){
		printf("��ǰ�ڴ�����ѧ����Ϣ��\n");
		system("pause");
		system("cls");
	}else{
		system("cls");
		printf("|----------------------------------------------------|\n");
		printf("|****************************************************|\n");
		printf("|****************************************************|\n");
		printf("|********        ��ѯͳ�ƹ���             ***********|\n");
		printf("|********   ��ѡ�����й���                ***********|\n");
		printf("|********   1.���ҵ���ѧ��������          ***********|\n");
		printf("|********   2.ͳ�Ʒ���������������ƽ����  ***********|\n");
		printf("|********   3.��ʾ��Ŀƽ�����Լ�������    ***********|\n");
		printf("|********   4.���Ҷ�Ӧ����������          ***********|\n");
		printf("|****************************************************|\n");
		printf("|****************************************************|\n");
		printf("|----------------------------------------------------|\n");
		char c=_getch();
		if(c=='1'){
				flag=0;
				printf("��������Ҫ���ҵ�ѧ������Ϣ��������ѧ�ţ�");
				scanf("%s",&temp);
				for(i=0;i<stu->number;i++){
					if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
						index=i;
						flag=1;
						break;
					}
				}
				if(!flag){
					printf("δ�ҵ���ѧ��������\n");
					system("pause");
					system("cls");
					return;
				}
				printf("|-----------------------��Ҫ���ҵ�ѧ��%-11s��Ϣ����---------------------|\n",temp);
				printf("|   ����   | ѧ     �� | רҵ | �꼶 | �ɼ�1 | �ɼ�2 | �ɼ�3 | ƽ����  | �ܷ� |\n"); 
				printf("|%-10s|%-11s|  %-2s  |  %-2d  |  %-3d  |  %-3d  |  %-3d  |  %-.2f  |  %-3d |\n",stu->st[index].stname,stu->st[index].number,stu->st[index].pro,stu->st[index].grade,stu->st[index].score1,stu->st[index].score2,stu->st[index].score3,stu->st[index].average,stu->st[index].sum);
				system("pause");
				system("cls");
		} else if (c=='2'){
				int rank[6]={0};//300~270 1 270~240 2 240~210 3 210 ~180 4 180 ~150 5 <150 6
				int total=0;float averagesum=0;
				for (i=0;i<stu->number;i++){
					if(stu->st[i].sum>=270){
						rank[0]++;
					}else if(stu->st[i].sum>=240 && stu->st[i].sum<270){
						rank[1]++;
					}else if(stu->st[i].sum>=210 && stu->st[i].sum<240){
						rank[2]++;
					}else if(stu->st[i].sum>=180 && stu->st[i].sum<210){
						rank[3]++;
					}else if(stu->st[i].sum>=150 && stu->st[i].sum<180){
						rank[4]++;
					}else if(stu->st[i].sum<150){
						rank[5]++;
					}
					total+=stu->st[i].sum;
					averagesum+=stu->st[i].average;
				}
			printf("|-------����ͳ�ƣ��õ����½����\n");
			printf("|-------������ͳ��\n");
			printf("�ֲַܷ���300~270�������У�%d��\n",rank[0]);
			printf("�ֲַܷ���270~240�������У�%d��\n",rank[1]);
			printf("�ֲַܷ���240~210�������У�%d��\n",rank[2]);
			printf("�ֲַܷ���180~210�������У�%d��\n",rank[3]);
			printf("�ֲַܷ���150~180�������У�%d��\n",rank[4]);
			printf("�ֲַܷ���150���µ������У�%d��\n",rank[5]);
			printf("|-------ƽ����ͳ��\n");
			printf("�����ܷ�����%d\n",total);
			printf("����ƽ��������%.2f\n",((float)total/(stu->number)));
			printf("�������ƿ�Ŀƽ��������%.2f\n",averagesum/(stu->number));
			system("pause");
			system("cls");
		}else if(c=='3'){
			int rank1[5]={0},rank2[5]={0},rank3[5]={0};//90~100 0 80~90 1 70~80 2 60~70 3 <60 4 
			int total1sum=0,total2sum=0,total3sum=0;
			for(i=0;i<stu->number;i++){
				if(stu->st[i].score1>=90){
						rank1[0]++;
					}else if(stu->st[i].score1>=80 && stu->st[i].score1<90){
						rank1[1]++;
					}else if(stu->st[i].score1>=70 && stu->st[i].score1<80){
						rank1[2]++;
					}else if(stu->st[i].score1>=60 && stu->st[i].score1<70){
						rank1[3]++;
					}else if(stu->st[i].score1<60){
						rank1[4]++;
					}
				if(stu->st[i].score2>=90){
						rank2[0]++;
					}else if(stu->st[i].score2>=80 && stu->st[i].score2<90){
						rank2[1]++;
					}else if(stu->st[i].score2>=70 && stu->st[i].score2<80){
						rank2[2]++;
					}else if(stu->st[i].score2>=60 && stu->st[i].score2<70){
						rank2[3]++;
					}else if(stu->st[i].score2<60){
						rank2[4]++;
					}
				if(stu->st[i].score3>=90){
						rank3[0]++;
					}else if(stu->st[i].score3>=80 && stu->st[i].score3<90){
						rank3[1]++;
					}else if(stu->st[i].score3>=70 && stu->st[i].score3<80){
						rank3[2]++;
					}else if(stu->st[i].score3>=60 && stu->st[i].score3<70){
						rank3[3]++;
					}else if(stu->st[i].score3<60){
						rank3[4]++;
					}
				total1sum+=stu->st[i].score1;
				total2sum+=stu->st[i].score2;
				total3sum+=stu->st[i].score3;
			}
			printf("|-------����ͳ�ƣ��õ����½����\n");
			printf("����ɼ�1���ܷ���%d\n����ɼ�2���ܷ���%d\n����ɼ�3���ܷ���%d\n",total1sum,total2sum,total3sum);
			printf("|-------ƽ����ͳ��\n");
			printf("����ɼ�1��ƽ����Ϊ:%.2f\n",(float)total1sum/(stu->number));
			printf("����ɼ�2��ƽ����Ϊ:%.2f\n",(float)total2sum/(stu->number));
			printf("����ɼ�3��ƽ����Ϊ:%.2f\n",(float)total3sum/(stu->number));
			printf("|------������ͳ��\n");
			printf("90���ϵ��������ɼ�1��%d�ˣ��ɼ�2��%d�ˣ��ɼ�3��%d��\n",rank1[0],rank2[0],rank3[0]);
			printf("80~90���������ɼ�1��%d�ˣ��ɼ�2��%d�ˣ��ɼ�3��%d��\n",rank1[1],rank2[1],rank3[1]);
			printf("70~80���������ɼ�1��%d�ˣ��ɼ�2��%d�ˣ��ɼ�3��%d��\n",rank1[2],rank2[2],rank3[2]);
			printf("60~70���������ɼ�1��%d�ˣ��ɼ�2��%d�ˣ��ɼ�3��%d��\n",rank1[3],rank2[3],rank3[3]);
			printf("60���µ��������ɼ�1��%d�ˣ��ɼ�2��%d�ˣ��ɼ�3��%d��\n",rank1[4],rank2[4],rank3[4]);
			system("pause");
			system("cls");
		}else if(c=='4'){
			int x;int index[20]={0};int man=0;int i;//index��¼��ţ�man��¼�÷��������� 
			printf("��������Ҫ���ҵķ�����");
			scanf("%d",&x);
			for(i=0;i<stu->number;i++){
				if(stu->st[i].sum==x){
					index[man]=i;
					man++;
				}
			}
    		if(!man){
    			printf("δ�ҵ��÷�����ѧ����");
    			system("pause");
				system("cls");
    		}else{
    				printf("|--------------------------�ҵ�%d���ܷ�Ϊ%d������ѧ��-------------------------|\n",man,x);
					printf("|   ����   | ѧ     �� | רҵ | �꼶 | �ɼ�1 | �ɼ�2 | �ɼ�3 | ƽ����  | �ܷ� |\n");
    			for(i=0;i<man;i++){
    				
					printf("|%-10s|%-11s|  %-2s  |  %-2d  |  %-3d  |  %-3d  |  %-3d  |  %-.2f  |  %-3d |\n",\
					stu->st[index[i]].stname,stu->st[index[i]].number,stu->st[index[i]].pro,stu->st[index[i]].grade,stu->st[index[i]].score1,\
					stu->st[index[i]].score2,stu->st[index[i]].score3,stu->st[index[i]].average,stu->st[index[i]].sum);
    			}
    		system("pause");
			system("cls");
    		}
		} 
		else{
			printf("�������\n");
			system("pause");
			system("cls");
		} 
	}
}
void printstudent(stunode stu){
	int i,k;
	int cnt=0; 
	system("cls");
	printf("|--------------------------------���ݴ�ӡ����---------------------------------|\n");
	printf("|   ����   | ѧ     �� | רҵ | �꼶 | �ɼ�1 | �ɼ�2 | �ɼ�3 | ƽ����  | �ܷ� |\n"); 
	for(i=stu->number;i>0;i--){
		k=i-1;
		cnt++;
		printf("|%-10s|%-11s|  %-2s  |  %-2d  |  %-3d  |  %-3d  |  %-3d  |  %-.2f  |  %-3d |\n",stu->st[k].stname,stu->st[k].number,stu->st[k].pro,stu->st[k].grade,stu->st[k].score1,stu->st[k].score2,stu->st[k].score3,stu->st[k].average,stu->st[k].sum);
		if(cnt%20==0){
			cnt=0;
			printf("��ǰҳ����ʾ��ʮ����������������ʾ��һҳ\n");
			system("pause");
			system("cls");
		}
	}
	system("pause");
	system("cls");
}
void bubblestudent(stunode stu){
	FILE *fp1=fopen("./ƽ���ɼ���������.txt","w+");
	stunode averagestu= (stunode)malloc(sizeof(struct node));
	averagestu=stu;
	student *temp=(student *)malloc(sizeof(student));
	int i,j;
	//ƽ���ɼ� (��С��ǰ��)
	for(i=0;i<averagestu->number-1;i++){
		for(j=0;j<averagestu->number-1-i;j++){
			if(averagestu->st[j].average>averagestu->st[j+1].average){
				*temp=averagestu->st[j];
				averagestu->st[j]=averagestu->st[j+1];
				averagestu->st[j+1]=*temp;
			}
		}
	}
	for(i=0;i<averagestu->number;i++){
		fprintf(fp1,"%s %s %s %d %d %d %d %.2f %d\n",averagestu->st[i].stname,averagestu->st[i].number,averagestu->st[i].pro,averagestu->st[i].grade,\
		averagestu->st[i].score1,averagestu->st[i].score2,averagestu->st[i].score3,averagestu->st[i].average,averagestu->st[i].sum);
	}
	fclose(fp1);
	printf("����ɹ���\n");
	printf("���������ӡ��ǰ��������\n");
	system("pause");
	system("cls");
	printstudent(averagestu);
}
void main(){
	stunode stu=(stunode)malloc(sizeof(struct node));
	stu->number=0;
	stunode stutemp;
	FILE *fp;
	int i;
	if(!(fp=fopen(".\\database.txt","r"))){
		fp=fopen(".\\database.txt","w");
		fclose(fp);
		fp=fopen(".\\database.txt","r");
	}
	while(fscanf(fp,"%s %s %s %d %d %d %d %lf %d\n",&stu->st[i].stname,&stu->st[i].number,&stu->st[i].pro,&stu->st[i].grade,&stu->st[i].score1,&stu->st[i].score2,&stu->st[i].score3,&stu->st[i].average,&stu->st[i].sum)!=EOF){
		i++;
		stu->number++;
	}
	rewind(fp);
	fclose(fp);
	while(1){
		char a;
		menu();
		a=_getch();
		switch(a){
			case '1':inputstudent(stu);break;
			case '2':delstudent(stu);break;
			case '3':stutemp=readstudent();
			if(!stutemp){
				break;
			}else{
				stu=stutemp;
				break;
			}
			case '4':savestudent(stu);break;
			case '5':changestudent(stu);break;
			case '6':bubblestudent(stu);break;
			case '7':searchstudent(stu);break;
			case '8':printstudent(stu);break;
			case '9':initstudent(stu);break;
			case '0':return;break;
			default:
				printf("����������������룡����\n");
				system("pause");
				system("cls");	
				break;
		}
	}
}
