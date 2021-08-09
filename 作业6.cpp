#include <iostream>
using namespace std;
class Employer{
	protected:
		int salary;
	public:
	    virtual int get_salary()=0;
};
class Director: public Employer{
	public:
		virtual int get_salary(){
			salary=6000;
			return salary;
		}
};
class Manager: public Employer{
	public:
		Manager(int a){hour=a;}
		virtual int get_salary(){
			salary=3000+50*hour;
			return salary;
		}
	private:
		int hour;
};
class Promotor: public Employer{
	public:
			Promotor(int a){dan=a;}
		virtual int get_salary(){
			salary=dan*100;
			return salary;
		}
	private:
		int dan;
};
int main(){
	Employer *p=new Director;
	Employer *q=new Manager(30);
	Employer *r=new Promotor(35);
	int a,b,c;
	a=p->get_salary();
	b=q->get_salary();
	c=r->get_salary();
	cout<< "�ܼࣺС�� ���¹��ʣ�" << a << endl;
	cout<< "����С�� ���¹��ʣ�" << b << endl;
	cout<< "רԱ��С�� ���¹��ʣ�" << c << endl;
	return 0;
}
