#include <stdio.h>
int sw(float a){
	int n=0;
	if (a>0&&a<=19){
		n=1;
	}else if(a>19&&a<=24){
		n=2;
	}else if(a>24&&a<=29){
		n=3;
	}else if(a>29&&a<=34){
		n=4;
	}else 
	{n=5;}
	return n;
}
int main(){
	int weight;float stature;char sex;
	scanf("%d %f %c",&weight,&stature,&sex);
	float bmi=1.0*weight/(stature*stature);
	if(sex=='F'||sex=='f'){
		switch(sw(bmi)){
			case 1:printf("����");printf("%.2f",bmi);break;
			case 2:printf("����");printf("%.2f",bmi);break;
			case 3:printf("����");printf("%.2f",bmi);break;
			case 4:printf("����");printf("%.2f",bmi);break;
			case 5:printf("�ǳ�����");printf("%.2f",bmi);break;
		}
	}
	else{
		switch(sw(bmi-1)){
			case 1:printf("����");printf("%.2f",bmi);break;
			case 2:printf("����");printf("%.2f",bmi);break;
			case 3:printf("����");printf("%.2f",bmi);break;
			case 4:printf("����");printf("%.2f",bmi);break;
			case 5:printf("�ǳ�����");printf("%.2f",bmi);break;
		}
	}
} 
