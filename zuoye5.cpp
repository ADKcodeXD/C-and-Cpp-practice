#include <stdio.h>
int max(int a[],int *p){
	int i,max=a[0];
	for(i=0;i<10;i++){
		if(a[i]>max){
			max=a[i];
			*p=i; 
		}
	}
	return max;
}
void fangcha(int a[]){
	int i,sum=0,sum2=0,fangcha=0;
	for(i=0;i<10;i++){
		sum+=a[i];
		sum2+=a[i]*a[i];
	}
	fangcha=sum2/10-(sum/10)*(sum/10);
	printf("学生平均分方差为%d\n",fangcha);
}
int s(int a,int b,int c,int d,int e,int i){
	int sum;
	sum=a+b+c+d+e;
	sum/=5;
	printf("第%d个的学生的平均分为%d\n",i+1,sum);
	return sum;
}
int q(int a[]){
	int sum=0,i;
	for(i=0;i<10;i++){
		sum+=a[i];
	}
	sum/=10;
	return sum;
}
int main()
{
	int one[10],two[10],three[10],four[10],five[10];
	int i;int pingjun[10];
	for(i=0;i<10;i++){
		printf("请输入第%d个学生的成绩\n",i+1);
		scanf("%d",&one[i]);
		scanf("%d",&two[i]);
		scanf("%d",&three[i]);
		scanf("%d",&four[i]);
		scanf("%d",&five[i]);
	}
	printf("第一门科目的平均分为%d\n",q(one));
	printf("第二门科目的平均分为%d\n",q(two));
	printf("第三门科目的平均分为%d\n",q(three));
	printf("第四门科目的平均分为%d\n",q(four));
	printf("第五门科目的平均分为%d\n",q(five));
	for(i=0;i<10;i++){
		pingjun[i]=s(one[i],two[i],three[i],four[i],five[i],i);
	}
	fangcha(pingjun);
	int ban[5];int *p;int high[5];
	p=&ban[0];
	high[0]=max(one,p);
	high[1]=max(two,p+1);
	high[2]=max(three,p+2);
	high[3]=max(four,p+3);
	high[4]=max(five,p+4);
	int t=high[0];int num=ban[0],sub=0,j;
	for(j=0;j<5;j++){
		if(high[j]>t){
			t=high[j];
			num=ban[j];
			sub=j;
		}
	}
	printf("分数最高的科目为第%d门科目，是第%d个学生考出来的，是%d分",sub+1,num+1,t);
}
