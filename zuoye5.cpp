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
	printf("ѧ��ƽ���ַ���Ϊ%d\n",fangcha);
}
int s(int a,int b,int c,int d,int e,int i){
	int sum;
	sum=a+b+c+d+e;
	sum/=5;
	printf("��%d����ѧ����ƽ����Ϊ%d\n",i+1,sum);
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
		printf("�������%d��ѧ���ĳɼ�\n",i+1);
		scanf("%d",&one[i]);
		scanf("%d",&two[i]);
		scanf("%d",&three[i]);
		scanf("%d",&four[i]);
		scanf("%d",&five[i]);
	}
	printf("��һ�ſ�Ŀ��ƽ����Ϊ%d\n",q(one));
	printf("�ڶ��ſ�Ŀ��ƽ����Ϊ%d\n",q(two));
	printf("�����ſ�Ŀ��ƽ����Ϊ%d\n",q(three));
	printf("�����ſ�Ŀ��ƽ����Ϊ%d\n",q(four));
	printf("�����ſ�Ŀ��ƽ����Ϊ%d\n",q(five));
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
	printf("������ߵĿ�ĿΪ��%d�ſ�Ŀ���ǵ�%d��ѧ���������ģ���%d��",sub+1,num+1,t);
}
