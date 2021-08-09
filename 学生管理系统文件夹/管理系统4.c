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
	printf("|**********      学生管理系统         ************|\n");
	printf("|**********  请选择下列功能           ************|\n");
	printf("|**********  1.录入学生信息于数据库   ************|\n"); 
	printf("|**********  2.从数据库中删除学生信息 ************|\n"); 
	printf("|**********  3.读取数据库学生信息     ************|\n"); 
	printf("|**********  4.覆盖保存学生信息       ************|\n"); 
	printf("|**********  5.修改学生信息           ************|\n"); 
	printf("|**********  6.排序并显示学生成绩     ************|\n"); 
	printf("|**********  7.查询并统计信息         ************|\n"); 
	printf("|**********  8.显示所有学生信息       ************|\n"); 
	printf("|**********  9.初始化当前学生信息     ************|\n"); 
	printf("|**********  0.退出系统               ************|\n"); 
	printf("|*************************************************|\n");
	printf("|-------------------------------------------------|\n");
}
void initstudent(stunode newnode){
	newnode->number=0;
	printf("初始化成功！\n");
	printf("当前内存中已无学生信息！\n");
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
				printf("录入失败！！\n");
				system("pause");
				system("cls");
				return;
			}
		A:printf("|----你要录入的学生的数量：");
		scanf("%d",&N);
		if(N>max
		) {
			printf("您输入的数量太大，请重新输入！\n");
			goto A; 
		}
		system("cls");
			for(i=1;i<=N;i++){
			B:printf("|----请输入第%d个学生的姓名：",i);
			scanf("%s",&temp1);
			for(j=0;j<stu->number+1;j++){
				if(!strcmp(temp1,stu->st[j].stname)){
					printf("内存中存在同名！\n");
					printf("请问是否确定输入？(Y\\N)\n");
					char c=_getch();
					if(c=='y'||c=='Y'){
						strcpy(stu->st[stu->number].stname,temp1);
					}else if(c=='n'||c=='N'){
						goto B;
					}else{
						printf("输入指令错误！\n");
						printf("默认执行替换\n");
						strcpy(stu->st[stu->number].stname,temp1);
					}
				}
			}
			strcpy(stu->st[stu->number].stname,temp1);
			printf("|----请输入第%d个学生的年龄：",i);
			scanf("%d",&stu->st[stu->number].age);
			printf("|----请输入第%d个学生的专业(计算机专业请输入CS)：",i);
			scanf("%s",&stu->st[stu->number].pro);
			C:printf("|----请输入第%d个学生的学号：",i);
			scanf("%s",&temp2);
			for(j=0;j<stu->number;j++){
				if(!strcmp(temp2,stu->st[j].number)){
					printf("内存中存在同学号！\n");
					printf("请重新输入当前数据！\n");
					goto C;
				}
			}
			strcpy(stu->st[stu->number].number,temp2);
			printf("|----请输入第%d个学生的年级(18级输入18)：",i);
			scanf("%d",&stu->st[stu->number].grade);
			printf("|----请输入第%d个学生的第一科成绩：",i);
			scanf("%d",&stu->st[stu->number].score1);
			printf("|----请输入第%d个学生的第二科成绩：",i);
			scanf("%d",&stu->st[stu->number].score2);
			printf("|----请输入第%d个学生的第三科成绩：",i);
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
		printf("|----录入成功！\n");
	}else{
		printf("已超出最大限制，拒绝录入！\n");
	}
	system("pause");
	system("cls");
}
void delstudent(stunode stu){
	int index=0;int flag=0;int i;
	char temp[20];
	if(stu->number==0){
		printf("当前内存内无学生信息！\n");
		system("pause");
		system("cls");
	}else{
		FILE *fp;
		fp=fopen(".\\database.txt","w");
		if(fp==NULL){
			printf("文件打开失败！\n");
			system("pause");
			system("cls");
			return ;
		}else{
			printf("请输入你要删除的学生的学号或姓名:");
			scanf("%s",&temp);
			for(i=0;i<stu->number;i++){
				if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
						index=i;
						flag=1;
						break;
					}
			}
			if(!flag){
				printf("未找到该学生！！！\n");
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
			printf("删除成功！\n");
			system("pause");
			system("cls");
		}
	}
}
void savestudent(stunode stu){
	int i;
	FILE *fp=fopen("./database.txt","w+");
	if(fp==NULL){
		printf("保存文件失败！！\n");
		system("pause");
		system("cls");
		return; 
	}
	if(stu->number!=0){
		for(i=0;i<stu->number;i++){
			fprintf(fp,"%s %s %s %d %d %d %d %.2f %d\n",stu->st[i].stname,stu->st[i].number,stu->st[i].pro,stu->st[i].grade,stu->st[i].score1,stu->st[i].score2,stu->st[i].score3,stu->st[i].average,stu->st[i].sum);
		}
	}else{
		printf("内存中没有数据！\n");
	}
	printf("保存成功！\n");
	rewind(fp);
	fclose(fp);
	system("pause");
	system("cls");
}
void changestudent(stunode stu){
	char temp[20],temp1[20],temp2[20];int index,i,j,flag; 
	if(stu->number==0){
		printf("当前内存内无学生信息！\n");
		system("pause");
		system("cls");
	}else{
		flag=0;
		printf("请输入你要修改的学生的信息的姓名或学号：");
		scanf("%s",&temp);
		for(i=0;i<stu->number;i++){
			if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
				index=i;
				flag=1;
				break;
			}
		}
		if(!flag){
			printf("未找到该学生！！！\n");
			system("pause");
			system("cls");
			return;
		}
		A:printf("|----请输入学生的姓名：");
		scanf("%s",&temp1);
		for(i=0;i<stu->number;i++){
			if(!strcmp(temp,stu->st[i].stname)){
				printf("内存中存在同名！\n");
				printf("请问是否确定输入？(Y\\N)\n");
				char c=_getch();
				if(c=='y'||c=='Y'){
					strcpy(stu->st[index].stname,temp1);
				}else if(c=='n'||c=='N'){
					goto A;
				}else{
					printf("输入指令错误！\n");
					printf("默认执行替换\n");
					strcpy(stu->st[index].stname,temp1);
				}
			}else{
				strcpy(stu->st[index].stname,temp1);
			}
		}
		printf("|----请输入学生的年龄：");
		scanf("%d",&stu->st[index].age);
		printf("|----请输入学生的专业(计算机专业请输入CS)：");
		scanf("%s",&stu->st[index].pro);
		B:printf("|----请输入学生的学号：");
		scanf("%s",&temp2);
		for(j=0;j<stu->number;j++){
			if(!strcmp(temp2,stu->st[j].number)){
				printf("内存中存在同学号！\n");
				printf("请重新输入当前数据！\n");
				goto B;
			}else{
				strcpy(stu->st[index].number,temp2);
				break;
			} 
		}
		printf("|----请输入学生的年级(18级输入18)：");
		scanf("%d",&stu->st[index].grade);
		printf("|----请输入学生的第一科成绩：");
		scanf("%d",&stu->st[index].score1);
		printf("|----请输入学生的第二科成绩：");
		scanf("%d",&stu->st[index].score2);
		printf("|----请输入学生的第三科成绩：");
		scanf("%d",&stu->st[index].score3);
		stu->st[index].average=(stu->st[index].score1+stu->st[index].score2+stu->st[index].score3)/3;
		stu->st[index].sum=(stu->st[index].score1+stu->st[index].score2+stu->st[index].score3);
		printf("修改成功！！！\n");
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
		printf("打开文件失败！！请检查路径下是否有该文件！没有的话可以执行一次保存后再次读入！\n");
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
	printf("读取文件完成！\n");
	system("pause");
	system("cls");
	return stu;
}
void searchstudent(stunode stu){
	char temp[20];int index,i,flag;
	if(stu->number==0){
		printf("当前内存内无学生信息！\n");
		system("pause");
		system("cls");
	}else{
		system("cls");
		printf("|----------------------------------------------------|\n");
		printf("|****************************************************|\n");
		printf("|****************************************************|\n");
		printf("|********        查询统计功能             ***********|\n");
		printf("|********   请选择下列功能                ***********|\n");
		printf("|********   1.查找单个学生的数据          ***********|\n");
		printf("|********   2.统计分数段人数并计算平均分  ***********|\n");
		printf("|********   3.显示科目平均分以及分数段    ***********|\n");
		printf("|********   4.查找对应分数的人数          ***********|\n");
		printf("|****************************************************|\n");
		printf("|****************************************************|\n");
		printf("|----------------------------------------------------|\n");
		char c=_getch();
		if(c=='1'){
				flag=0;
				printf("请输入你要查找的学生的信息的姓名或学号：");
				scanf("%s",&temp);
				for(i=0;i<stu->number;i++){
					if(!strcmp(temp,stu->st[i].stname)||!strcmp(temp,stu->st[i].number)){
						index=i;
						flag=1;
						break;
					}
				}
				if(!flag){
					printf("未找到该学生！！！\n");
					system("pause");
					system("cls");
					return;
				}
				printf("|-----------------------你要查找的学生%-11s信息如下---------------------|\n",temp);
				printf("|   姓名   | 学     号 | 专业 | 年级 | 成绩1 | 成绩2 | 成绩3 | 平均分  | 总分 |\n"); 
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
			printf("|-------根据统计，得到以下结果：\n");
			printf("|-------分数段统计\n");
			printf("总分分布在300~270的人数有：%d人\n",rank[0]);
			printf("总分分布在270~240的人数有：%d人\n",rank[1]);
			printf("总分分布在240~210的人数有：%d人\n",rank[2]);
			printf("总分分布在180~210的人数有：%d人\n",rank[3]);
			printf("总分分布在150~180的人数有：%d人\n",rank[4]);
			printf("总分分布在150以下的人数有：%d人\n",rank[5]);
			printf("|-------平均分统计\n");
			printf("本班总分数：%d\n",total);
			printf("本班平均分数：%.2f\n",((float)total/(stu->number)));
			printf("本班三科科目平均分数：%.2f\n",averagesum/(stu->number));
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
			printf("|-------根据统计，得到以下结果：\n");
			printf("本班成绩1的总分是%d\n本班成绩2的总分是%d\n本班成绩3的总分是%d\n",total1sum,total2sum,total3sum);
			printf("|-------平均分统计\n");
			printf("本班成绩1的平均分为:%.2f\n",(float)total1sum/(stu->number));
			printf("本班成绩2的平均分为:%.2f\n",(float)total2sum/(stu->number));
			printf("本班成绩3的平均分为:%.2f\n",(float)total3sum/(stu->number));
			printf("|------分数段统计\n");
			printf("90以上的人数：成绩1：%d人，成绩2：%d人，成绩3：%d人\n",rank1[0],rank2[0],rank3[0]);
			printf("80~90的人数：成绩1：%d人，成绩2：%d人，成绩3：%d人\n",rank1[1],rank2[1],rank3[1]);
			printf("70~80的人数：成绩1：%d人，成绩2：%d人，成绩3：%d人\n",rank1[2],rank2[2],rank3[2]);
			printf("60~70的人数：成绩1：%d人，成绩2：%d人，成绩3：%d人\n",rank1[3],rank2[3],rank3[3]);
			printf("60以下的人数：成绩1：%d人，成绩2：%d人，成绩3：%d人\n",rank1[4],rank2[4],rank3[4]);
			system("pause");
			system("cls");
		}else if(c=='4'){
			int x;int index[20]={0};int man=0;int i;//index记录序号，man记录该分数的人数 
			printf("请输入你要查找的分数：");
			scanf("%d",&x);
			for(i=0;i<stu->number;i++){
				if(stu->st[i].sum==x){
					index[man]=i;
					man++;
				}
			}
    		if(!man){
    			printf("未找到该分数的学生！");
    			system("pause");
				system("cls");
    		}else{
    				printf("|--------------------------找到%d名总分为%d分数的学生-------------------------|\n",man,x);
					printf("|   姓名   | 学     号 | 专业 | 年级 | 成绩1 | 成绩2 | 成绩3 | 平均分  | 总分 |\n");
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
			printf("输入错误！\n");
			system("pause");
			system("cls");
		} 
	}
}
void printstudent(stunode stu){
	int i,k;
	int cnt=0; 
	system("cls");
	printf("|--------------------------------数据打印如下---------------------------------|\n");
	printf("|   姓名   | 学     号 | 专业 | 年级 | 成绩1 | 成绩2 | 成绩3 | 平均分  | 总分 |\n"); 
	for(i=stu->number;i>0;i--){
		k=i-1;
		cnt++;
		printf("|%-10s|%-11s|  %-2s  |  %-2d  |  %-3d  |  %-3d  |  %-3d  |  %-.2f  |  %-3d |\n",stu->st[k].stname,stu->st[k].number,stu->st[k].pro,stu->st[k].grade,stu->st[k].score1,stu->st[k].score2,stu->st[k].score3,stu->st[k].average,stu->st[k].sum);
		if(cnt%20==0){
			cnt=0;
			printf("当前页面显示二十条结果，按任意键显示下一页\n");
			system("pause");
			system("cls");
		}
	}
	system("pause");
	system("cls");
}
void bubblestudent(stunode stu){
	FILE *fp1=fopen("./平均成绩排序数据.txt","w+");
	stunode averagestu= (stunode)malloc(sizeof(struct node));
	averagestu=stu;
	student *temp=(student *)malloc(sizeof(student));
	int i,j;
	//平均成绩 (最小在前面)
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
	printf("输出成功！\n");
	printf("按任意键打印当前排序结果。\n");
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
				printf("输入错误，请重新输入！！！\n");
				system("pause");
				system("cls");	
				break;
		}
	}
}
